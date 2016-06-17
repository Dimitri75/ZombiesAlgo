#include "stdafx.h"
#include "Question5.h"
#include <algorithm>


static Distance1 distanceMatrix[MAX][MAX];
static Status statusList[MAX];
static double oldMatrix[MAX][MAX];
static double length;
static int number;
static Node nodeList[MAX];

void Question5::proceed(){

	Question5::read();
	Question5::calcDistances();

	Question5::setProblem(statusList);
	Question5::setMatrix();
	Question5::sortMatrix();
	for (int i = 1; i < MAX; i++){
		Question5::findNeighbour(i);
	}

	cout << endl
		<< "Le meilleur parcourt :"
		<< endl;
	Question5::findNeighbour(11);
}

void Question5::read()
{
	ifstream fileCity = Utils::getFile("ville.txt");
	number = 38;
	for (int i = 0; i < number; i++)
	{
		fileCity >> nodeList[i].index >> nodeList[i].xCoord >> nodeList[i].yCoord;
	}

	cout << "\n";
}


void Question5::calcDistances()
{
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)

		{
			if (i == j)
			{
				distanceMatrix[i][j].next = 0;
				distanceMatrix[i][j].index = nodeList[j].index;
			}
			else
			{
				double distanceX = (nodeList[i].xCoord - nodeList[j].xCoord);
				double distanceY = (nodeList[i].yCoord - nodeList[j].yCoord);
				distanceMatrix[i][j].next = sqrt((distanceX*distanceX) + (distanceY*distanceY));
				distanceMatrix[i][j].index = nodeList[j].index;
			}
		}
	}
}

int Question5::getNumber()
{
	return number;
}

void Question5::setProblem(Status statusList[]){

	for (int i = 0; i < MAX; i++){
		statusList[i].index = i;
		statusList[i].approched = 0;
		statusList[i].fullDistance = 0;
	}
}

void Question5::setMatrix()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			oldMatrix[i][j] = distanceMatrix[i][j].next;
}

void Question5::sortMatrix()
{

	for (int i = 0; i < MAX; i++)
	{
		sort(distanceMatrix[i], distanceMatrix[i] + getNumber(), [](Distance1 const &a, Distance1 const &b) {
		return a.next < b.next; });


	}
}
void Question5::findNeighbour(int city)
{
	int cityCount = getNumber();
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
			if (!visited[distanceMatrix[city - 1][i].index])
			{
				finished = false;
				length += distanceMatrix[city - 1][i].next;
				visited[city] = true;
				city = distanceMatrix[city - 1][i].index;
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
