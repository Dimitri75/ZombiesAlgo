// ZombiesAlgo.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"


void _tmain(int argc, _TCHAR* argv[])
{
	int x;

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
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}

	cout << endl;
	system("pause");
}

