#include <iostream>
#include <ctime>
using namespace std;
//#define REPEATS
#define TEACHER_REPEATS
void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
#ifdef REPEATS

	const int size = 10;
	int arr[size];
	int i = 0;
	while (i < size)
	{
		arr[i++] = rand() % 6;
	}
	cout << "Массив из десяти чисел в диапазоне от 0 до 5, сформирован случайным образом" << endl;
	for (int k = 0; k < size; k++)
	{
		cout << arr[k] << "\t";
	}
	for (int j = 0; j < size; j++)
	{
		int buffer;
		for (int k = j + 1; k < size; k++)
		{
			if (arr[k] < arr[j])
			{
				buffer = arr[j];
				arr[j] = arr[k];
				arr[k] = buffer;
			}
		}
	}
	cout << endl;
	int count = 1, step = 1;
	for (int j = 0; j < size; j += step)
	{
		int l = step;
		while (l < size)
		{
			if (arr[j] == arr[l++])
			{
				count++;
			}
		}
		cout << "Число из массива: " << arr[j] << "\t" << "Количество повторов: " << count << endl;
		step = count;
		count = 0;
	}
	cout << endl;
#endif // REPEATS
#ifdef TEACHER_REPEATS

	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	// Поиск повторений
	for (int i = 0; i < n; i++)
	{
		bool met_before = false; // предположим, что выбранное значение раньше не встречалось,
		// но это нужно проверить
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				met_before = true;
				break;
			}

		}
		if (met_before) continue;
		// Ключевое слово 'continue' прерывает текущую итерацию и переходит к следующей
		int count = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count > 0) cout << "Значение " << arr[i] << " повторяется " << count << " раз\n";
	}
#endif // TEACHER_REPEATS
}