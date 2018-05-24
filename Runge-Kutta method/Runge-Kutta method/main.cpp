/*
	@author: rfiba May 2018
	classical Runge–Kutta method (RK4)
	Input:
	[numberOfPoints] [initialX] [initialY] [step]
	Output:
	Points from initial to initial + numberOfPoints
*/

#include <iostream>

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

void calculateRungeKuttaMethod(Point initialPoint, double step, int numberOfPoints, Point * result)
{
	double k1, k2, k3, k4;
	for (int i = 1; i <= numberOfPoints; i++)
	{
		k1 = step*calculateFunction(result[i - 1]);
		k2 = step*calculateFunction(result[i - 1] + Point(0.5*step, k1/2));
		k3 = step*calculateFunction(result[i - 1] + Point(0.5*step, k2/2));
		k4 = step*calculateFunction(result[i - 1] + Point(step, k3));
		result[i].y = result[i - 1].y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		result[i].x = result[i - 1].x + step;
	}
}

int main() {
	double step;
	Point initialPoint;
	int numberOfPoints;

	cin >> numberOfPoints >> initialPoint.x >> initialPoint.y >> step;
	Point *result = new Point[numberOfPoints + 1];
	result[0] = initialPoint;

	calculateRungeKuttaMethod(initialPoint, step, numberOfPoints, result);
	
	for (int i = 0; i <= numberOfPoints;i++)
		cout << result[i].x << " " << result[i].y << endl;

	system("pause");
	delete result;
	return 0;
}
