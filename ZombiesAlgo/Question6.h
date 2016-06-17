#pragma once
class Question6
{
public:
	static void proceed();
	static string vigenereEncryption(string msg, string key);
	static string vigenereDecryption(string msg, string key);
private:
	static const int alphabet_length = 26;
};

