#include <iostream>
#include <ctime>
using namespace std;
//#define UGLY_REPEATS2
//#define REPEATS2
#define REPEATS2_AS_ONE_DIM

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	const int rows = 4;
	const int cols = 4;
	int arr[rows][cols];

	// Формирую массив из случайных чисел
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
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
	cout << endl;
#ifdef UGLY_REPEATS2
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
#endif // UGLY_REPEATS2


#ifdef REPEATS2
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			bool met_before = false;
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < (k == i ? j : cols); l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						met_before = true;
						break;
					}
					if (met_before) break;
				}
			}
			if (met_before) continue;
			int count = 0;
			for (int k = i; k < rows; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < cols; l++)
				{
					if (arr[i][j] == arr[k][l]) count++;
				}
			}
			if (count) cout << "Значение " << arr[i][j] << " повторяется " << count << " раз." << endl;
		}
	}
#endif // REPEATS2
#ifdef REPEATS2_AS_ONE_DIM
	//Это вариант работает для статического массива
	for (int i = 0; i < rows * cols; i++)
	{
		bool met_before = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[0][i] == arr[0][j])
			{
				met_before = true;
				break;
			}
		}
		if (met_before) continue;
		int count = 0;
		for (int j = i + 1; j < rows * cols; j++)
		{
			if (arr[0][i] == arr[0][j]) count++;
		}
		if (count) cout << "Значение " << arr[0][i] << " повторяется " << count << " раз" << endl;
	}
#endif // REPEATS2_AS_ONE_DIM

}