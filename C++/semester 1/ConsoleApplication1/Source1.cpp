#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int k, n, cd;
	cout << "������� ������ ��������: ";
	cin >> k;

	cout << "������� ��������� �����: ";
	cin >> n;

	if (k < 0)
	{
		cout << "���������� ������ ����\n������� ������ ��������: ";
		cin >> k;
	}

	if ((k == 0) and (n == 0))
	{
		cout << "�����: " << (k - n) << endl;
	}
	else if ((k > 0) and (n >= 0))
	{
		cd = k - n;
		while (cd < 0)
		{
			k = k * 2;
			if (k < n)
			{
				k = k * 3;
			}

			cd = k - n;
		}

		cout << "�����: " << cd << endl;

	}
	else
	{
		cout << "���������� ������ ����" << endl;
	}
}

