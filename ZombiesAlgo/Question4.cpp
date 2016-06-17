#include "stdafx.h"
#include "Question4.h"

void Question4::proceed(){
	ifstream file = Utils::chooseFile();

	vector<int> list = Utils::parseFileIntoVector(file);

	int nbShooters = list.at(0);
	list.erase(list.begin());

	int nbTowers = list.at(0);
	list.erase(list.begin());

	map<int, pair<double, int>> map = Utils::parseVectorIntoMapWithMeteoAndKeepEstimation(list);

	int maxPosition;
	int distance = chooseDistance();
	vector<int> takenPositions;

	for (int i = 1; i <= nbShooters; ++i){
		maxPosition = getMaxInCorrectDistanceAndApplyVariation(map, distance, takenPositions);
		takenPositions.push_back(maxPosition);
		cout << endl;
	}
	cout << endl;

	for (auto it = takenPositions.begin(); it != takenPositions.end(); ++it){

	}
}

int Question4::chooseDistance(){
	int distance;
	do {
		cout << "Choose a distance between 0 and 10 : ";
		cin >> distance;
	} while (distance < 0 || distance > 10);

	return distance;
}

int Question4::getMaxInCorrectDistanceAndApplyVariation(map<int, pair<double, int>> map, int minDistance, vector<int> takenPositions){
	pair<int, double> maxPair = pair<int, double>(map.begin()->first, map.begin()->second.first * ((100 + map.begin()->second.second) / 100));
	int position;
	double variation, efficiency;

	for (auto it = map.begin(); it != map.end(); ++it){
		position = it->first;
		pair<int, double> estimationAndVariation = it->second;
		variation = (100 + estimationAndVariation.second) / 100;
		efficiency = estimationAndVariation.first * variation;

		if (isDistanceOk(position, minDistance, takenPositions)){
			maxPair = efficiency > maxPair.second ? pair<int, double>(position, efficiency) : maxPair;
		}
	}
	cout << endl << "Shooter at " << maxPair.first << " : " << maxPair.second << " (" << map[maxPair.first].second << "%)" << endl;
	applyVariation(map, maxPair.first);

	return maxPair.first;
}

void Question4::updateTower(map<int, pair<double, int>> myMap, map<int, pair<double, int>>::iterator& it){
	int position;
	double currentVariation, improvementVariation;
	double estimation, oldEfficiency, variation;
	pair<double, int> efficiencyAndVariation;

	position = it->first;
	estimation = it->second.first;
	currentVariation = it->second.second;
	oldEfficiency = estimation * ((100 + currentVariation) / 100);

	improvementVariation = Utils::getImprovementVariation();
	variation = (currentVariation + improvementVariation + 100) / 100;

	myMap[position] = pair<double, int>(estimation, currentVariation + improvementVariation);
	cout << "Tower at " << position << " is now " << estimation * variation << " (was " << oldEfficiency << ")" << endl;
}

void Question4::applyVariation(map<int, pair<double, int>> map, double maxPosition){
	if (map[maxPosition].second < 0){
		auto it = map.find(maxPosition);

		updateTower(map, next(it, -1));
		updateTower(map, next(it, 1));
	}
}

bool Question4::isDistanceOk(int position, int minDistance, vector<int> takenPositions){
	for (auto takenPositionsIt = takenPositions.begin(); takenPositionsIt != takenPositions.end(); ++takenPositionsIt){
		if (position <= *takenPositionsIt && *takenPositionsIt - position < minDistance)
			return false;
		else if (position >= *takenPositionsIt && position - *takenPositionsIt < minDistance)
			return false;
	}
	return true;
}