/*
 Newton-Raphson
 rfiba March 2018
 */
#include <iostream>
#include<cmath>
using namespace std;


const double precision = 0.000001;

double calculateRoot(double root, double startPoint, double secondPoint)
{
    if(abs(startPoint-secondPoint) <= precision)
        return startPoint;

    calculateRoot(root, (0.5)*(startPoint+(root/startPoint)), startPoint);
}

int main() {
    double root;
    cout << "Get number" << endl;
    cin >> root;
    cout << calculateRoot(root, 1,root) << endl;

    return 0;
}