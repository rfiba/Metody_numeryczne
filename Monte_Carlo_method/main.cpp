#include <iostream>
#include <cmath>

using namespace std;

double doPolynomial(int degreeOfPolynomial, double * coefficientArr, double x)
{
    double result = coefficientArr[0];

    for(int i = 1; i <= degreeOfPolynomial; i++)
        result += coefficientArr[i]*pow(x,i);

    return result;
}

int main() {
    int degreeOfPolynomial;
    double minimumInRange, maximumInRange, beginOfRange, endOfRange;
    cin >> degreeOfPolynomial >> minimumInRange >> maximumInRange >> beginOfRange >> endOfRange;

    double *coefficientArr = new double[degreeOfPolynomial+1];

    for (int i = 0; i <= degreeOfPolynomial; i++)
        cin >> coefficientArr[i];

    cout << doPolynomial(degreeOfPolynomial, coefficientArr, 5) << endl;

    return 0;
}