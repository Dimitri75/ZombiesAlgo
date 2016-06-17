// ZombiesAlgo.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"

map<int, function<void()>> question;

void initMapQuestions();
int chooseQuestion();
void doContinue(string& again);

void _tmain(int argc, _TCHAR* argv[])
{
	string again;
	int q;

	initMapQuestions();
	do {
		q = chooseQuestion();
		question[q]();
		doContinue(again);
	} while (again != "n");
}

void initMapQuestions(){
	question[1] = &Question1::proceed;
	question[2] = &Question2::proceed;
	question[3] = &Question3::proceed;
	question[4] = &Question4::proceed;
	question[5] = &Question5::proceed;
	question[6] = &Question6::proceed;
}

int chooseQuestion(){
	int q;

	cout << "Choix de l'exercice :" << endl
		<< "1 - Question 1" << endl
		<< "2 - Question 2" << endl
		<< "3 - Question 3" << endl
		<< "4 - Question 4" << endl
		<< "5 - Question 5" << endl
		<< "6 - Question 6" << endl;

	cin >> q;
	cout << endl;

	return q;
}

void doContinue(string& quit){
	cout << endl << "Continue ? (y/n)" << endl;
	cin >> quit;
	cout << endl;
}



