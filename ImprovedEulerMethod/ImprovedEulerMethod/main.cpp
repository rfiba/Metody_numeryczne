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
	return 2*(pow(toCalculate.y, 2)+1)/(pow(toCalculate.x, 2)+4);
}

void calculateImprovedEulerMethod(Point initialPoint, double step, int numberOfPoints, Point * result)
{
	double forwardEulerResult, backwardEulerResult;
	for (int i = 1; i <= numberOfPoints; i++)
	{
		result[i].x = result[i - 1].x + step;
		forwardEulerResult = result[i - 1].y + step*calculateFunction(result[i - 1]);
		backwardEulerResult = result[i - 1].y + step*calculateFunction(Point(result[i].x, forwardEulerResult));
		result[i].y = (forwardEulerResult + backwardEulerResult) / 2;
	}
}

int main()
{
	double step;
	Point initialPoint;
	int numberOfPoints;

	cin >> numberOfPoints >> initialPoint.x >> initialPoint.y >> step;
	Point *result = new Point[numberOfPoints + 1];
	result[0] = initialPoint;

	calculateImprovedEulerMethod(initialPoint, step, numberOfPoints, result);

	for (int i = 0; i <= numberOfPoints; i++)
		cout << result[i].x << " " << result[i].y << endl;

	system("pause");
	delete result;
	return 0;
}