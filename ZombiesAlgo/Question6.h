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
	static string decryptionVigenere(string, string);
	static string gestionCle(string);
	static string encryptionVigenere(string, string);
	static void vigenere();
	static char decryptionCeasar(char);
	static char encryptionCeasar(char);
	static void ceasar();
	static void displayChooseAlgorithm();
};

