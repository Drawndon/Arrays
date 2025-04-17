#include <iostream>
using namespace std;
//#define BINARY_CONVERT
#define HEX_CONVERT
void main()
{
	setlocale(LC_ALL, "");
#ifdef BINARY_CONVERT
	const int n = 16;
	int arr[n];
	int number, i;
	cout << "������� ���������� �����: "; cin >> number;
	int temp = number;
	for (i = 0; temp > 0; i++)
	{
		arr[i] = temp % 2;
		temp /= 2;
	}
	cout << "����� " << number << " � �������� ������� �����: ";
	for (i = i - 1; i >= 0; i--)
		cout << arr[i];
	cout << endl;
#endif // BINARY_CONVERT

	
#ifdef HEX_CONVERT
	const int size = 100;
	char hex_arr[size];
	int number_1, i = 1, remainder;
	cout << "������� ���������� �����: "; cin >> number_1;
	int temp_1 = number_1;
	while (temp_1 != 0)
	{
		remainder = temp_1 % 16;
		if (remainder < 10) remainder += 48;
		else remainder += 55;
		hex_arr[i++] = remainder;
		temp_1 /= 16;

	}
	cout << "����� " << number_1 << " � ����������������� ������� �����: ";
	for (int j = i - 1; j > 0; j--)
		cout << hex_arr[j];
	cout << endl;
#endif // HEX_CONVERT

}