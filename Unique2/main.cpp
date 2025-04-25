#include <iostream>
#include <ctime>
using namespace std;
using std::cout;
using std::cin;
#define TEACHER_UNIQUE
//#define UNIQUE

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
#ifdef UNIQUE

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
#endif // UNIQUE
#ifdef TEACHER_UNIQUE

	const int ROWS = 3;
	const int COLS = 4;
	int arr_n[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool unique;
			do
			{
				arr_n[i][j] = rand() % (ROWS * COLS);
				unique = true;
				for (int k = 0; k <= i; k++)
				{
					for (int l = 0; l < (k < i ? COLS : j); l++)
					{
						if (arr_n[i][j] == arr_n[k][l])
						{
							unique = false;
							break;
						}
					}
					if (!unique) break;
				}
			} while (!unique);
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr_n[i][j] << "\t";
		}
		cout << endl;
	}
#endif // TEACHER_UNIQUE
}