#include "stdafx.h"
#include "Question5.h"
#include "Problem.h"
#include "TSP.h"

void Question5::proceed(){

	Problem problem;
	problem.read();
	problem.calcDistances();

	TSP tsp;
	tsp.setProblem(problem);
	tsp.setMatrix();
	tsp.sortMatrix();
	for (int i = 1; i < 38; i++){
		tsp.findNeighbour(i);
	}

	cout << endl
		<< "Le meilleur parcourt :"
		<< endl;
	tsp.findNeighbour(11);
}