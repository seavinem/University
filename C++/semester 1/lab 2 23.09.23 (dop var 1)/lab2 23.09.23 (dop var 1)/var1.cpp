#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int a, b, ax, bx, nA = 0, nB = 0, cnt = 0;
	cin >> a;
	cin >> b;

	ax = a;
	while (ax != 0)
	{
		ax = ax / 10;
		nA++;
	}
	bx = b;
	while (bx != 0)
	{
		bx = bx / 10;
		nB++;
	}

	int* arrA = new int[nA], *arrS = new int [nA], * arrB = new int[nB];
	while (a != 0)
	{
		for (int i = 0; i < nA; i++)
		{
			arrA[i] = a % 10;
		}
		a = a / 10;
	}
	while (b != 0)
	{
		for (int i = 0; i < nB; i++)
		{
			arrB[i] = b % 10;
		}
		b = b / 10;
	}

	for (int i = 0; i < nA; i++)
	{
		for (int j = 0; j < nB; i++)
		{
			if (arrA[i] == arrB[j])
			{
				arrS[cnt] = j;
				cnt++;
				break;
			}
		}
	}

	cnt = 0;
	for (int i = 1; i < nA; i++)
	{
		if (arrS[i - 1] > arrS[i])
		{
			cnt++;
		}
	}
	if (cnt == nA - 1)
		cout << "yes";
	else
		cout << "no";
	return 0;
}