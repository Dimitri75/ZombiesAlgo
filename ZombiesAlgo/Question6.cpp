/*
*Question 6 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de coder nos messages par différents algorithmes
*/

#include "stdafx.h"
#include "Question6.h"

static string constKey = "iqbgiubqegibqeibgqerig";

void Question6::proceed(){
	int choice = chooseAlgorithm();

	switch (choice)
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

int Question6::chooseAlgorithm()
{
	int choice;

	cout << endl << "Choix de l'algorithme d'encryption" << endl <<
		"1 - Ceasar" << endl <<
		"2 - Vigenere " << endl <<
		"3 - XOR" << endl;
	
	cin >> choice;
	return choice;
}

string Question6::getMessage(){
	string messageToEncrypt;
	cout << "Type a message to encrypt : " << endl;
	cin.ignore();
	getline(cin, messageToEncrypt);
	cout << endl;

	return messageToEncrypt;
}

void Question6::ceasar(){
	string messageToEncrypt = getMessage();

	string encryptedMessage = encryptionCeasar(messageToEncrypt);
	cout << endl << "Encrypted message is : " << encryptedMessage << endl;

	string decryptedMessage = decryptionCeasar(encryptedMessage);
	cout << "Decrypted message is : " << decryptedMessage << endl;
}

string Question6::encryptionCeasar(string msg)
{
	string encryptedMessage;
	for (int i = 0; i < msg.length(); ++i)
		encryptedMessage += msg[i] - 10;

	return encryptedMessage;
}

string Question6::decryptionCeasar(string msg)
{
	string decryptedMessage;
	for (int i = 0; i < msg.length(); ++i)
		decryptedMessage += msg[i] + 10;

	return decryptedMessage;
}

void Question6::vigenere()
{
	string messageToEncrypt = getMessage();

	string encryptedMessage = encryptionVigenere(messageToEncrypt, constKey);
	cout << endl << "Encrypted message is : " << encryptedMessage << endl;

	string decryptedMessage = decryptionVigenere(encryptedMessage, constKey);
	cout << "Decrypted message is : " << decryptedMessage << endl;
}

string Question6::encryptionVigenere(string msg, string key)
{
	transform(msg.begin(), msg.end(), msg.begin(), ::tolower);
	transform(key.begin(), key.end(), key.begin(), ::tolower);

	unsigned int j = 0;
	for (int i = 0; i < msg.length(); i++)
	{
		if (isalpha(msg[i]))
		{
			msg[i] += key[j] - 'a';

			if (msg[i] > 'z') 
				msg[i] += -'z' + 'a' - 1;
		}
		j = (j == (key.size() - 1)) ? 0 : j + 1;
	}
	return msg;
}

string Question6::decryptionVigenere(string msg, string key)
{
	unsigned int j = 0;
	for (int i = 0; i < msg.length(); i++)
	{
		if (isalpha(msg[i]))
		{
			if (msg[i] >= key[j])
				msg[i] = msg[i] - key[j] + 'a';
			else
				msg[i] = 'a' + ('z' - key[j] + msg[i] - 'a') + 1;
		}

		j = (j == (key.size() - 1)) ? 0 : j + 1;
	}
	return msg;
}

void Question6::xor()
{
	string messageToEncrypt = getMessage();

	string encryptedMessage = encryptionXOR(messageToEncrypt, constKey);
	cout << endl << "Encrypted message is : " << encryptedMessage << endl;

	string decryptedMessage = decryptionXOR(encryptedMessage, constKey);
	cout << "Decrypted message is : " << decryptedMessage << endl;
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


