#include <iostream>
#include <cmath>

using namespace std;

const double precision = 0.1;

double calculateValueOfFunction(int aFactor, int bFactor, int cFactor, double point)
{

    return aFactor*pow(point,2) + bFactor*point + cFactor;
}

double doBisection(int aFactor, int bFactor, int cFactor, int beginOfInterval, int endOfInterval)
{
    double result = (beginOfInterval+endOfInterval)/2;
    int valueOfResult = calculateValueOfFunction(aFactor,bFactor,cFactor,result);
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
    int a,b,c, beginOfInterval, endOfInterval;
    cout << "Get a, b and c factor" << endl;
    cin >> a >> b >> c;
    cout << "Get endpoints of interval" << endl;
    cin >> beginOfInterval >> endOfInterval;
    cout << doBisection(a,b,c,beginOfInterval, endOfInterval) << endl;




    return 0;
}