#include<iostream>

using namespace std;

void prepareMatrices(int numberOfXs, double **arrX, double **lowerMatrix, double** diagonalMatrix, double** upperMatrix)
{
	for (int i = 0; i < numberOfXs; i++)
		diagonalMatrix[i][i] = arrX[i][i];

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < i; j++)
			lowerMatrix[i][j] = arrX[i][j];
	}

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = i+1; j < numberOfXs; j++)
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


void reverseDiagonalMatrix(int numberOfXs, double **diagonalMatrix, double **diagonalReverseMatrix)
{
	for (int i = 0; i < numberOfXs; i++)
		diagonalReverseMatrix[i][i] = 1 / diagonalMatrix[i][i];
}

double** sumLowerUpperMatrices(int numberOfXs, double **arrX)
{
	double** result = arrX;
	for (int i = 0; i < numberOfXs; i++)
		result[i][i] = 0;

	return result;
}

double** multiplyMatrices(int numberOfXs, double **toMultiplyA, double **toMultiplyB)
{
	double** result = new double*[numberOfXs];
	for (int i = 0; i < numberOfXs; i++)
		result[i] = new double[numberOfXs];

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < numberOfXs; j++)
			result[i][j] = 0;
	}

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < numberOfXs; j++)
		{
			for (int k = 0; k < numberOfXs; k++)
				result[i][j] += toMultiplyA[i][k] * toMultiplyB[k][j];
		}
	}
	return result;
}

double** minusMatrix(int numberOfXs, double** matrix)
{
	double** result = matrix;
	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < numberOfXs; j++)
			result[i][j] = -result[i][j];
	}

	return matrix;
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
	double **diagonalReverseMatrix = new double*[numberOfXs];
	for (int i = 0; i < numberOfXs; i++)
	{
		arrX[i] = new double[numberOfXs];
		lowerMatrix[i] = new double[numberOfXs];
		upperMatrix[i] = new double[numberOfXs];
		diagonalMatrix[i] = new double[numberOfXs];
		diagonalReverseMatrix[i] = new double[numberOfXs];
	}

	for (int i = 0; i < numberOfXs; i++)
	{
		for (int j = 0; j < numberOfXs; j++)
		{
			cin >> arrX[i][j];
			lowerMatrix[i][j] = 0;
			upperMatrix[i][j] = 0;
			diagonalMatrix[i][j] = 0;
			diagonalReverseMatrix[i][j] = 0;
		}
	}

	prepareMatrices(numberOfXs, arrX, lowerMatrix, diagonalMatrix, upperMatrix);
	showMatrix(numberOfXs, lowerMatrix);
	cout << endl << endl;
	showMatrix(numberOfXs, upperMatrix);
	cout << endl << endl;
	showMatrix(numberOfXs, diagonalMatrix);
	cout << endl << endl;
	reverseDiagonalMatrix(numberOfXs, diagonalMatrix, diagonalReverseMatrix);
	showMatrix(numberOfXs, diagonalReverseMatrix);
	cout << endl << endl;
	double ** tmp = sumLowerUpperMatrices(numberOfXs, arrX);
	showMatrix(numberOfXs, tmp);
	cout << endl << endl;
	showMatrix(numberOfXs, multiplyMatrices(numberOfXs, minusMatrix(numberOfXs, diagonalReverseMatrix), tmp));
	system("pause");

	
	return 0;
}