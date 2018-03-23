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

void createDifferentQuotientArray(int n, Point *arr)
{
    double **array = new double*[2*n-1];
    for(int i = 0; i < 2*n-1; i++)
        array[i] = new double[n];
    //double array[5][5];

    for(int i = 0, j = 0; i < 2*n-1; i+=2, j++)
        array[i][0] = arr[j].y;


    for(int i = 1, k = 2*n-1; i < n; i++, k--)
    {
        for(int j = i, t=i; j < k; j+=2, t++)
        {
            cout << "dla " << j << " " << i << endl;
            printf("%f - %f / %f - %f", array[j+1][i-1], array[j-1][i-1], arr[t].x, arr[t-i].x);
            cout << endl;
            array[j][i] = (array[j+1][i-1]-array[j-1][i-1])/(arr[t].x-arr[t-i].x);
            cout << array[j][i] << endl;
        }
    }
    cout << "po" << endl;
}

int main() {
    int n;
    cin >> n;
    Point *arr =  new Point[n];
    int *differenceArr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
    //for(int i = 0; i < n; i++)
      //  differenceArr[i] = calculateDifferenceQuotient(i, arr);

    createDifferentQuotientArray(n,arr);
    //for(int i = -5; i <= 5; i++)
      //  cout << "f("<< i << ") = " << calculateNewtonInterpolation(n,arr,i, differenceArr) << endl;

    return 0;
}