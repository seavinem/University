#include <iostream>
using namespace std;

//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	const int nmax = 10;// max ������
//	int n;// �������� ������ �������
//	int a[nmax];
//	int s = 0;
//	cout << "������� ������ �������\n";
//	cin >> n;
//	cout << "������� ������\n";
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//		s += a[i];
//	cout << "����� ��������� ������� = " << s << endl;
//}

//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	int Flag = -1;
//	const int nmax = 10;// max ������
//	int n;// �������� ������ �������
//	int a[nmax];
//	int X;
//	cout << "������� ������ �������\n";
//	cin >> n;
//	srand(time(NULL));
//	cout << "���������� ������ ��������� �����\n";
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 100;
//		cout << a[i] << endl;
//	}
//	cout << "������� �����, ������� ����� ������\n";
//	cin >> X;
//	for (int i = 0; i < n; i++)
//		if (a[i] == X)
//		{
//			Flag = i;
//			break;
//		}
//	if (Flag == -1)
//		cout << "����� �� �������\n"<< endl;
//	else
//		cout << "����� " << X << " �������, ��� ������ = " << Flag << endl;
//}

//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	/*����� �������� ����� ������������� ������� � �������*/
//	const int nmax = 30;
//	int b[nmax], n;
//	int max_el, max_kol, i, j, kol;
//	cout << "������� ������ �������\n";
//	cin >> n;
//	cout << "������� �������� �������\n";
//	for (i = 0; i < n; i++)
//		cin >> b[i];
//	max_el = b[0];
//	max_kol = 1;
//	for (i = 0; i < n; i++)
//	{
//		kol = 1;
//		for (j = i + 1; j < n; j++)
//			if (b[i] == b[j])
//				kol++;
//		if (kol > max_kol)
//		{
//			max_kol = kol;
//			max_el = b[i];
//		}
//	}
//	if (max_kol == 1)
//		cout << "� ������� ��� �������������\n";
//	else
//		cout << max_el << " ����������� " << max_kol << " ���\n";
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <stdio.h>
//#include <time.h>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, ".1251");
//
//	const int Nmax = 20; // ������������ ���������� �����������
//	int N, // �������� ���������� �����������
//		K; // ���������� ���������
//
//	cout << "������� ���������� �����������" << endl;
//	cin >> N;
//	cout << "������� ���������� ���������" << endl;
//	cin >> K;
//
//	int a[Nmax]; //����, ��������� ������������
//	srand(time(NULL));
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << "���������� " << i + 1 << "-�� ����������:" << endl;
//		int sum = 0; //����
//		for (int j = 0; j < K; j++)
//		{
//			double x = rand() % 15;
//			double y = rand() % 15;
//			cout << "���������� " << j + 1 << "-�� ��������: x="
//				<< x << " y=" << y << "\t";
//			double r = sqrt(x * x + y * y);
//			cout << "R =" << r << "\t";
//			if (r <= 10)
//			{
//				cout << "���� = "<< (int)(11 - r) << endl;
//				sum = sum + (11 - r);
//			}
//			else 
//				cout << "���� = 0" << endl;
//		}
//		a[i] = sum;
//		cout << "���� = " << sum << endl;
//	}
//
//	int Max = 0; //������������ ���������� �����
//	int imax = 1; //����� ���������� 
//
//	for (int i = 0; i < N; i++)
//		if (a[i] > Max)
//		{
//			Max = a[i];
//			imax = i + 1;
//		}
//
//	cout << "������ ��������� � " << imax << "-�� ���������� = " << Max << endl;
//	return 0;
//}


int main()
{
	setlocale(LC_ALL, "ru");

	const int nmax = 30;
	int a[nmax], n;
	long i, j;
	cout << "������� ������ �������\n";
	cin >> n;
	cout << "������� �������� �������\n";
	for (i = 0; i < n; i++)
		cin >> a[i];

	int x;
	for (i = 1; i < n; i++)
	{
		// ���� ��������, i-����� �������
		x = a[i];
		// ����� ����� �������� � ������� ������������������
		for (j = i - 1; j >= 0 && a[j] > x; j--) //�������� �������� ������
			a[j + 1] = a[j];
		a[j + 1] = x; // ������� ��������
	}
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
}