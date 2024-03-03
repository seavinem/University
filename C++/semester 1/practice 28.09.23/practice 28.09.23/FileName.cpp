#include <iostream>
using namespace std;

//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	const int nmax = 10;// max размер
//	int n;// реальный размер массива
//	int a[nmax];
//	int s = 0;
//	cout << "введите размер массива\n";
//	cin >> n;
//	cout << "введите массив\n";
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int i = 0; i < n; i++)
//		s += a[i];
//	cout << "сумма элементов массива = " << s << endl;
//}

//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	int Flag = -1;
//	const int nmax = 10;// max размер
//	int n;// реальный размер массива
//	int a[nmax];
//	int X;
//	cout << "введите размер массива\n";
//	cin >> n;
//	srand(time(NULL));
//	cout << "генерируем массив случайных чисел\n";
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = rand() % 100;
//		cout << a[i] << endl;
//	}
//	cout << "введите число, которое будем искать\n";
//	cin >> X;
//	for (int i = 0; i < n; i++)
//		if (a[i] == X)
//		{
//			Flag = i;
//			break;
//		}
//	if (Flag == -1)
//		cout << "число не найдено\n"<< endl;
//	else
//		cout << "число " << X << " найдено, его индекс = " << Flag << endl;
//}

//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	/*найти наиболее часто встречающийс€ элемент в массиве*/
//	const int nmax = 30;
//	int b[nmax], n;
//	int max_el, max_kol, i, j, kol;
//	cout << "введите размер массива\n";
//	cin >> n;
//	cout << "введите элементы массива\n";
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
//		cout << "в массиве нет повтор€ющихс€\n";
//	else
//		cout << max_el << " встречаетс€ " << max_kol << " раз\n";
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
//	const int Nmax = 20; // максимальное количество спортсменов
//	int N, // реальное количество спортсменов
//		K; // количество выстрелов
//
//	cout << "¬ведите количество спортсменов" << endl;
//	cin >> N;
//	cout << "¬ведите количество выстрелов" << endl;
//	cin >> K;
//
//	int a[Nmax]; //очки, набранные спортсменами
//	srand(time(NULL));
//
//	for (int i = 0; i < N; i++)
//	{
//		cout << "результаты " << i + 1 << "-го спортсмена:" << endl;
//		int sum = 0; //очки
//		for (int j = 0; j < K; j++)
//		{
//			double x = rand() % 15;
//			double y = rand() % 15;
//			cout << "координаты " << j + 1 << "-го выстрела: x="
//				<< x << " y=" << y << "\t";
//			double r = sqrt(x * x + y * y);
//			cout << "R =" << r << "\t";
//			if (r <= 10)
//			{
//				cout << "ќчки = "<< (int)(11 - r) << endl;
//				sum = sum + (11 - r);
//			}
//			else 
//				cout << "ќчки = 0" << endl;
//		}
//		a[i] = sum;
//		cout << "ќчки = " << sum << endl;
//	}
//
//	int Max = 0; //максимальное количество очков
//	int imax = 1; //номер спортсмена 
//
//	for (int i = 0; i < N; i++)
//		if (a[i] > Max)
//		{
//			Max = a[i];
//			imax = i + 1;
//		}
//
//	cout << "лучший результат у " << imax << "-го спортсмена = " << Max << endl;
//	return 0;
//}


int main()
{
	setlocale(LC_ALL, "ru");

	const int nmax = 30;
	int a[nmax], n;
	long i, j;
	cout << "введите размер массива\n";
	cin >> n;
	cout << "введите элементы массива\n";
	for (i = 0; i < n; i++)
		cin >> a[i];

	int x;
	for (i = 1; i < n; i++)
	{
		// цикл проходов, i-номер прохода
		x = a[i];
		// поиск места элемента в готовой последовательности
		for (j = i - 1; j >= 0 && a[j] > x; j--) //сдвигаем элементы вправо
			a[j + 1] = a[j];
		a[j + 1] = x; // вставка элемента
	}
	for (i = 0; i < n; i++)
		cout << a[i] << endl;
}