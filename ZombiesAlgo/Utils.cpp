#include "stdafx.h"
#include "Utils.h"

ifstream Utils::getFile(string fileName){
	ifstream file("TestFiles/" + fileName, ios::in);

	if (!file)
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	return file;
}

ifstream Utils::chooseFile(){
	map<int, string> filesMap = getFilesMap();

	int choice;
	do {
		cout << "Choose a file" << endl;
		for (auto it = filesMap.begin(); it != filesMap.end(); ++it){
			cout << it->first << " - " << it->second << endl;
		}

		cin >> choice;
		cout << endl;
	} while (choice <= 0 || choice > filesMap.size());

	return Utils::getFile(filesMap[choice]);
}

map<int, string> Utils::getFilesMap(){
	map<int, string> filesMap;
	filesMap[1] = "T_2_5.txt";
	filesMap[2] = "T_2_10.txt";
	filesMap[3] = "T_3_20.txt";
	filesMap[4] = "T_4_20.txt";
	filesMap[5] = "T_5_30.txt";
	filesMap[6] = "T_7_30.txt";

	return filesMap;
}

vector<int> Utils::parseFileIntoVector(ifstream& file){
	int number;
	vector<int> list;
	while (file >> number){
		list.push_back(number);
	}

	return list;
}

map<int, int> Utils::parseVectorIntoMap(vector<int>& vector){
	map<int, int> map;
	int position, efficiency;
	for (auto it = vector.begin(); it != vector.end(); ++it){
		position = *it;
		efficiency = *++it;

		map[position] = efficiency;
	}

	return map;
}

int Utils::getMeteoVariation(){
	return Utils::random(30) - 15;
}

int Utils::getImprovementVariation(){
	return Utils::random(15);
}

// Return a map<position, <efficiency, variation>>
map<int, pair<double, int>> Utils::parseVectorIntoMapWithMeteo(vector<int>& vector){
	map<int, pair<double, int>> map;
	int position, efficiency;
	double meteoVariation;
	double variation;

	for (auto it = vector.begin(); it != vector.end(); ++it){
		meteoVariation = getMeteoVariation();
		variation = (100 + meteoVariation) / 100;

		position = *it;
		efficiency = *++it;

		map[position] = pair<double, int>(efficiency * variation, meteoVariation);
	}

	return map;
}


int Utils::random(int max, int min){
	random_device seeder;
	mt19937 engine(seeder());
	uniform_int_distribution<int> dist(min, max);
	return dist(engine);
}
