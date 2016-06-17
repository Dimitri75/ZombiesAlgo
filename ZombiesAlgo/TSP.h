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

class TSP
{
public:
	TSP();
	void setProblem(Problem problem);
	void setMatrix();
	void sortMatrix();
	void findNeighbour(int city);
private:
	Problem problem;
	Status statusList[MAX];
	double oldMatrix[MAX][MAX];
	double length = 0;
};