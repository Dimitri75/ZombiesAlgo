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

