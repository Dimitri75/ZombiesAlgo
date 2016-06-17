#pragma once
class Question2
{
public:
	static void proceed();
	static int getMaxInCorrectDistance(map<int, int> map, int minDistance, vector<int> distances);
	static bool isDistanceOk(int position, int minDistance, vector<int> distances);
	static int chooseDistance();
};

