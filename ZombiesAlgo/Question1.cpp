#include "stdafx.h"
#include "Question1.h"


Question1::Question1()
{
	ifstream file = Utils::chooseFile();

	vector<int> list = Utils::parseFileIntoVector(file);

	int nbShooters = list.at(0);
	list.erase(list.begin());

	int nbTowers = list.at(0);
	list.erase(list.begin());

	map<int, int> map = Utils::parseVectorIntoMap(list);

	int max;
	int bestPosition;
	for (int i = 1; i <= nbShooters; ++i){
		max = getMax(map);
		bestPosition = map[max];
		cout << "Shooter " << i << " at " << bestPosition << " (" << max << ")" << endl;
		map.erase(max);
	}
}


Question1::~Question1()
{
}

int Question1::getMax(map<int, int> map){
	int max = 0;

	for (auto it = map.begin(); it != map.end(); ++it)
		max = it->first > max ? it->first : max;

	return max;
}


