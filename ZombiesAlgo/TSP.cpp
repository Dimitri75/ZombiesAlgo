#include "stdafx.h"
#include "Problem.h"
#include "TSP.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

TSP::TSP()
{
	for (int i = 0; i < problem.getNumber(); i++){
		statusList[i].index = i;
		statusList[i].approched = 0;
		statusList[i].fullDistance = 0;
	}
}

void TSP::setProblem(Problem problem){
	this->problem = problem;
}

void TSP::setMatrix()
{
	for (int i = 0; i < problem.getNumber(); i++)
		for (int j = 0; j < problem.getNumber(); j++)
			oldMatrix[i][j] = problem.distanceMatrix[i][j].next;
}

void TSP::sortMatrix()
{

	for (int i = 0; i < problem.getNumber(); i++)
	{
		sort(problem.distanceMatrix[i], problem.distanceMatrix[i] + problem.getNumber(), [](Distance1 const &a, Distance1 const &b) {
			return a.next < b.next; });


	}
}
void TSP::findNeighbour(int city)
{
	int cityCount = problem.getNumber();
	double length = 0;
	bool visited[MAX];
	fill_n(visited, cityCount, false);
	int path[MAX];

	int cityInit = city;



	bool finished = false;
	int indexAway = 0;
	path[indexAway] = city;
	while (!finished)
	{
		finished = true;
		for (int i = 1; i < cityCount; i++)
		{
			if (!visited[problem.distanceMatrix[city - 1][i].index])
			{
				finished = false;
				length += problem.distanceMatrix[city - 1][i].next;
				visited[city] = true;
				city = problem.distanceMatrix[city - 1][i].index;
				indexAway++;
				path[indexAway] = city;
				break;
			}
		}
	}

	length += oldMatrix[city - 1][0];
	indexAway++;




	cout << "\n Cout du chemin d'approvisionnement : " << length << " a partir de la ville " << cityInit << "\n" << endl;


	cout << "\n Chemin d'approvisionnement:\n ";


	for (int i = 1; i < cityCount; i++)
	{
		cout << path[i - 1];

		if (i != cityCount - 1)
		{
			cout << " -> ";
		}
		else
		{
			cout << " -> " << cityInit << endl;

		}
	}
}
