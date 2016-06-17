#include "stdafx.h"
#include "Question5.h"

static Distance1 distanceMatrix[MAX][MAX];
static Status statusList[MAX];
static double oldMatrix[MAX][MAX];
static double length;
static int number;
static Node nodeList[MAX];

struct less_than_key
{
	inline bool operator() (const pair<double, pair<int, string>>& pair1, const pair<double, pair<int, string>>& pair2)
	{
		return (pair1.first < pair2.first);
	}
};

void Question5::proceed(){
	read();
	calcDistances();
	setProblem(statusList);
	setMatrix();
	sortMatrix();

	vector<pair<double, pair<int, string>>> paths;
	for (int i = 1; i < MAX; i++){
		paths.push_back(findNeighbour(i));
	}

	sort(paths.begin(), paths.end(), less_than_key());
	pair<double, pair<int, string>> shortest = paths.at(0);

	cout << "Best path starts from " << shortest.second.first << endl <<
	"Path distance is " << shortest.first << endl << endl <<
	shortest.second.second << endl;
}

void Question5::read()
{
	ifstream fileCity = Utils::getFile("ville.txt");
	number = 38;
	for (int i = 0; i < number; i++)
	{
		fileCity >> nodeList[i].index >> nodeList[i].xCoord >> nodeList[i].yCoord;
	}

	cout << endl;
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
	for (int i = 0; i < MAX; i++)
	{
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

pair<double, pair<int, string>> Question5::findNeighbour(int city)
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

	stringstream ss;
	for (int i = 1; i < cityCount; i++){
		ss << path[i - 1];

		if (i != cityCount - 1)
			ss << " -> ";
		else
			ss << " -> " << cityInit << endl;
	}

	return pair<double, pair<int, string>>(length, pair<int, string>(cityInit, ss.str()));
}
