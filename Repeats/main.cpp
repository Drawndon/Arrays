#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
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
}