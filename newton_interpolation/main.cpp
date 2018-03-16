#include <iostream>

struct Point{
    int x;
    int y;
};


double calculateDifferenceQuotient(int n, Point *arr)
{
    double result = 0;
    for(int i = 0; i < n; i++)
    {
        double tmp = 1;
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            tmp *= (arr[i].x - arr[j].x);
        }
        result += arr[i].y / tmp;
    }

    return result;
}



int main() {

    return 0;
}