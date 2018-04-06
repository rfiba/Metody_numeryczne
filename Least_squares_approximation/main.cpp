#include <iostream>

using namespace std;



int main() {
    int numberOfPoints, degreeOfPolynomial;
    cin >> numberOfPoints >> degreeOfPolynomial;

    double *arrX, *arrY, **resultArr;
    arrX = new double[numberOfPoints];
    arrY = new double[numberOfPoints];
    resultArr = new double*[numberOfPoints+1];
    for(int i = 0; i <= numberOfPoints ; i++)
    {
        resultArr[i] = new double[numberOfPoints+1];
    }

    for(int i = 0; i < numberOfPoints; i++)
        cin >> arrX[i] >> arrY[i];

    delete []arrX;
    delete []arrY;
    return 0;
}