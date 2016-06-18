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

	int maxKey;
	int estimation;
	for (int i = 1; i <= nbShooters; ++i){
		maxKey = getMax(map);
		estimation = map[maxKey];
		cout << "Shooter " << i << " at " << maxKey << " (" << estimation << ")" << endl;
		map.erase(maxKey);
	}
}

int Question1::getMax(map<int, int> map){
	int maxKey = map.begin()->first;

	for (auto it = map.begin(); it != map.end(); ++it)
		maxKey = it->second > map[maxKey] ? it->first : maxKey;

	return maxKey;
}


