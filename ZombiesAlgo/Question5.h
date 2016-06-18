/*
*Question 5 du devoir 2
*Réalisé par Dimitri BUHON, Noel SOBCZAK et Céline CARLES
*Ce fichier permet d'approvisionner toutes les tours en commançant par le meilleur point de début
*/

#pragma once
#define MAX 38

typedef struct {
	int index;
	bool approched;
	double fullDistance;
} Status;

struct City {
	double x;
	double y;
};

struct Distance {
	int index;
	double distance;
};

typedef struct
{
	int index;
	double xCoord;
	double yCoord;
} Node;

typedef struct
{
	int index;
	double next;
} Distance1;

class Question5
{
public:
	static void proceed();
private:	
	static void read();
	static void calcDistances();
	static double ** getDistanceMatrix();
	static int getNumber();
	static void setProblem(Status statusList[]);
	static void setMatrix();
	static void sortMatrix();
	static pair<double, pair<int, string>> findNeighbour(int city);
};