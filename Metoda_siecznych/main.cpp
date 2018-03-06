#include <iostream>
#include <cmath>

using namespace std;

const double precision = 0.0000001;


double calculateValueOfFunction(int numberOfFactors, double *factors, double point)
{
    double result = 0;
    for(int i = 0; i < numberOfFactors-1;i++)
        result += factors[i] * point;

    result += factors[numberOfFactors-1];
    return result;
}

double calculateValueOfFunction(int aFactor, int bFactor, int cFactor, double point)
{
    return aFactor*pow(point,2) + bFactor*point + cFactor;
}

/*double doSecantMethod(int numberOfFactors, double *factors,double previousValue, double value)
{

    double valueOfFunctionForValue = calculateValueOfFunction(numberOfFactors, factors, value);
    double valueOfFunctionForPreviousValue = calculateValueOfFunction(numberOfFactors, factors, previousValue);

    if(abs(valueOfFunctionForValue) < precision)
        return value;

    double result = value - ((valueOfFunctionForValue * (value-previousValue))/(valueOfFunctionForValue - valueOfFunctionForPreviousValue));
    doSecantMethod(numberOfFactors, factors, value, result);
}*/

double doSecantMethod(int aFactor, int bFactor, int cFactor, double previousValue, double value)
{

    double valueOfFunctionForValue = calculateValueOfFunction(aFactor, bFactor, cFactor, value);
    double valueOfFunctionForPreviousValue = calculateValueOfFunction(aFactor, bFactor, cFactor, previousValue);

    if(abs(valueOfFunctionForValue) < precision)
        return value;

    double result = value - (((valueOfFunctionForValue * (value-previousValue)) / (valueOfFunctionForValue - valueOfFunctionForPreviousValue)));
    doSecantMethod(aFactor, bFactor, cFactor, value, result);
}

int main() {
    int aFactor,bFactor, cFactor, beginOfInterval, endOfInterval;

    cout << "Get a, b and c factor" << endl;
    cin >> aFactor >> bFactor >> cFactor;
    cout << "Get endpoints of interval" << endl;
    cin >> beginOfInterval >> endOfInterval;
   cout << doSecantMethod(aFactor,bFactor, cFactor, beginOfInterval, endOfInterval);
    /*int numberOfFactors;
    double beginOfInterval, endOfInterval;
    cin >> numberOfFactors;
    double *factors = new double[numberOfFactors];
    for(int i  = 0; i < numberOfFactors; i++)
        cin >>  factors[i];
    cin >> beginOfInterval >> endOfInterval;
    cout <<doSecantMethod(numberOfFactors, factors, beginOfInterval, endOfInterval)<< endl;
    */
    return 0;
}