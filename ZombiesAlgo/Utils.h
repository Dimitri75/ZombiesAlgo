#pragma once
class Utils
{
public:
	Utils();
	~Utils();
	static ifstream chooseFile();
	static vector<int> parseFileIntoVector(ifstream&);
	static map<int, int> parseVectorIntoMap(vector<int>&); 
	static map<int, pair<double, int>> parseVectorIntoMapWithMeteo(vector<int>&);
	static int random(int max, int min = 0);
	static int getImprovementVariation();

private:
	static ifstream getFile(string);
	static int getMeteoVariation();
};

