#pragma once
class Question3
{
public:
	Question3();
	~Question3();
	static int getMaxInCorrectDistanceAndApplyVariation(map<int, pair<double, int>>, int minDistance, vector<int> distances);
	static bool isDistanceOk(int position, int minDistance, vector<int> distances);
	static int chooseDistance();
	static void applyVariation(map<int, pair<double, int>> map, double max);
};

