#include <iostream>
using namespace std;
#define BINARY_CONVERT
#define HEX_CONVERT
void main()
{
	setlocale(LC_ALL, "");
#ifdef BINARY_CONVERT
	const int n = 16;
	int arr[n];
	int number, i;
	cout << "Программа перевода десятичного числа в двоичное" << endl;
	cout << "Введите десятичное число: "; cin >> number;
	int temp = number;
	for (i = 0; temp > 0; i++)
	{
		arr[i] = temp % 2;
		temp /= 2;
	}
	cout << "Число " << number << " в двоичной системе равно: ";
	for (i = i - 1; i >= 0; i--)
		cout << arr[i];
	cout << endl;
#endif // BINARY_CONVERT

	
#ifdef HEX_CONVERT
	const int size = 100;
	int hex_arr[size];
	int number_1, remainder;
	i = 0;
	cout << endl << "Программа перевода десятичного числа в шестнадцатиричное" << endl;
	cout << "Введите десятичное число: "; cin >> number_1;
	int temp_1 = number_1;
	while (temp_1 != 0)
	{
		remainder = temp_1 % 16;
		hex_arr[i++] = remainder;
		temp_1 /= 16;

	}
	cout << "Число " << number_1 << " в шестнадцатиричной системе равно: ";
	cout << "0x";
	for (int j = i - 1; j >= 0; j--)
	{
		if (hex_arr[j] < 10)
			cout << hex_arr[j];
		else cout << char(hex_arr[j] + 55);
	}
	cout << endl;
#endif // HEX_CONVERT

}