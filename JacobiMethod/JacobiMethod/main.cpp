#include<iostream>

using namespace std;

void prepareMatrices(int numberOfXs, double **arrX, double **lowerMatrix, double** diagonalMatrix, double** upperMatrix)
{
	for (int i = 0, j = 0; i < numberOfXs; i++, j++)
		diagonalMatrix[i][j] = arrX[i][j];

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < i; j++)
			lowerMatrix[i][j] = arrX[i][j];
	}

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = i; j < numberOfXs; j++)
			upperMatrix[i][j] = arrX[i][j];
	}
}

void showMatrix(int numberOfXs, double **toShow)
{
	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < numberOfXs; j++)
			cout << toShow[i][j] << " ";
		cout << endl;
	}
}

void calculateJacobiMethod() {}

int main()
{
	int numberOfXs;
	cin >> numberOfXs;

	double **arrX = new double*[numberOfXs];
	double **lowerMatrix = new double*[numberOfXs];
	double **upperMatrix = new double*[numberOfXs];
	double **diagonalMatrix = new double*[numberOfXs];
	for (int i = 0; i < numberOfXs; i++)
	{
		arrX[i] = new double[numberOfXs];
		lowerMatrix[i] = new double[numberOfXs];
		upperMatrix[i] = new double[numberOfXs];
		diagonalMatrix[i] = new double[numberOfXs];
	}

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < numberOfXs; j++)
		{
			cin >> arrX[i][j];
			lowerMatrix[i][j] = 0;
			upperMatrix[i][j] = 0;
			diagonalMatrix[i][j] = 0;
		}
	}

	prepareMatrices(numberOfXs, arrX, lowerMatrix, diagonalMatrix, upperMatrix);
	showMatrix(numberOfXs, lowerMatrix);
	cout << endl << endl;
	showMatrix(numberOfXs, upperMatrix);
	cout << endl << endl;
	showMatrix(numberOfXs, diagonalMatrix);
	cout << endl << endl;
	system("pause");
	return 0;
}