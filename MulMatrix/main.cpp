#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
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
			matrix_A[i][j] = rand() % 5 + 1;
	}
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < COLS; j++)
			matrix_B[i][j] = rand() % 5 + 1;
	}
	cout << endl << "Matrix_A" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << matrix_A[i][j] << tab;
		cout << endl;
	}
	cout << endl << "Matrix_B" << endl;
	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << matrix_B[i][j] << tab;
		cout << endl;
	}
	int matrix_C[ROWS][COLS] = { 0 };
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = 0; k < COLS; k++)
				matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
		}
	}

		cout << endl << "A x B = C" << endl;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
				cout << matrix_C[i][j] << tab;
			cout << endl;
		}
}