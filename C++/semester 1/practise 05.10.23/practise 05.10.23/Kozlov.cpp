#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const int N = 5;
	int arr[N], max, min, ind_max = 0, ind_min = 0, c, n = N;

	//���� ��������� �������
	cout << "������� �������� �������: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	max = arr[0]; min = arr[0];
	
	//����� ������� ������������� �������� � ��� �������
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			ind_max = i;
		}
	}
	//����� ���������� ������������ �������� � ��� �������
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
			ind_min = i;
		}
	}
	
	//����� ��������� �������
	cout << "\n�������� ������: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	//������ �������
	if (max == min)
		cout << "\n������������ � ����������� �������� �����, ������ ������, ���������� ������ ��������� ���������" << endl;
	else
	{
		//����� ��������� �������
		c = arr[ind_min];
		arr[ind_min] = arr[ind_max];
		arr[ind_max] = c;

		//����� ����������� �������
		cout << "\n���������� ������: ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";


		//���������
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == max)
			{
				for (int j = i; j < n - 1; j++)
				{
					c = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = c;
				}
				n--;
			}
		}
		cout << "\n���������� ������ ����� ������� ������������ ���������: ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
}