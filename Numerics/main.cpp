#include <iostream>
using namespace std;
//#define BINARY_CONVERT
//#define TEACHER_BINARY_CONVERT
#define TEACHER_HEX_CONVERT
//#define HEX_CONVERT
#define DELTA 55
void main()
{
	setlocale(LC_ALL, "");
	int i;
#ifdef BINARY_CONVERT
	const int n = 16;
	int bin_arr[n];
	int number;
	cout << "Программа перевода десятичного числа в двоичное" << endl;
	cout << "Введите десятичное число: "; cin >> number;
	int temp = number;
	for (i = 0; temp > 0; i++)
	{
		bin_arr[i] = temp % 2;
		temp /= 2;
	}
	cout << "Число " << number << " в двоичной системе равно: ";
	for (i = i - 1; i >= 0; i--)
		cout << bin_arr[i];
	cout << "b" << endl;
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
		else cout << char(hex_arr[j] + DELTA);
	}
	cout << endl;
#endif // HEX_CONVERT
	int decimal; //Хранит десятичное число, введенное пользователем
	cout << "Введите десятичное число: "; cin >> decimal;
#ifdef TEACHER_BINARY_CONVERT

	const int n_bin = 32; // Максимальная возможная разрядность двоичного числа
	bool binary[n_bin] = {};
	int k = 0;
	for (; decimal; decimal >>= 1) binary[k++] = decimal & 1;
	for (--k; k >= 0; k--)
	{
		cout << binary[k];
		if(k % 8 == 0) cout << " ";
		if (k % 4 == 0) cout << " ";
	}
	cout << endl;
#endif // TEACHER_BINARY_CONVERT
#ifdef TEACHER_HEX_CONVERT

	const int n_hex = 8; // Максимальная возможная разрядность двоичного числа
	char hex[n_hex] = {};
	int k = 0;
	for (; decimal; decimal >>= 4)
	{
		hex[k] = decimal & 15;
		hex[k++] += hex[k] < 10 ? 48 : 55;
	}
	for (--k; k >= 0; k--)
	{
		cout << hex[k];
		//cout << char(hex[k] < 10 ? hex[k] + 48 : hex[k] + 55);
		//if (k % 8 == 0) cout << " ";
		//if (k % 4 == 0) cout << " ";
	}
	cout << endl;
#endif // TEACHER_HEX_CONVERT
}