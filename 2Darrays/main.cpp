#include <iostream>
#include <ctime>
#include <climits>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	const int rows = 3;
	const int cols = 3;
	int arr[rows][cols];
	int s = 0;
	int min_el = INT_MAX;
	int max_el = INT_MIN;
	// �������� ������ �� ��������� �����, ������ ����� ��������� � ��� ����������� � ������������ �������
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
			s += arr[i][j];
			if (arr[i][j] < min_el) min_el = arr[i][j];
			if (arr[i][j] > max_el) max_el = arr[i][j];
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

	
		int shift;
		cout << "��������� ��������� �������� ��������� ������? ������� �����: "; cin >> shift;
		cout << "����� �����" << endl;
	
		// ���������������� ����������� ��� ���������� ���������� �������
		// �������� ��������� ������ � ����������
	int d_arr[rows * cols];
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++, k++)
		{
			d_arr[i + k] = arr[i][j];
		}
	}
	cout << "������ ���������� ������ �� ����������" << endl;
	for (int i = 0; i < rows * cols; cout << d_arr[i] << "\t", i++)
	// ������� �����
	//int t;
	for (int i = 0; i < shift % (rows * cols); i++)
	{
		int t = d_arr[0];
		for (int j = 1; j < cols; j++)
		{
			d_arr[j - 1] = d_arr[j];
		}
		d_arr[rows * cols - 1] = t;
	}
	cout << endl;
	// �������� ���������� ������ ������� � ���������
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = d_arr[i + k++];
		}
	}

	cout << "����� ���������� ����� ���������� ������� �� �����" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
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

	// �������� ���������� ������ ������� � ���������
	for (int i = 0, k = 0; i < rows; i++, k -= 1)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = d_arr[i + k++];
		}
	}
	// ������ ��������������� ��������� ������
	cout << "����� ���������������� ���������� ������� �� �����" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "����� ��������� �������: " << s << endl;
	cout << "������� �������������� ��������� �������: " << (double)s / (rows * cols) << endl;
	cout << "����������� ��������: " << min_el << endl << "������������ ��������: " << max_el << endl;
	//#endif //2D_ARRAY_SORT		
}