/*
 * @author: rfiba April 2018
 * Monte Carlo Method
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>

using namespace std;

double calculatePolynomial(int degreeOfPolynomial, double * coefficientArr, double x)
{
    double result = coefficientArr[0];

    for(int i = 1; i <= degreeOfPolynomial; i++)
        result += coefficientArr[i]*pow(x,i);

    return result;
}

bool checkPointInArea(double x, double y, int degreeOfPolynomial, double * coefficientArr)
{
    if(y >= 0)
    {
        if(calculatePolynomial(degreeOfPolynomial,coefficientArr, x) > y)
            return true;
        else
            return false;
    }
    else
    {
        if( calculatePolynomial(degreeOfPolynomial,coefficientArr, x) < y)
            return true;
        else
            return false;
    }
}

double calculateArea(int degreeOfPolynomial, int numberOfPoints, double *coefficientArr, double minimumInRange,
                    double maximumInRange,double beginOfRange,double endOfRange)
{

    double area = (maximumInRange-minimumInRange)*(endOfRange-beginOfRange);

    double x, y;
    int inTarget = 0;

    for(int i = 0; i < numberOfPoints; i++)
    {
        x = beginOfRange + ((double)rand()/RAND_MAX)*(endOfRange-beginOfRange);
        y = minimumInRange + ((double)rand()/RAND_MAX)*(maximumInRange - minimumInRange);

        if(checkPointInArea(x, y, degreeOfPolynomial, coefficientArr))
            inTarget++;
    }

    return ((double)inTarget/numberOfPoints)*area;
}

int main() {
    srand(time(NULL));
    int degreeOfPolynomial, numberOfPoints;
    double minimumInRange, maximumInRange, beginOfRange, endOfRange;
    cin >> degreeOfPolynomial >> numberOfPoints >> minimumInRange >> maximumInRange >> beginOfRange >> endOfRange;

    double *coefficientArr = new double[degreeOfPolynomial+1];

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    for(int i = 0; i < 10; i++)
        cout << calculateArea(degreeOfPolynomial, numberOfPoints, coefficientArr, minimumInRange, maximumInRange,
                              beginOfRange, endOfRange) << endl;

    return 0;
}