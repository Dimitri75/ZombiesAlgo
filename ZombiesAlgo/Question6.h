/*
*Question 6 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de coder nos messages par différents algorithmes
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

