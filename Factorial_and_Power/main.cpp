#include <iostream>
using namespace std;
//#define FACTORIAL
#define POWER
long long Factorial(int n);
double Power(double a, int b);
void main()
{
	setlocale(LC_ALL, "");
#ifdef FACTORIAL
	int n;
	cout << "Введите число, факториал которого необходимо вычислить: "; cin >> n;
	cout << "Факториал числа " << n << " = " << Factorial(n) << endl;
#endif // FACTORIAL


#ifdef POWER
	double a;
	int b;
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

double Power(double a, int b)
{
	double power;
	if (b == 0) power = 1;
	else if (b < 0)
	{
		a = 1 / a;
		b = -b;
		power = a * Power(a, b - 1);
	}
	else power = a * Power(a, b - 1);
	return power;

}