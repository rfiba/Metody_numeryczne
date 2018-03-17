#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x;
    double y;
};

double f(double x)
{
    return pow(x,3);//pow(x,4)*3 - pow(x,3) + pow(x,2)*2 -x +3;
}

double calculateDifferenceQuotient(int n, Point *arr)
{

    double result = 0, tmp = 1;
    for(int i = 0; i <= n; i++) {
        tmp = 1.;
        for (int j = 0; j <= n; j++)
            if (i != j)
                tmp *= arr[i].x - arr[j].x;


        result += arr[i].y / (tmp);

    }
    return result;
}

double calculateNewtonInterpolation(int n, Point *arr, double x)
{

    double result = 0, tmp = 1;
    for(int i = 0; i < n; i++)
    {

        tmp = 1.;
        for(int j = 0; j < i ; j++)
            tmp *= (x - arr[j].x);

        //tmp *= calculateDifferenceQuotient(i, arr);

        result += tmp * calculateDifferenceQuotient(i, arr);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    Point *arr =  new Point[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        //arr[i].y = f(arr[i].x);
    }

    for(int i = 0; i < n; i++)
        calculateDifferenceQuotient(i, arr);

    for(int i = -5; i <= 5; i++)
        cout << "f("<< i << ") = " << calculateNewtonInterpolation(5,arr,i) << endl;

    cout << "real: " << endl;
    for(int i =-5; i <= 5; i++ )
        cout << "f(" << i << ") = " << f(i) << endl;

    return 0;
}