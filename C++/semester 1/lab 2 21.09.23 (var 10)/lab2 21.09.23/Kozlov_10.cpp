#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	float a, b;
	int c, x;
	bool f;
	cout << "введите промежуток [a, b] (a, b - натуральные числа)\na = ";
	cin >> a;
	if (!(a > 0) or (a*10 != (int)a*10) )
	{
		cout << "недопустимое значение а";
		return 0;
	}
	cout << "b = ";
	cin >> b;
	if (!((b > 0) and (b > a)) or (b * 10 != (int)b * 10))
	{
		cout << "недопустимое значение b";
		return 0;
	}

	cout << "числа, делящиеся на каждую из своих цифр: " << endl;
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