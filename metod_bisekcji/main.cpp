/*
Bisection method for quadratic function y
rfiba - March 2018
 */
#include <iostream>
#include <cmath>

using namespace std;

const double precision = 0.0000001;

double calculateValueOfFunction(int aFactor, int bFactor, int cFactor, double point)
{

    return aFactor*pow(point,2) + bFactor*point + cFactor;
}

double doBisection(int aFactor, int bFactor, int cFactor, double beginOfInterval, double endOfInterval)
{
    double result = (beginOfInterval+endOfInterval)/2;
    double valueOfResult = calculateValueOfFunction(aFactor,bFactor,cFactor,result);
    if(abs(beginOfInterval-endOfInterval) <= precision)
        return result;

    if(calculateValueOfFunction(aFactor,bFactor,cFactor,beginOfInterval)*valueOfResult < 0)
    {
        doBisection(aFactor, bFactor, cFactor, beginOfInterval, result);
    }else if(valueOfResult*calculateValueOfFunction(aFactor,bFactor,cFactor,endOfInterval) < 0)
    {
        doBisection(aFactor, bFactor, cFactor, result, endOfInterval);
    }

}

int main()
{
    int aFactor,bFactor, cFactor, beginOfInterval, endOfInterval;

    cout << "Get a, b and c factor" << endl;
    cin >> aFactor >> bFactor >> cFactor;
    cout << "Get endpoints of interval" << endl;
    cin >> beginOfInterval >> endOfInterval;
    cout << doBisection(aFactor,bFactor,cFactor,beginOfInterval, endOfInterval) << endl;

    return 0;
}