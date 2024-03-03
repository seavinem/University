#include <iostream>
#include <ctime>
using namespace std;

void n1()
{
	srand(time(0));
	const int N = 10, K = 8;
	int arr[N][K]{}, min = arr[0][0], max = arr[0][0], imin = 0, imax = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			arr[i][j] = rand()%10;
	}
	cout << "начальный массив" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << arr[i][j] << "\t";
		cout << "\n";
	}
	
	for (int j = 0; j < K; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				imax = i;
			}
			if (arr[i][j] <= min)
			{
				min = arr[i][j];
				imin = i;
			}
		}
	}

	cout << "\nmax = " << max  << " строка = " << imax + 1 << "\tmin = " << min << " строка = " << imin + 1 << endl;

	

	if ((max == min) or (imax == imin))
		cout << "нечего менять";
	else
	{
		int c;
		for (int j = 0; j < K; j++)
		{
			c = arr[imax][j];
			arr[imax][j] = arr[imin][j];
			arr[imin][j] = c;

		}
		
		cout << "\nизмененный массив" << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K; j++)
				cout << arr[i][j] << "\t";
			cout << "\n";
		}
	}

}

void n2()
{
	const int N = 6;
	int A[N], B[2][N];
	int k = 1;
	bool flag;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	B[0][0] = A[0];
	B[1][0] = 1;

	for (int i = 1; i < N; i++)
	{
		flag = true;
		while (flag)
		{
			for (int j = 0; j < k; j++)
			{
				if (A[i] == B[0][j])
				{
					B[1][j]++;
					flag = false;
				}
			}
			if (flag)
			{
				k++;
				B[0][k - 1] = A[i];
				B[1][k - 1] = 1;
				flag = false;
			}
		}
	}

	flag = true;
	int k1 = k - 1;
	int c;
	while (k1 > 0 and flag)
	{
		flag = false;
		for (int i = 0; i < k1; i++)
		{
			if (B[1][i] < B[1][i + 1])
			{
				c = B[1][i];
				B[1][i] = B[1][i + 1];
				B[1][i + 1] = c;

				c = B[0][i];
				B[0][i] = B[0][i + 1];
				B[0][i + 1] = c;

				flag = true;
			}
		}
		k1--;
	}

	for (int j = 0; j < k; j++)
		cout << "элемент " << B[0][j] << " встречается " << B[1][j] << " раз" << "\n";
}

int main()
{
	setlocale(LC_ALL, "ru");
	
	n1();
	n2();
}