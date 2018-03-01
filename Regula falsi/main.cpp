/*
 Regula falsi method
 rfiba March 2018
 */
#include <iostream>
#include <cmath>

using namespace std;

const double precision = 0.0000001;

double calculateValueOfFunction(int aFactor, int bFactor, int cFactor, double point)
{

    return aFactor*pow(point,2) + bFactor*point + cFactor;
}

double doFalsi(int aFactor, int bFactor, int cFactor, double beginOfInterval, double endOfInterval)
{
    double valueOfBegin = calculateValueOfFunction(aFactor, bFactor, cFactor, beginOfInterval);
    double valueOfEnd = calculateValueOfFunction(aFactor, bFactor, cFactor, endOfInterval);
    double result = beginOfInterval - (valueOfBegin/(valueOfEnd-valueOfBegin))*(endOfInterval-beginOfInterval);
    double valueOfResult = calculateValueOfFunction(aFactor,bFactor,cFactor,result);
    if(abs(valueOfResult) <= precision)
        return result;

    if(valueOfBegin*valueOfResult < 0)
    {
        doFalsi(aFactor, bFactor, cFactor, beginOfInterval, result);
    }else if(valueOfResult*valueOfEnd < 0)
    {
        doFalsi(aFactor, bFactor, cFactor, result, endOfInterval);
    }

}

int main()
{
    int aFactor,bFactor, cFactor, beginOfInterval, endOfInterval;

    cout << "Get a, b and c factor" << endl;
    cin >> aFactor >> bFactor >> cFactor;
    cout << "Get endpoints of interval" << endl;
    cin >> beginOfInterval >> endOfInterval;
    cout << doFalsi(aFactor,bFactor,cFactor,beginOfInterval, endOfInterval) << endl;

    return 0;
}