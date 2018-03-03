/*
 Newton-Raphson
 rfiba March 2018
 */
#include <iostream>
#include<cmath>
using namespace std;


const double precision = 0.000001;

double calculateRoot(double root)
{
    double sideA = 1, sideB = root;

    while(abs(sideA-sideB)>=precision)
    {
        sideA = (sideA+sideB)/2.;
        sideB = root/sideA;
    }

    return sideA;

}

int main() {
    double root;
    cout << "Get number" << endl;
    cin >> root;
    cout << calculateRoot(root) << endl;

    return 0;
}