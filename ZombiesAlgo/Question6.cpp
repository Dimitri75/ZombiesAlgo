#include "stdafx.h"
#include "Question6.h"

void Question6::proceed(){
	/*
	Vos services de renseignement ont pu d�terminer la source du virus. 
	En effet, des entit�s extraterrestres ont pu propager ce virus dans le but de r�duire la plan�te � l�esclavage. 
	Vous �tes sur le point de d�couvrir leur laboratoires et usines de production. 
	Vous souhaitez s�curisez vos �changes d�informations.
	Il vous est demand� de mettre en place un syst�me qui permettra de s�curiser vos �changes de messages.
	*/

	string key = "jhgyufzzzzzkyfluyghy";

	string message = "Hello world";
	cout << "Message : " << message << endl;

	string encryptedMessage = vigenereEncryption(message, key);
	cout << "Encrypted message : " << encryptedMessage << endl;

	string decryptedMessage = vigenereDecryption(encryptedMessage, key);
	cout << "Decrypted message : " << decryptedMessage << endl;

	// TODO : perhaps should we do something better than vigenere ? :x
}

string Question6::vigenereEncryption(string msg, string key)
{
	std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);
	unsigned int j = 0;
	for (int i = 0; i < msg.length(); i++)
	{
		if (isalpha(msg[i]))
		{
			msg[i] += key[j] - 'A';
			if (msg[i] > 'Z') msg[i] += -'Z' + 'A' - 1;
		}
		j = j + 1 == key.length() ? 0 : j + 1;
	}
	return msg;
}

string Question6::vigenereDecryption(string msg, string key)
{
	std::transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
	std::transform(key.begin(), key.end(), key.begin(), ::toupper);
	unsigned int j = 0;
	for (int i = 0; i < msg.length(); i++)
	{
		if (isalpha(msg[i]))
		{
			msg[i] = msg[i] >= key[j] ?
				msg[i] - key[j] + 'A' :
				'A' + ('Z' - key[j] + msg[i] - 'A') + 1;
		}
		j = j + 1 == key.length() ? 0 : j + 1;
	}
	return msg;
}
