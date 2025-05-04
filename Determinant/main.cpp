#include <iostream>
using namespace std;
#define ROWS 3
#define COLS 3
#define tab '\t'
void main()
{
	setlocale(LC_ALL, "");
	int arr[ROWS][COLS];
	cout << "Формирую и вывожу матрицу 3х3" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			arr[i][j] = rand() % 24 + 1;
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			cout << arr[i][j] << tab;
		cout << endl;
	}
}