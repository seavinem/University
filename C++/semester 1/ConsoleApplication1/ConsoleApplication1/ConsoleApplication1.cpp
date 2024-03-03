#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int k, n, cd;
	cout << "введите деньги мальчика: ";
	cin >> k;

	cout << "введите стоимость хлеба: ";
	cin >> n;

	if (k<0)
	{
		cout << "невозможно купить хлеб\nвведите деньги мальчика: ";
		cin >> k;
	}
	
	if ((k == 0) and (n == 0))
	{
		cout << "сдача: " << (k - n) << endl;
	}
	else if((k > 0) and (n >= 0))
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

		cout << "сдача: " << cd << endl;			

	}
	else
	{
		cout << "невозможно купить хлеб" << endl;
	}
}

