#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	float a, b;
	int c, x;
	bool f;
	cout << "������� ���������� [a, b] (a, b - ����������� �����)\na = ";
	cin >> a;
	if (!(a > 0) or (a*10 != (int)a*10) )
	{
		cout << "������������ �������� �";
		return 0;
	}
	cout << "b = ";
	cin >> b;
	if (!((b > 0) and (b > a)) or (b * 10 != (int)b * 10))
	{
		cout << "������������ �������� b";
		return 0;
	}

	cout << "�����, ��������� �� ������ �� ����� ����: " << endl;
	for (int i = a; i <= b; i++)
	{
		f = true;
		x = i;
		while (x != 0)
		{
			c = x % 10;
			if ((c == 0) or (i % c != 0))
			{
				f = false;
				break;
			}
			x = x / 10;
		}
		if (f)
		{
			cout << i << endl;
		}
	}
	return 0;
}