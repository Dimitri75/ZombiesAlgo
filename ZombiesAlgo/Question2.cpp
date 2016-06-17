#include "stdafx.h"
#include "Question2.h"


Question2::Question2()
{
	ifstream file = Utils::chooseFile();

	vector<int> list = Utils::parseFileIntoVector(file);

	int nbShooters = list.at(0);
	list.erase(list.begin());

	int nbTowers = list.at(0);
	list.erase(list.begin());

	map<int, int> map = Utils::parseVectorIntoMap(list);

	int distance = chooseDistance();

	int max;
	int bestPosition;
	vector<int> distances;
	for (int i = 1; i <= nbShooters; ++i){
		max = getMaxInCorrectDistance(map, distance, distances);
		bestPosition = map[max];
		cout << "Shooter " << i << " at " << bestPosition << " (" << max << ")" << endl;
		map.erase(max);
	}
}


Question2::~Question2()
{
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
	int max = 0, efficiency, position;
	bool distanceIsOk = false;

	for (auto it = map.begin(); it != map.end(); ++it){
		efficiency = it->first;
		position = it->second;

		if (isDistanceOk(position, minDistance, distances))
			max = efficiency > max ? efficiency : max;
	}

	distances.push_back(map[max]);

	return max;
}

bool Question2::isDistanceOk(int position, int minDistance, vector<int> distances){
	for (auto distanceIt = distances.begin(); distanceIt != distances.end(); ++distanceIt){
		if (position <= *distanceIt && *distanceIt - position < minDistance)
			return false;
		else if (position > *distanceIt && position - *distanceIt < minDistance)
			return false;
	}
	return true;
}

