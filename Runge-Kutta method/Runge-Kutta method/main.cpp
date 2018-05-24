#include <iostream>

using namespace std;

struct Point {
	double x;
	double y;
};

double calcuateFunction(Point toCalculate)
{
	return 0;
}

double calculateRungeKuttaMethod(Point initiaPoint, double step, int numberOfPoints, double * result)
{
	double k1, k2, k3, k4;
	for (int i = 1; i < numberOfPoints; i++)
	{
		k1 = step*calcuateFunction()
	}
}

int main() {
	double step;
	Point initialPoint;
	int numberOfPoints;
	Point *result = new Point[numberOfPoints+1];
	
	cin >> numberOfPoints >> initialPoint.x >> initialPoint.y >> step;
	result[0] = initialPoint;
	delete result;
	return 0;
}
