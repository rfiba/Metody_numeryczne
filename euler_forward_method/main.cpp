#include <iostream>

using namespace std;

double calculataFunction(double t, double x)
{
    return 0;
}

void calculateEulerMethod(double xMin, double xMax, int numberOfPoints, double valueOfXMin, double *resultArr)
{
    double step = (xMax-xMin)/numberOfPoints;
    resultArr[0] = valueOfXMin;
    double t = xMin, tPrevious = xMin;

    for(int i = 1; i < numberOfPoints; i++)
    {
        resultArr[i] = resultArr[i-1] + step*calculataFunction(tPrevious, resultArr[i-1]);
        tPrevious = t;
        t = xMin +(i+1)*step;
    }
}

int main() {
    int numberOfPoints;
    double xMin, xMax, valueOfXMin;
    cin >> numberOfPoints >> xMin >> xMax >> valueOfXMin;
    double * resultArr = new double[numberOfPoints];
    
    delete resultArr;
    return 0;
}