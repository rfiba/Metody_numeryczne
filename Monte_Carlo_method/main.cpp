/*
 * @author: rfiba April 2018
 * Monte Carlo Method
 * Input:
 * [degree of polynomial]
 * [number of points] [xMin] [xMax]
 * [coefficients from a0 to an]
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

double calculateIntegral(int degreeOfPolynomial, int numberOfPoints, double *coefficientArr, double xMin, double xMax)
{
    double x;
    double result = 0;
    int inTarget = 0;

    for(int i = 0; i < numberOfPoints; i++)
        result += calculatePolynomial(degreeOfPolynomial, coefficientArr, xMin + ((double)rand()/RAND_MAX)*(xMax - xMin));

    return (xMax-xMin)*(result/numberOfPoints);
}

int main() {
    srand(time(NULL));
    int degreeOfPolynomial, numberOfPoints;
    double xMin, xMax;
    cin >> degreeOfPolynomial >> numberOfPoints >> xMin >> xMax;

    double *coefficientArr = new double[degreeOfPolynomial+1];

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    for(int i = 0; i < 10; i++)
        cout << calculateIntegral(degreeOfPolynomial, numberOfPoints, coefficientArr, xMin, xMax) << endl;

    return 0;
}