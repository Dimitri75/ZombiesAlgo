#pragma once
class Utils
{
public:
	static ifstream getFile(string);
	static ifstream chooseFile();
	static vector<int> parseFileIntoVector(ifstream&);
	static map<int, int> parseVectorIntoMap(vector<int>&); 
	static map<int, pair<double, int>> parseVectorIntoMapWithMeteo(vector<int>&);
	static map<int, pair<double, int>> parseVectorIntoMapWithMeteoAndKeepEstimation(vector<int>&);
	static int random(int max, int min = 0);
	static int getMeteoVariation();
	static int getImprovementVariation();

private:
	static map<int, string> getFilesMap();
};

