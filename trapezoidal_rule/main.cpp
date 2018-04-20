/*
 * @author: rfiba April 2018
 * Trapeizoidal Rule
 * Input:
 * [Degree of Polynomial] [Number of trapezoids] [Begin of range] [end of range]
 * [coefficients from a0 to an]
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
    double legOfTrapezoid = (double)(endOfRange-beginOfRange)/numberOfTrapezoids;
    double result = 0, beginPoint = beginOfRange, valueOfEndPoint;
    double valueOfBeginPoint = calculatePolynomial(degreeOfPolynomial, coefficientArr, beginPoint);

    for(int i = 0; i < numberOfTrapezoids;i++)
    {
        valueOfEndPoint = calculatePolynomial(degreeOfPolynomial, coefficientArr, beginPoint+legOfTrapezoid);
        result += calculateAreaOfTrapezoid(valueOfBeginPoint, valueOfEndPoint, legOfTrapezoid);
        valueOfBeginPoint = valueOfEndPoint;
        beginPoint += legOfTrapezoid;
    }

    return result;
}

int main() {
    int degreeOfPolynomial, numberOfTrapezoids, beginOfRange, endOfRange;

    cin >> degreeOfPolynomial >> numberOfTrapezoids >> beginOfRange >> endOfRange;
    double *coefficientArr = new double[degreeOfPolynomial+1];

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    cout << calculateArea(degreeOfPolynomial, numberOfTrapezoids, beginOfRange, endOfRange, coefficientArr) << endl;
    return 0;
}