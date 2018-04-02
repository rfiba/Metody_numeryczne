#include <iostream>

using namespace std;

int factorial(int k)
{
    if( k < 2)
        return 1;

    return k*factorial(k-1);
}

double** createDifferentQuotientArray(int n,int * arrD, double *arrX, double *arrY, bool i) {
    double **array = new double *[n];
    for (int i = 0; i < n; i++) {
        array[i] = new double[n];
        array[i][0] = arrY[i-arrD[i]];
    }

    for (int i = 1; i < n; i++){
        for (int j = i; j < n; j++) {
            if((arrX[j] - arrX[j - i]) == 0)
                array[j][i] = (arrY[j - arrD[j - i]]) / factorial(i);
            else
                array[j][i] = (array[j][i - 1] - array[j - 1][i - 1]) / (arrX[j] - arrX[j - i]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= i; j++)
            cout << " " << array[i][j];
        cout << endl;
    }

        return array;

}

void prepareDerivativesArr(int * arrD, double * arrX, int n)
{
    arrD[0] = 0;
    for(int i = 1; i < n; i++)
    {
        if(arrX[i] == arrX[i-1])
            arrD[i] = arrD[i-1] + 1;
        else
            arrD[i] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    double * arrX = new double[n];
    double * arrY = new double[n];
    int * arrD = new int[n];

    for(int i = 0; i < n; i ++) {
        cin >> arrX[i] >> arrY[i];
    }

    arrD[0] = 0;
    for(int i = 1; i < n; i++)
    {
        if(arrX[i] == arrX[i-1])
            arrD[i] = arrD[i-1] + 1;
        else
            arrD[i] = 0;
    }

    createDifferentQuotientArray(n, arrD, arrX, arrY, 1);

    for(int j = 1; j < n; j++)
    {
        for(int i = n - 1; i >= j; i--)
        {
            if(arrD[i] == 0)
                arrY[i] = (arrY[i] - arrY[i-1-arrD[i-1]]) / (arrX[i] - arrX[i-j]);
            else {
                arrY[i] /= j;
                arrD[i]--;
            }
        }
    }



    for(int i = 0; i < n; i++)
        cout << arrY[i] << endl;

    return 0;
}