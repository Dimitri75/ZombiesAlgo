#define MAX 38

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

class Problem
{
public:
	void read();
	void calcDistances();
	double ** getDistanceMatrix();
	int getNumber();
	Distance1 distanceMatrix[MAX][MAX];

private:
	int number;
	Node nodeList[MAX];

};