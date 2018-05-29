#include <iostream>
/*
* @author: rfiba MAy 2018
* Forward Euler Method
* Input:
* [numberOfPoints] [xMin] [xMax] [value of xMin]
*/

const double precision = 0.000001;

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

double calculateFunction(double t, double x)
{
	return t/x;
}

void calculateDirectIteration(int numberOfPoints, double step, Point *result)
{
	double predictor, corector;
	
	for (int i = 1; i <= numberOfPoints; i++)
	{
		result[i].x = result[i - 1].x + step;
		predictor = result[i - 1].x + step*calculateFunction(result[i].x, result[i - 1].y);
		corector = result[i - 1].x + step*calculateFunction(result[i].x, predictor);
		while (abs(predictor - corector) / corector > precision)
		{
			predictor = corector;
			corector = corector = result[i - 1].x + step*calculateFunction(result[i].x, predictor);
		}
		result[i].y = corector;
	}
}

int main(){
	int numberOfPoints;
	Point initialPoint;
	double step;
	cin >> numberOfPoints >> initialPoint.x >> initialPoint.y >> step;
	Point *result = new Point[numberOfPoints+1];
	result[0] = initialPoint;
	calculateDirectIteration(numberOfPoints, step, result);
	for (int i = 0; i <= numberOfPoints; i++)
		cout << "y = " << i << " : " << result[i].x << " " << result[i].y << endl;
	delete result;
	system("pause");
	return 0;
}