#include<iostream>

using namespace std;

struct Point {

	double x;
	double y;
	Point() {};
	Point(double xToAdd, double yToAdd) {
		x = xToAdd;
		y = yToAdd;
	}
	Point operator+(Point toAdd) {
		return Point(x + toAdd.x, y + toAdd.y);
	}
};

double calculateFunction(Point toCalculate)
{
	return toCalculate.x + toCalculate.y;
}

void calculateImprovedEuler(Point initialPoint, double step, int numberOfPoints, Point * result)
{
	double forwardEulerResult, backwardEulerResult;
	for (int i = 1; i <= numberOfPoints; i++)
	{
		result[i].x = result[i - 1].x + step;
		forwardEulerResult = result[i - 1].y + step*calculateFunction(result[i - 1]);
		backwardEulerResult = result[i - 1].y + step*calculateFunction(Point(result[i - 1].x, forwardEulerResult));
		result[i].y = (forwardEulerResult + backwardEulerResult) / 2;
	}
}

int main()
{
	return 0;
}