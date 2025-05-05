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
	int p1, p2, p3, p4, p5, p6;
	p1 = arr[0][0] * arr[1][1] * arr[2][2];
	p2 = arr[1][0] * arr[2][1] * arr[0][2];
	p3 = arr[0][1] * arr[1][2] * arr[2][0];
	p4 = arr[0][2] * arr[1][1] * arr[2][0];
	p5 = arr[0][1] * arr[1][0] * arr[2][2];
	p6 = arr[2][1] * arr[1][2] * arr[0][0];
	int s1 = p1 + p2 + p3;
	int s2 = p4 + p5 + p6;
	cout << "Determinant: " << s1 - s2 << endl;
}