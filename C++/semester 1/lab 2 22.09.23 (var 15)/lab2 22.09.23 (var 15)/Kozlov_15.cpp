#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n;
	unsigned int a, b, c;
	cout << "N - ����� ������ ����� ���������\n������� N: ";
	cin >> n;
	while ( !(n >= 0) or (n*10 != (int)n*10) )
	{
		cout << "������������ �������� N\n������� N: ";
		cin >> n;
	}
	if (n > 46)
	{
		cout << "������������ ���������� ����� ��������� ����� ����� 46" << endl;
		n = 46;
	}

	a = 0;
	b = 1;
	if (n == 1)
		cout << a << endl;
	else if (n == 2)
		cout << a << endl << b << endl;
	else if (n > 3)
	{
		cout << a << endl << b << endl;

		for (int i = 0; i < n; i++)
		{
			c = a + b;
			a = b;
			b = c;
			cout << c << endl;
		}
	}
	
	return 0;
}