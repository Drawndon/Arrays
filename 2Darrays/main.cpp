#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	const int rows = 5;
	const int cols = 4;
	int arr[rows][cols];
	int s = 0;
	int min_el = INT_MAX;
	int max_el = INT_MIN;
	// Формирую массив из случайных чисел, считаю сумму элементов и ищу минимальный и максимальный элемент
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
			s += arr[i][j];
			if (arr[i][j] < min_el) min_el = arr[i][j];
			if (arr[i][j] > max_el) max_el = arr[i][j];
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

	
		int shift;
		cout << "Насколько элементов сдвинуть двумерный массив? Введите число: "; cin >> shift;

		// Сдвиг влево
		cout << "Сдвинул влево построчно на " << shift << endl;
		for (int k = 0; k < shift % cols; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				int buffer = arr[i][0];
				for (int j = 1; j < cols; j++)
				{
					arr[i][j - 1] = arr[i][j];
				}
				arr[i][cols - 1] = buffer;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		// Сдвиг вправо
		cout << "Сдвинул вправо построчно на " << shift << endl;
		for (int k = 0; k < shift % cols; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				int buffer = arr[i][cols - 1];
				for (int j = cols - 1; j > 0; j--)
				{
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][0] = buffer;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}


	// Сохраняю двумерный массив в одномерный
	int d_arr[rows * cols];
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++, k++)
		{
			d_arr[i + k] = arr[i][j];
		}
	}
	// Сдвигаю влево
	for (int i = 0; i < shift % (rows * cols); i++)
	{
		int t = d_arr[0];
		for (int j = 1; j < rows * cols; j++)
		{
			d_arr[j - 1] = d_arr[j];
		}
		d_arr[rows * cols - 1] = t;
	}
	
	// Сохраняю одномерный массив обратно в двумерный
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = d_arr[i + k++];
		}
	}

	cout << endl << "Вывод сдвинутого влево змейкой двумерного массива на экран" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// Подготовительные манипуляции для сортировки двумерного массива

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

	// Сохраняю одномерный массив обратно в двумерный
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = d_arr[i + k++];
		}
	}
	// Вывожу отсортированный двумерный массив
	cout << "Вывод отсортированного двумерного массива на экран" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Сумма элементов массива: " << s << endl;
	cout << "Среднее арифметическое элементов массива: " << (double)s / (rows * cols) << endl;
	cout << "Минимальное значение: " << min_el << endl << "Максимальное значение: " << max_el << endl;
	
}