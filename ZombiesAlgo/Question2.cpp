#include "stdafx.h"
#include "Question2.h"

void Question2::proceed(){
	ifstream file = Utils::chooseFile();

	vector<int> list = Utils::parseFileIntoVector(file);

	int nbShooters = list.at(0);
	list.erase(list.begin());

	int nbTowers = list.at(0);
	list.erase(list.begin());

	map<int, int> map = Utils::parseVectorIntoMap(list);

	int distance = chooseDistance();

	int maxPosition;
	int efficiency;
	vector<int> distances;
	for (int i = 1; i <= nbShooters; ++i){
		maxPosition = getMaxInCorrectDistance(map, distance, distances);
		efficiency = map[maxPosition];
		cout << "Shooter " << i << " at " << maxPosition << " (" << efficiency << ")" << endl;
		distances.push_back(maxPosition);
	}
}

int Question2::chooseDistance(){
	int distance;
	do {
		cout << "Choose a distance between 0 and 10 : ";
		cin >> distance;
	} while (distance < 0 || distance > 10);

	return distance;	
}

int Question2::getMaxInCorrectDistance(map<int, int> map, int minDistance, vector<int> distances){
	int maxPosition = map.begin()->first, position, efficiency;

	for (auto it = map.begin(); it != map.end(); ++it){
		position = it->first;
		efficiency = it->second;

		if (isDistanceOk(position, minDistance, distances))
			maxPosition = efficiency > map[maxPosition] ? position : maxPosition;
	}

	return maxPosition;
}

bool Question2::isDistanceOk(int position, int minDistance, vector<int> distances){
	for (auto distanceIt = distances.begin(); distanceIt != distances.end(); ++distanceIt){
		if (position <= *distanceIt && (*distanceIt - position < minDistance))
			return false;
		else if (position >= *distanceIt && (position - *distanceIt < minDistance))
			return false;
	}
	return true;
}

