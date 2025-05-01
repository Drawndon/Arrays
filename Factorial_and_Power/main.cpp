#include <iostream>
using namespace std;
//#define FACTORIAL
#define POWER
long long Factorial(int n);
long long Power(int a, int b);
void main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	int n;
	cout << "Введите число, факториал которого необходимо вычислить: "; cin >> n;
	cout << "Факториал числа " << n << " = " << Factorial(n) << endl;
#endif // FACTORIAL


#ifdef POWER
	int a, b;
	cout << "Введите число и степень, в которую его необходимо возвести: "; cin >> a >> b;
	cout << "Число " << a << " в степени " << b << " = " << Power(a, b) << endl;
#endif // POWER

}


long long Factorial(int n)
{
	int factorial;
	if (n == 1 || n == 0) factorial = 1;
	else factorial = n * Factorial(n - 1);
	return factorial;
}

long long Power(int a, int b)
{
	long long power;
	if (b == 0) power = 1;
	else power = a * Power(a, b - 1);
	return power;

}