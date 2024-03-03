#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	float x, e, f, res;
	int cnt = 1;

	cout << "введите x: ";
	cin >> x;
	if (!((x < 1) and (x > -1)))
	{
		cout << "недопустимое значение x";
		return 0;
	}

	cout << "введите E: ";
	cin >> e;
	if (!((e < 0.1) and (e > 0)))
	{
		cout << "недопустимое значение эпсилона";
		return 0;
	}

	f = x * 0.5;
	res = 1 + f;
	for (float n = 3; ((f >= e) or (f <= -e)); n += 2)
	{
		f *= x * ((n - 2) / (n + 1));

		if (cnt == 0)
		{
			res += f;
			cnt = 1;
		}
		else
		{
			res -= f;
			cnt = 0;
		}
	}
	cout << "sqrt(1 + " << x << ") = " << res;
	return 0;
}