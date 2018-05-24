#include <iostream>
/*
 * @author: rfiba MAy 2018
 * Forward Euler Method
 * Input:
 * [numberOfPoints] [xMin] [xMax] [value of xMin]
 */

using namespace std;

double calculateFunction(double t, double x)
{
    return x/(2*t+2);
}

void calculateEulerMethod(double xMin, double xMax, int numberOfPoints, double valueOfXMin, double *resultArr)
{
    double step = (xMax-xMin)/numberOfPoints;
    resultArr[0] = valueOfXMin;
    double t = xMin, tPrevious = xMin;

    for(int i = 1; i <= numberOfPoints; i++)
    {
        resultArr[i] = resultArr[i-1] + step*calculateFunction(tPrevious, resultArr[i-1]);
        tPrevious = t;
        t = xMin +(i+1)*step;
    }
}

int main() {
    int numberOfPoints;
    double xMin, xMax, valueOfXMin;
    cin >> numberOfPoints >> xMin >> xMax >> valueOfXMin;
    double * resultArr = new double[numberOfPoints];
    calculateEulerMethod(xMin, xMax, numberOfPoints, valueOfXMin, resultArr);
    for(int i = 0; i < numberOfPoints; i++)
       cout << resultArr[i] << endl;
    delete resultArr;
    return 0;
}
