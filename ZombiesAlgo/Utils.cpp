#include "stdafx.h"
#include "Utils.h"


Utils::Utils()
{
}


Utils::~Utils()
{
}

ifstream Utils::getFile(string fileName){
	ifstream file("TestFiles/" + fileName, ios::in);

	if (!file)
		cerr << "Impossible d'ouvrir le fichier !" << endl;

	return file;
}

ifstream Utils::chooseFile(){
	cout << "Choix du fichier\n"
		<< "1 - T_2_5\n"
		<< "2 - T_2_10\n"
		<< "3 - T_3_20\n"
		<< "4 - T_4_20\n"
		<< "5 - T_5_30\n"
		<< "6 - T_7_30\n";

	int choice;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		return Utils::getFile("T_2_5.txt");
	case 2:
		return Utils::getFile("T_2_10.txt");
	case 3:
		return Utils::getFile("T_3_20.txt");
	case 4:
		return Utils::getFile("T_4_20.txt");
	case 5:
		return Utils::getFile("T_5_30.txt");
	case 6:
		return Utils::getFile("T_7_30.txt");
	default:
		break;
	}
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
