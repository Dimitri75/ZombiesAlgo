#pragma once
class Question2
{
public:
	Question2();
	~Question2();
	static int getMaxInCorrectDistance(map<int, int> map, int minDistance, vector<int> distances);
	static bool isDistanceOk(int position, int minDistance, vector<int> distances);
	static int chooseDistance();
};

