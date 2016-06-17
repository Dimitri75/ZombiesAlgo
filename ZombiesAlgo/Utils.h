#pragma once
class Utils
{
public:
	Utils();
	~Utils();
	static ifstream getFile(string);
	static ifstream chooseFile();
	static vector<int> parseFileIntoVector(ifstream&);
	static map<int, int> parseVectorIntoMap(vector<int>&);
};

