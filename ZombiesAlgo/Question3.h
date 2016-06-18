/*
*Question 3 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de placer les k tireurs en maximisant le nombre de zombies tués
*selon les variations des estimations données et selon les distances séparant les tours
*/

#pragma once
class Question3
{
public:
	static void proceed();
private:
	static int getMaxInCorrectDistanceAndApplyVariation(map<int, pair<double, int>>, int minDistance, vector<int> takenPositions);
	static bool isDistanceOk(int position, int minDistance, vector<int> takenPositions);
	static int chooseDistance();
	static void applyVariation(map<int, pair<double, int>> map, double max);
	static void updateTower(map<int, pair<double, int>>, map<int, pair<double, int>>::iterator&);
};

