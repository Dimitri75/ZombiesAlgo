/*
*Question 6 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet de coder nos messages par différents algorithmes
*/

#include "stdafx.h"
#include "Question6.h"

static string globalKey = "izabfiuazbaifzbuaizufb";

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

	string encryptedMessage = encryptionVigenere(messageToEncrypt, globalKey);
	cout << endl << "Encrypted message is : " << encryptedMessage << endl;

	string decryptedMessage = decryptionVigenere(encryptedMessage, globalKey);
	cout << "Decrypted message is : " << decryptedMessage << endl;
}

string Question6::encryptionVigenere(string& message, string& key){
	transform(message.begin(), message.end(), message.begin(), tolower);
	transform(key.begin(), key.end(), key.begin(), tolower);

	string encryptedMessage;
	unsigned int i, j, ch;
	for (i = 0, j = 0; i < message.length(); ++i, ++j) {
		if (j >= key.length())
			j = 0;

		if (message[i] >= 'a' && message[i] <= 'z')
			ch = ((message[i] - 'a') + (key[j] - 'a')) % 26;
		else
			ch = message[i] - 'a';

		encryptedMessage.append(string(1, (char)(ch + 'a')));
	}
	return encryptedMessage;
}

string Question6::decryptionVigenere(string& encryptedMessage, string& key){
	string decryptedMessage;

	unsigned int i, j, ch;
	for (i = 0, j = 0; i < encryptedMessage.length(); ++i, ++j) {
		if (j >= key.length())
			j = 0;

		if (encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z')
			ch = ((encryptedMessage[i] - 'a') + 26 - (key[j] - 'a')) % 26;
		else
			ch = encryptedMessage[i] - 'a';

		decryptedMessage.append(string(1, (char)(ch + 'a')));
	}
	return decryptedMessage;
}





void Question6::xor()
{
	string messageToEncrypt = getMessage();

	string encryptedMessage = encryptionXOR(messageToEncrypt, globalKey);
	cout << endl << "Encrypted message is : " << encryptedMessage << endl;

	string decryptedMessage = decryptionXOR(encryptedMessage, globalKey);
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


