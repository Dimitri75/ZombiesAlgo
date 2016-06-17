#include "stdafx.h"
#include "Question3.h"

void Question3::proceed(){
	ifstream file = Utils::chooseFile();

	vector<int> list = Utils::parseFileIntoVector(file);

	int nbShooters = list.at(0);
	list.erase(list.begin());

	int nbTowers = list.at(0);
	list.erase(list.begin());

	map<int, pair<double, int>> map = Utils::parseVectorIntoMapWithMeteo(list);

	int maxPosition;
	double efficiency;
	int distance = chooseDistance();
	vector<int> takenPositions;

	for (int i = 1; i <= nbShooters; ++i){
		maxPosition = getMaxInCorrectDistanceAndApplyVariation(map, distance, takenPositions);
		takenPositions.push_back(maxPosition);
		cout << endl;
	}
}

int Question3::chooseDistance(){
	int distance;
	do {
		cout << "Choose a distance between 0 and 10 : ";
		cin >> distance;
	} while (distance < 0 || distance > 10);

	return distance;
}

int Question3::getMaxInCorrectDistanceAndApplyVariation(map<int, pair<double, int>> map, int minDistance, vector<int> takenPositions){
	int maxPosition = map.begin()->first, position;

	for (auto it = map.begin(); it != map.end(); ++it){
		position = it->first;
		pair<double, int> efficiencyAndVariation = it->second;

		if (isDistanceOk(position, minDistance, takenPositions))
			maxPosition = efficiencyAndVariation.first > map[maxPosition].first ? position : maxPosition;
	}
	cout << endl << "Shooter at " << maxPosition << " : " << map[maxPosition].first << " (" << map[maxPosition].second << "%)" << endl;
	applyVariation(map, maxPosition);

	return maxPosition;
}

void Question3::updateTower(map<int, pair<double, int>> myMap, map<int, pair<double, int>>::iterator& it){
	int position;
	double currentVariation, improvementVariation;
	double efficiency, variation;
	pair<double, int> efficiencyAndVariation;

	position = it->first;
	efficiency = it->second.first;
	currentVariation = it->second.second;

	improvementVariation = Utils::getImprovementVariation();
	variation = (currentVariation + improvementVariation + 100) / 100;

	myMap[position] = pair<double, int>(efficiency * variation, currentVariation + improvementVariation);
	cout << "Tower at " << position << " is now " << efficiency * variation << " (was " << efficiency << ")" << endl;
}

void Question3::applyVariation(map<int, pair<double, int>> map, double maxPosition){
	if (map[maxPosition].second < 0){
		auto it = map.find(maxPosition);

		updateTower(map, next(it, -1));
		updateTower(map, next(it, 1));
	}
}

bool Question3::isDistanceOk(int position, int minDistance, vector<int> takenPositions){
	for (auto takenPositionsIt = takenPositions.begin(); takenPositionsIt != takenPositions.end(); ++takenPositionsIt){
		if (position <= *takenPositionsIt && *takenPositionsIt - position < minDistance)
			return false;
		else if (position >= *takenPositionsIt && position - *takenPositionsIt < minDistance)
			return false;
	}
	return true;
}
