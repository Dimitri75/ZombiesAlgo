/*
*Question 6 du devoir 2
*R�alis� par Dimitri BUHON, Noel SOBCZAK et C�line CARLES
*Ce fichier permet de coder nos messages par diff�rents algorithmes
*/

#pragma once
class Question6
{
public:
	static void proceed();
private:
	static string decryptionXOR(string, string);
	static string encryptionXOR(string, string);
	static void xor();
	static string decryptionVigenere(string&, string&);
	static string encryptionVigenere(string&, string&);
	static void vigenere();
	static string decryptionCeasar(string);
	static string encryptionCeasar(string);
	static void ceasar();
	static string getMessage();
	static int chooseAlgorithm();
};

