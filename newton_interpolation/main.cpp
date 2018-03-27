#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x;
    double y;
};

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

double calculateNewtonInterpolation(int n, Point *arr, double x, int *differenceArr)
{

    double result = 0, tmp = 1;
    for(int i = 0; i < n; i++)
    {

        tmp = 1.;
        for(int j = 0; j < i ; j++)
            tmp *= (x - arr[j].x);

        result += tmp * differenceArr[i];

    }

    return result;
}

double** createDifferentQuotientArray(int n, Point *arr, bool i) {
    double **array = new double *[n];
    for (int i = 0; i < n; i++) {
        array[i] = new double[n];
        array[i][0] = arr[i].y;
    }

    for (int i = 1; i < n; i++)
        for (int j = i; j < n; j++)
            array[j][i] = (array[j][i-1] - array[j-1][i - 1]) / (arr[j].x - arr[j - i].x);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " " << array[i][j];
        }
        cout << endl;
    }

    return array;
}

int main() {
    int n;
    cin >> n;
    Point *arr =  new Point[n];
    double ** array;
    for(int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;

    array = createDifferentQuotientArray(n,arr,1);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << " " << array[i][j];
        }
        cout << endl;
    }
    delete arr, array;

    return 0;
}