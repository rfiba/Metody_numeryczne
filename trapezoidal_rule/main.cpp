/*
 * @author: rfiba April 2018
 * Trapeizoidal Rule
 */
#include <iostream>
#include <cmath>

using namespace std;

double calculatePolynomial(int degreeOfPolynomial, double * coefficientArr, double x)
{
    double result = coefficientArr[0];

    for(int i = 1; i <= degreeOfPolynomial; i++)
        result += coefficientArr[i]*pow(x,i);

    return result;
}

int main() {
    int degreeOfPolynomial, numberOfPoints, numberOfTrapezoids;

    double *coefficientArr = new double[degreeOfPolynomial+1];

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    return 0;
}