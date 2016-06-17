#include "stdafx.h"
#include "Problem.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;


void Problem::read()
{
	ifstream fileCity = Utils::getFile("ville.txt");
	number = 38;
	for (int i = 0; i < number; i++)
	{
		fileCity >> nodeList[i].index >> nodeList[i].xCoord >> nodeList[i].yCoord;
	}

	cout << "\n";
}


void Problem::calcDistances()
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

int Problem::getNumber()
{
	return number;
}
