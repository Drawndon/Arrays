#include <iostream>
using namespace std;
#define ROWS 4  
#define COLS 3
#define tab '\t'
void main()
{
	setlocale(LC_ALL, "");
	int matrix_A[ROWS][COLS];
	int matrix_B[COLS][COLS];
	cout << "Формирую и вывожу матрицы" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			matrix_A[i][j] = rand() % 24 + 1;
	}
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < COLS; j++)
			matrix_B[i][j] = rand() % 24 + 1;
	}
	cout << "Matrix_A" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << matrix_A[i][j] << tab;
		cout << endl;
	}
	cout << "Matrix_B" << endl;
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << matrix_B[i][j] << tab;
		cout << endl;
	}
	int matrix_C[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = 0; k < COLS; k++)
				matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
		}
	}
		for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << matrix_B[i][j] << tab;
		cout << endl;
	}
		cout << "Matrix_C" << endl;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
				cout << matrix_C[i][j] << tab;
			cout << endl;
		}
}