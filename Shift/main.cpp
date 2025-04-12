#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	int shift;
	cout << endl << "Введите число, на которое вы хотите сдвинуть элементы массива влево: "; cin >> shift;
	int t;
	for (int i = 0; i < shift % n; i++)
	{
		t = arr[0];
		for (int j = 1; j < n; j++)
		{
			arr[j - 1] = arr[j];
		}
		arr[n - 1] = t;
	}
	cout << endl << "Сдвинутый массив:" << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}