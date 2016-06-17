// ZombiesAlgo.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

/*typedef Question(*FPTR)();
map<int, FPTR> question;

void initMapQuestions(){
	question[1] = &Question1();
	question[2] = &Question2();
	question[3] = &Question3();
	question[4] = &Question4();
	question[5] = &Question5();
	question[6] = &Question6();
}

initMapQuestions();
question[x]();*/

void _tmain(int argc, _TCHAR* argv[])
{
	string quit;
	int x;

	do {
		cout << "Choix de l'exercice :" << endl
			<< "1 - Question 1" << endl
			<< "2 - Question 2" << endl
			<< "3 - Question 3" << endl
			<< "4 - Question 4" << endl
			<< "5 - Question 5" << endl
			<< "6 - Question 6" << endl;

		cin >> x;
		cout << endl;

		switch (x)
		{
		case 1:
			Question1();
			break;
		case 2:
			Question2();
			break;
		case 3:
			Question3();
			break;
		case 4:
			Question4();
			break;
		case 5:
			Question5();
			break;
		case 6:
			Question6();
			break;
		default:
			break;
		}

		cout << endl << "Quit ? (y/n)" << endl;
		cin >> quit;
		cout << endl;
	} while (quit != "y");
}



