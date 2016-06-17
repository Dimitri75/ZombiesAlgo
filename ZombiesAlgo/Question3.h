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

