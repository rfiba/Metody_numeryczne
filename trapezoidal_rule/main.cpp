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

double calculateAreaOfTrapezoid(double aBase, double bBase, double height)
{
    return ((aBase+bBase)*height)/2;
}

double calculateArea(int degreeOfPolynomial, int numberOfTrapezoids, int beginOfRange, int endOfRange, double * coefficientArr)
{
    double legOfTrapezoid = (endOfRange-beginOfRange)/numberOfTrapezoids;
    double result = 0, beginPoint = beginOfRange;
    for(int i = 0; i < numberOfTrapezoids;i++)
    {
        result += calculateAreaOfTrapezoid(calculatePolynomial(degreeOfPolynomial, coefficientArr, beginPoint),
        calculatePolynomial(degreeOfPolynomial, coefficientArr, beginPoint+legOfTrapezoid),
        legOfTrapezoid);
    }
    return result;
}

int main() {
    int degreeOfPolynomial, numberOfPoints, numberOfTrapezoids, beginOfRange, endOfRange;

    double *coefficientArr = new double[degreeOfPolynomial+1];
    cin >> degreeOfPolynomial >> numberOfTrapezoids >> beginOfRange >> endOfRange;

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    cout << calculateArea(degreeOfPolynomial, numberOfTrapezoids, beginOfRange, endOfRange, coefficientArr) << endl;
    return 0;
}