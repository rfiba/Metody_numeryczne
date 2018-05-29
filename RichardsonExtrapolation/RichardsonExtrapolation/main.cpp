#include <iostream>

using namespace std;

double calculateFunction(double t, double x)
{
	return 2*t;
}

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

void calculateRichardson(Point initialPoint, Point *result, int numberOfPoints, double smallStep, double bigStep)
{
	result[0] = initialPoint;
	double multiplier = bigStep / smallStep;
	double resultFromSS;
	double smallX = result[0].x;
	resultFromSS = result[0].y + smallStep*calculateFunction(result[0].x, result[0].y);
	double *tmp = new double[numberOfPoints + 1];
	tmp[0] = result[0].x;
	
	for (int i = 1; i <= numberOfPoints; i++)
	{
		result[i].x = result[i - 1].x + bigStep;
		tmp[i] = tmp[i - 1] + bigStep*calculateFunction(result[i - 1].x, tmp[i - 1]);
	
		for (int j = 0; j < multiplier; j++)
		{
			resultFromSS = resultFromSS + smallStep*calculateFunction(smallX, resultFromSS);
			smallX += smallStep;
		}
		
		result[i].y = (4 * resultFromSS - tmp[i]) / 3;
	}

	delete tmp;
}

int main()
{
	int numberOfPoints;
	Point initialPoint;
	double smallStep, bigStep;
	cin >> numberOfPoints >> initialPoint.x >> initialPoint.y >> smallStep >> bigStep;
	Point *result = new Point[numberOfPoints + 1];
	
	calculateRichardson(initialPoint, result, numberOfPoints, smallStep, bigStep);
	for (int i = 0; i <= numberOfPoints; i++)
		cout << result[i].x << " : " << result[i].y << endl;
	
	system("pause");
	delete result;
	return 0;
}