/*
*Question 6 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de coder nos messages par différents algorithmes
*/

#include "stdafx.h"
#include "Question6.h"

void Question6::proceed(){

	displayChooseAlgorithm();
	int x;
	cout << endl;
	cin >> x;
	cout << endl;
	switch (x)
	{
	case 1:
		ceasar();
		break;
	case 2:
		vigenere();
		break;
	case 3:
		xor();
		break;
	default:
		break;
	}
}

void Question6::ceasar(){
	
	string messageEncrypt;
	cout << "Message a encrypte" << endl;
	cin.ignore();
	getline(cin, messageEncrypt);
	string output;
	for (int x = 0; x < messageEncrypt.length(); x++)
	{
		output += encryptionCeasar(messageEncrypt[x]);
	}
	cout << endl << output << endl;
	string de;
	for (int x = 0; x < output.length(); x++)
	{
		de += decryptionCeasar(output[x]);
	}
	cout << endl << de << endl;

}

char Question6::encryptionCeasar(char c)
{

	c = c - 10;
	return c;
}

char Question6::decryptionCeasar(char c)
{

	c = c + 10;
	return c;
	
}


void Question6::vigenere()
{
	
	string cle = "algo";
	
	string messageEncrypt;
	cout << "Message a encrypte : " << endl;
	cin.ignore();
	getline(cin, messageEncrypt);
	
	string message = encryptionVigenere(messageEncrypt, cle);
	cout << "le message encrypte devient : " << message << endl;
	string messageDecrypt = decryptionVigenere(message, cle);
	cout << "le message clair est " << messageDecrypt << endl;
	
}

string Question6::encryptionVigenere(string text, string cle){

	string res = "";
	string key = gestionCle(cle);

	for (int i = 0, j = 0; i < text.length(); i++){
		char c = text[i];
		if (c >= 'A' && c <= 'Z')
		{
			res += ((c + key[j] - 2 * 'A') % 26 + 'A');
			j = (j + 1) % key.length();

		}
		else if (c >= 'a' && c <= 'z')
		{
			res += ((c + key[j] - 2 * 'a') % 26 + 'a');
			j = (j + 1) % key.length();
		}

	}
	return res;
}

string Question6::gestionCle(string cle)
{

	string key = "";
	
		for (int i = 0; i < cle.length(); i++) {
		char c = cle[i];
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
			key = key + c;
			
		}
		
	}
	return key;
	
		
}

string Question6::decryptionVigenere(string text, string cle) {
	string res = "";

	string key = gestionCle(cle);

	for (int i = 0, j = 0; i < text.length(); i++) {
		char c = text[i];

		if (c >= 'A' && c <= 'Z')
		{
			res += ((c - key[j] + 26 - 2 * 'A') % 26 + 'A');
			j = (j + 1) % key.length();


		}
		else if (c >= 'a' && c <= 'z')
		{
			res += ((c - key[j] + 26) % 26 + 'a');
			j = (j + 1) % key.length();
		}
	}
	return res;
}

void Question6::xor()
{
	
	string messageUncrypt;
	string messageEncrypt;
	cout << endl << "Votre message a encrypter" << endl;
	cin.ignore();
	getline(cin, messageEncrypt);
	cout << endl;
	string message = encryptionXOR(messageEncrypt, "ras");
	cout << "Message encrypte : " << message << endl;
	
	cout << "Message decrypte : " << decryptionXOR(message, "ras");
}


string Question6::encryptionXOR(string msg, string key)
{
	for (string::size_type i = 0; i < msg.size(); ++i)
		 msg[i] = msg[i] ^ key[i % (sizeof(key) / sizeof(key))];
	return msg;
}

string Question6::decryptionXOR(string msg, string key)
{
	return encryptionXOR(msg, key);
}

void Question6::displayChooseAlgorithm()
{
	
	cout << endl << "Choix de l'algorithme d'encryption" << endl;
	cout << "1 - Ceasar" << endl << "2 - Vigenere " << endl << "3 - XOR";
	
}
