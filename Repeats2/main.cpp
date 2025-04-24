#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	const int rows = 5;
	const int cols = 5;
	int arr[rows][cols];

	// Формирую массив из случайных чисел
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	// Вывожу сформированный массив
	cout << "Сформированный массив" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// Подготовительные манипуляции для сортировки двумерного массива
	// Сохраняю двумерный массив в одномерный
	int d_arr[rows * cols];
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			d_arr[i + k++] = arr[i][j];
		}
	}

	// Сортирую одномерный массив
	for (int j = 0; j < rows * cols; j++)
	{
		int buffer;
		for (int k = j + 1; k < rows * cols; k++)
		{
			if (d_arr[k] < d_arr[j])
			{
				buffer = d_arr[j];
				d_arr[j] = d_arr[k];
				d_arr[k] = buffer;
			}
		}
	}

	cout << endl;
	// Считаю количество повторений и вывожу на экран
	int count = 1, step = 1;
	for (int j = 0; j < rows * cols; j += step)
	{
		int l = step;
		while (l < rows * cols)
		{
			if (d_arr[j] == d_arr[l++])
			{
				count++;
			}
		}
		cout << "Число из массива: " << d_arr[j] << "\t" << "Количество повторов: " << count << endl;
		step = count;
		count = 0;
	}
	cout << endl;	
}