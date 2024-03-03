#include <iostream>
#include <ctime>
using namespace std;

//вариант 22
//количество различных элементов
void var22_1(double nums[], int& n)
{
	setlocale(LC_ALL, "ru");
	int k_el, kol = 0;

	for (int i = 0; i < n; i++)
	{
		k_el = 0;
		for (int j = 0; j < n; j++)
			if (nums[i] == nums[j])
				k_el++;
		if (k_el == 1)
			kol++;
	}
	cout << "\n1. количество различных элементов - " << kol << endl;
}

//произведение элементов массива, расположенных до минимального по модулю элемента
void var22_2(double nums[], int& n)
{
	setlocale(LC_ALL, "ru");
	int ind_min = 0;
	double mult = 1, min;

	//нахождение минимального по модулю элемента
	min = abs(nums[0]);
	for (int i = 1; i < n; i++)
	{
		if (abs(nums[i]) <= min)
		{
			min = abs(nums[i]);
			ind_min = i;
		}
	}

	if (ind_min == 0)
		cout << "2. минимальный по модулю элемент - первый в массиве" << endl;
	else
	{
		for (int i = 0; i < ind_min; i++)
			mult *= nums[i];
		cout << "2. произведение элементов массива, расположенных до последнего минимального по модулю элемента, - " << mult << endl;
	}
}

//преобразование массива
void var22_3(double nums[], int& n)
{
	setlocale(LC_ALL, "ru");
	int ind_neg = 0, ind_0 = 0;
	double c;

	//ind_neg - индекс, в который смещается отрицательный элемент, ind_0 - индекс, в который смещается нулевой элемент 
	// (т.к. нулевые элементы следуют после отрицаельных, то при увеличении индекса отрицательного числа, увеличивается и индекс нулевого) 

	cout << "\nисходный массив:\t";
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";

	for (int i = 0; i < n; i++) 
	{
		//смещение отрицательных элементов
		if (nums[i] < 0) 
		{
			for (int j = i; j > ind_neg; j--) 
			{
				c = nums[j];
				nums[j] = nums[j - 1];
				nums[j- 1] = c;
			}
			ind_neg++;
			ind_0++;
		}
		//смещение нулевого элемента
		else if (nums[i] == 0) 
		{
			for (int j = i; j > ind_0; j--) 
			{
				c = nums[j];
				nums[j] = nums[j - 1];
				nums[j - 1] = c;
			}
			ind_0++;
		}
	}

	cout << "\nполученный массив:\t";
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	const int nmax = 100;
	int n, var, flag = 0;
	double nums[nmax];

	//вариант 22 ввод
	cout << "вариант 22" << endl;
	cout << "введите количество элементов в массиве: ";
	cin >> n;
	if ((n < 1) or (n > nmax) or (n * 10 != (int)n * 10))
		flag = 1;
	else
	{
		cout << "выберите формат ввода элементов массива (массив из n вещественных элементов):\n1. ввод с клавиатуры\n2. генерация случайных чисел\n\nвведите вариант ввода:" << endl;
		cin >> var;

		switch (var)
		{
		case 1:
			//ввод с клавиатуры
			cout << "введите элементы массива: ";
			for (int i = 0; i < n; i++)
				cin >> nums[i];
			break;

		case 2:
			//генерация случайных чисел
			srand(time(NULL));

			//ввод промежутка случайных чисел
			double a, b;
			cout << "введите границы интервала [a, b], которому должны принадлежать элементы массива\na = ";
			cin >> a;
			cout << "b = ";
			cin >> b;

			//проверка правильности промежутка
			if (a > b)
			{
				a = a + b;
				b = a - b;
				a = a - b;
			}
			for (int i = 0; i < n; i++)
			{
				nums[i] = (b - a) * rand() / (float)RAND_MAX + a;
				cout << nums[i] << " ";
			}
			cout << endl;
			break;
		default:
			flag = 2;
			break;
		}
	}

	if (flag == 0)
	{
		var22_1(nums, n);
		var22_2(nums, n);
		var22_3(nums, n);
	}
	else if (flag == 1)
		cout << "недопустимое количество элементов в массиве" << endl;
	else
		cout << "такого варианта нет" << endl;
}