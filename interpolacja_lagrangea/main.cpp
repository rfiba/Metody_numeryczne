#include <iostream>

using namespace std;

double lagrangeInterpolation(double *arrOfX, double *arrOfY, double x, int numberOfPoints)
{
    double y = 0;

    for(int i; i < numberOfPoints; i++)
    {
        double tmp = 1;
        for(int j = 0; j < numberOfPoints; j++)
        {
            if(j!=i)
                tmp = (x - arrOfX[j])/(arrOfX[i]-arrOfX[j]);
        }
        y += tmp * arrOfY[i];
    }

    return y;
}
int main() {
    int n;
    cin >> n;
    double *arrOfX =  new double[n];
    double *arrOfY =  new double[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arrOfX[i] >> arrOfY[i];
    }
    cout << lagrangeInterpolation(arrOfX, arrOfY, 5, 3) << endl;
    system("pause");
    return 0;
}