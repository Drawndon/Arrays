#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	int s = 0;
	double average = 0;
	int min_el = INT_MAX, max_el = INT_MIN;
	cout << "Введите пять элементов массива:" << endl;
	for (int i = 0; i < n; i++)
	{
		//cin >> arr[i];
		arr[i] = rand() % 100;
		if (min_el > arr[i])
			min_el = arr[i];
		if (arr[i] > max_el)
			max_el = arr[i];
		s += arr[i];
	}
	int minRand, maxRand;
	do
	{
		cout << "Введите минимальное случайное число: "; cin >> minRand;
		cout << "Введите максимальное случайное число: "; cin >> maxRand;
		if (minRand > maxRand) cout << "Минимальное должно быть меньше максимального" << endl;
		if (minRand == maxRand) cout << "Числа должны быть разные" << endl;
	} while (minRand >= maxRand);
	/*if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}*/
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand; //ограничили снизу 50 сверху 100
	}
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


	int buf;  // для обмена значениями

	for (int i = 0; i < n; i++) // Счётчик i выбирает элемент, в который нужно поместить минимальное значение
	{
		
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				buf = arr[j];
				arr[j] = arr[i];
				arr[i] = buf;
			}
		}
	}
	for (int i = 0; i < n; i++)  //Вывод отсортированного массива
		cout << arr[i] << "\t";
	cout << endl;
}