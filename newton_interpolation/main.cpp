#include <iostream>

struct Point{
    int x;
    int y;
};


double calculateDifferenceQuotient(int n, Point *arr)
{
    double result = 0, tmp;
    for(int i = 0; i < n; i++)
    {
        tmp = 1;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            tmp *= (arr[i].x - arr[j].x);
        }
        result += arr[i].y / tmp;
    }

    return result;
}

double calculateNewtonInterpolation(int n, Point *arr, double x)
{
    double result = arr[0].y, tmp;
    for(int i = 1; i < n; i++)
    {
        tmp = 1;
        for(int j = 0; j < i; j++)
            tmp *= (x-arr[j].x);
        tmp *= calculateDifferenceQuotient(i, arr);

        result += tmp;
    }
    return result;
}

int main() {

    return 0;
}