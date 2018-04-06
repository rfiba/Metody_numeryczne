#include <iostream>
#include <cmath>

using namespace std;

double sumOfArrayXPower(int numberOfPoints, double *arrX, double power)
{
    double result = 0;
    if(power > 1){
        for(int i = 0; i < numberOfPoints; i++)
            result += pow(arrX[i], power);
    }
    else
    {
        if(power == 0)
            return numberOfPoints;

        for(int i = 0; i < numberOfPoints; i++)
            result += arrX[i];
    }
    return result;
}

double sumOfArrayYPower(int numberOfPoints, double *arrX, double *arrY, double power)
{
    double result = 0;
    if(power > 1){
        for(int i = 0; i < numberOfPoints; i++)
            result += arrY[i]*pow(arrX[i], power);
    }
    else
    {
        if(!power){
            for(int i = 0; i < numberOfPoints; i++)
                result += arrY[i];
        }
        else
        {
            for(int i = 0; i < numberOfPoints; i++)
                result += arrY[i]*arrX[i];
        }

    }
    return result;
}

void do_Lest_Squares_Equations(double *arrX, double *arrY, double **resultArr, int numberOfPoints, int degreeOfPolynomial)
{

    for(int i = 0; i <= degreeOfPolynomial; i++)
    {
        for(int j = 0; j <= degreeOfPolynomial; j++)
            resultArr[i][j] = sumOfArrayXPower(numberOfPoints, arrX, j+i);
    }

    for(int i = 0; i <= degreeOfPolynomial; i++)
        resultArr[i][degreeOfPolynomial+1] = sumOfArrayYPower(numberOfPoints, arrX, arrY, i);
}

int main() {
    int numberOfPoints, degreeOfPolynomial;
    cin >> numberOfPoints >> degreeOfPolynomial;

    double *arrX, *arrY, **resultArr;
    arrX = new double[numberOfPoints];
    arrY = new double[numberOfPoints];
    resultArr = new double*[degreeOfPolynomial+1];
    for(int i = 0; i <= degreeOfPolynomial ; i++)
        resultArr[i] = new double[degreeOfPolynomial+2];

    for(int i = 0; i < numberOfPoints; i++)
        cin >> arrX[i] >> arrY[i];

    do_Lest_Squares_Equations(arrX, arrY, resultArr, numberOfPoints, degreeOfPolynomial);
    for(int i = 0; i <= degreeOfPolynomial; i++)
    {
        for(int j = 0; j <= degreeOfPolynomial; j++)
            cout << "a" << j << " " << resultArr[i][j] << " ";

        cout << "= " << resultArr[i][degreeOfPolynomial+1] << endl;
    }

    delete []arrX;
    delete []arrY;
    for(int i = 0; i <= degreeOfPolynomial; i++)
        delete []resultArr[i];
    delete []resultArr;
    return 0;
}