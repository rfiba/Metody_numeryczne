#include <iostream>

using namespace std;

struct Point{
    double x;
    double y;
};

double lagrangeInterpolation(Point *arr, double x, int numberOfPoints)
{
    double y = 0;

    for(int i = 0; i < numberOfPoints; i++)
    {
        double tmp = 1;
        for (int j = 0; j < numberOfPoints; j++) {
            if (j != i)
                tmp *= (x - arr[j].x) / (arr[i].x - arr[j].x);
        }
        y += tmp * arr[i].y;
    }
    return y;
}
int main() {
    int n;
    cin >> n;
    Point *arr =  new Point[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    cout << lagrangeInterpolation(arr, 5, 3) << endl;
    system("pause");
    return 0;
}