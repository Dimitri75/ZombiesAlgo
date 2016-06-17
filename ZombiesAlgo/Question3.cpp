#include "stdafx.h"
#include "Question3.h"


Question3::Question3()
{
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
	vector<int> distances;

	for (int i = 1; i <= nbShooters; ++i){
		maxPosition = getMaxInCorrectDistanceAndApplyVariation(map, distance, distances);
		map.erase(maxPosition);
		cout << endl;
	}
}


Question3::~Question3()
{
}

int Question3::chooseDistance(){
	int distance;
	do {
		cout << "Choose a distance between 0 and 10 : ";
		cin >> distance;
	} while (distance < 0 || distance > 10);

	return distance;
}

int Question3::getMaxInCorrectDistanceAndApplyVariation(map<int, pair<double, int>> map, int minDistance, vector<int> distances){
	int maxPosition, position;

	for (auto it = map.begin(); it != map.end(); ++it){
		position = it->first;
		pair<double, int> efficiencyAndVariation = it->second;

		if (isDistanceOk(position, minDistance, distances))
			maxPosition = efficiencyAndVariation.first > map[maxPosition].first ? position : maxPosition;
	}
	distances.push_back(maxPosition);
	cout << "Shooter at " << maxPosition << " (" << map[maxPosition].first << ")" << endl;
	applyVariation(map, maxPosition);

	return maxPosition;
}

void updateTower(map<int, pair<double, int>> myMap, map<int, pair<double, int>>::iterator& it){
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
		cout << endl;
	}
}

bool Question3::isDistanceOk(int position, int minDistance, vector<int> distances){
	for (auto distanceIt = distances.begin(); distanceIt != distances.end(); ++distanceIt){
		if (position <= *distanceIt && *distanceIt - position < minDistance)
			return false;
		else if (position > *distanceIt && position - *distanceIt < minDistance)
			return false;
	}
	return true;
}
