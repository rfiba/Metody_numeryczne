/*
 * @author: rfiba April 2018
 * Monte Carlo Method
 */
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double calculatePolynomial(int degreeOfPolynomial, double * coefficientArr, double x)
{
    double result = coefficientArr[0];

    for(int i = 1; i <= degreeOfPolynomial; i++)
        result += coefficientArr[i]*pow(x,i);

    return result;
}

int checkPointInArea(double x, double y, int degreeOfPolynomial, double * coefficientArr)
{
    return 0;
}

double calculateArea(int degreeOfPolynomial, int numberOfPoints, double *coefficientArr, double minimumInRange,
                    double maximumInRange,double beginOfRange,double endOfRange)
{
    srand(time(NULL));
    double area = (maximumInRange-minimumInRange)*(endOfRange*beginOfRange);
}

int main() {
    int degreeOfPolynomial, numberOfPoints;
    double minimumInRange, maximumInRange, beginOfRange, endOfRange;
    cin >> degreeOfPolynomial >> minimumInRange >> maximumInRange >> beginOfRange >> endOfRange;

    double *coefficientArr = new double[degreeOfPolynomial+1];

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    cout << calculatePolynomial(degreeOfPolynomial, coefficientArr, 5) << endl;

    return 0;
}