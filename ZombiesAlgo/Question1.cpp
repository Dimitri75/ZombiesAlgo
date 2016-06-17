#include "stdafx.h"
#include "Question1.h"

void Question1::proceed(){
	ifstream file = Utils::chooseFile();

	vector<int> vector = Utils::parseFileIntoVector(file);

	int nbShooters = vector.at(0);
	vector.erase(vector.begin());

	int nbTowers = vector.at(0);
	vector.erase(vector.begin());

	map<int, int> map = Utils::parseVectorIntoMap(vector);

	int max;
	int bestPosition;
	for (int i = 1; i <= nbShooters; ++i){
		max = getMax(map);
		bestPosition = map[max];
		cout << "Shooter " << i << " at " << bestPosition << " (" << max << ")" << endl;
		map.erase(max);
	}
}

int Question1::getMax(map<int, int> map){
	int max = 0;

	for (auto it = map.begin(); it != map.end(); ++it)
		max = it->first > max ? it->first : max;

	return max;
}


