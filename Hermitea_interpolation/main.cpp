#include <iostream>

using namespace std;

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