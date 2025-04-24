#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	const int rows = 5;
	const int cols = 5;
	int arr_2d[rows][cols];

	int arr[rows * cols];
	int i = 0, n;
	// Формирую одномерный массив случайных чисел размером rows * cols
	while (i < rows * cols)
	{
		n = rand() % 100;
		bool is_unique = true;
		for (int j = 0; j < rows * cols; j++)
		{
			if (n == arr[j])
			{
				is_unique = false;
				break;
			}
		}
		if (!is_unique)
		{
			continue;
		}
		else { arr[i] = n; i++; }
	}


	// Сохраняю одномерный массив обратно в двумерный
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			arr_2d[i][j] = arr[i + k++];
		}
	}
	// Вывожу двумерный массив
	cout << "Вывод двумерного массива с уникальными элементами на экран";
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr_2d[i][j] << "\t";
		}
		cout << endl;
	}
}