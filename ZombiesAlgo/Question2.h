/*
*Question 2 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de placer les k tireurs en maximisant le nombre de zombies tués
*selon les estimations données et selon les distances séparant les tours
*/

#pragma once
class Question2
{
public:
	static void proceed();
private:
	static int getMaxInCorrectDistance(map<int, int> map, int minDistance, vector<int> takenPositions);
	static bool isDistanceOk(int position, int minDistance, vector<int> takenPositions);
	static int chooseDistance();
};

