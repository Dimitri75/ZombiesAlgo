/*
*Question 2 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de placer les k tireurs en maximisant le nombre de zombies tués
*selon les estimations données et selon les distances séparant les tours
*/

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
	vector<int> takenPositions;
	for (int i = 1; i <= nbShooters; ++i){
		maxPosition = getMaxInCorrectDistance(map, distance, takenPositions);
		efficiency = map[maxPosition];
		cout << "Shooter " << i << " at " << maxPosition << " (" << efficiency << ")" << endl;
		takenPositions.push_back(maxPosition);
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

int Question2::getMaxInCorrectDistance(map<int, int> map, int minDistance, vector<int> takenPositions){
	int maxPosition = map.begin()->first, position, efficiency;

	for (auto it = map.begin(); it != map.end(); ++it){
		position = it->first;
		efficiency = it->second;

		if (isDistanceOk(position, minDistance, takenPositions))
			maxPosition = efficiency > map[maxPosition] ? position : maxPosition;
	}

	return maxPosition;
}

bool Question2::isDistanceOk(int position, int minDistance, vector<int> takenPositions){
	for (auto takenPositionsIt = takenPositions.begin(); takenPositionsIt != takenPositions.end(); ++takenPositionsIt){
		if (position <= *takenPositionsIt && *takenPositionsIt - position < minDistance)
			return false;
		else if (position >= *takenPositionsIt && position - *takenPositionsIt < minDistance)
			return false;
	}
	return true;
}

