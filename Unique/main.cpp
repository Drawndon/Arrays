#include <iostream>
#include <ctime> //чтобы использовать функцию time
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0)); // Чтобы случайные числа были при каждом запуске разные
	const int size = 10;
	int arr[size];
	int i = 0, n;
	while (i < size)
	{
		n = rand() % 10 + 70;
		bool is_unique = true;
		for (int j = 0; j < size; j++)
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
	cout << "Массив из десяти элементов с уникальными случайными числами в диапазоне от 70 до 80" << endl;
	for (int k = 0; k < size; k++)
	{
		cout << arr[k] << "\t";
	}
	cout << endl;
}