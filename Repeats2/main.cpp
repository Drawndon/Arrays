#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	const int rows = 5;
	const int cols = 5;
	int arr[rows][cols];

	// �������� ������ �� ��������� �����
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	// ������ �������������� ������
	cout << "�������������� ������" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// ���������������� ����������� ��� ���������� ���������� �������
	// �������� ��������� ������ � ����������
	int d_arr[rows * cols];
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			d_arr[i + k++] = arr[i][j];
		}
	}

	// �������� ���������� ������
	for (int j = 0; j < rows * cols; j++)
	{
		int buffer;
		for (int k = j + 1; k < rows * cols; k++)
		{
			if (d_arr[k] < d_arr[j])
			{
				buffer = d_arr[j];
				d_arr[j] = d_arr[k];
				d_arr[k] = buffer;
			}
		}
	}

	cout << endl;
	// ������ ���������� ���������� � ������ �� �����
	int count = 1, step = 1;
	for (int j = 0; j < rows * cols; j += step)
	{
		int l = step;
		while (l < rows * cols)
		{
			if (d_arr[j] == d_arr[l++])
			{
				count++;
			}
		}
		cout << "����� �� �������: " << d_arr[j] << "\t" << "���������� ��������: " << count << endl;
		step = count;
		count = 0;
	}
	cout << endl;	
}