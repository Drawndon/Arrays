#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	int s = 0;
	double average = 0;
	int min_el = INT_MAX, max_el = INT_MIN;
	cout << "Введите пять элементов массива:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (min_el > arr[i])
			min_el = arr[i];
		if (arr[i] > max_el)
			max_el = arr[i];
		s += arr[i];
	}
/*	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (100 - 50) + 50; //ограничили снизу 50 сверху 100
	}*/
	average = (double)s / n;
	cout << endl << "1. Вывод в прямом порядке:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl << "2. Вывод в обратном порядке:" << endl;
	for (int i = n - 1; i > -1; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << endl << "3. Сумма: " << s << endl << "4. Среднее арифметическое: " << average << endl;
	cout << "5. Минимальный элемент: " << min_el << endl << "6. Максимальный элемент: " << max_el << endl;
}