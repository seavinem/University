#include <iostream>
#include <ctime>
using namespace std;

//вариант 2
//сумма элементов с нечетными номерами
void var2_1(double nums2[], int& n2)
{
	setlocale(LC_ALL, "ru");
	double sum = 0;

	for (int i = 0; i < n2; i++)
		if (i % 2 == 0)
			sum += nums2[i];
	cout << "\n\n1. сумма элементов с нечетными номерами = " << sum << endl;
}

//произведение элементов, расположенных между первым и последним отрицательными элементами
void var2_2(double nums2[], int& n2)
{
	setlocale(LC_ALL, "ru");
	int cnt = 0;
	double mult = 1, ind_f = -1, ind_l = -1;

	for (int i = 0; i < n2; i++)
	{
		if (nums2[i] < 0)
		{
			if (cnt == 0)
			{
				ind_f = i;
				cnt = 1;
			}
			else
				ind_l = i;
		}
	}
	if (ind_f + 1 == ind_l)
		cout << "2. первый и последний отрицательные элементамы следуют друг за другом" << endl;
	else if ((ind_f == -1) and (ind_l == -1))
		cout << "2. в массиве нет отрицательных элементов" << endl;
	else if ((ind_f != -1) and (ind_l == -1))
		cout << "2. в массиве только один отрицательный элемент" << endl;
	else
	{
		for (int i = ind_f + 1; i < ind_l; i++)
			mult *= nums2[i];
		cout << "2. произведение элементов, расположенных между первым и последним отрицательными элементами = " << mult << endl;
	}
}

//сжатие массива, заполнение освободившегося места нулями
void var2_3(double nums2[], int& n2)
{
	setlocale(LC_ALL, "ru");
	double c;
	int k = n2 - 1;

	cout << "\nмассив до сжатия:\t";
	for (int i = 0; i < n2; i++)
		cout << nums2[i] << " ";
	cout << endl;
	while (k > 0)
	{
		for (int i = 0; i < k; i++)
			if ((nums2[i] <= 1) and (nums2[i] >= -1))
			{
				c = nums2[i];
				nums2[i] = nums2[i + 1];
				nums2[i + 1] = c;
			}
		k--;
	}
	for (int i = 0; i < n2; i++)
		if ((nums2[i] <= 1) and (nums2[i] >= -1))
			nums2[i] = 0;

	cout << "\nмассив после сжатия:\t";
	for (int i = 0; i < n2; i++)
		cout << nums2[i] << " ";
	cout << endl;
}

//вариант 12
//количество положительных элементов массива
void var12_1(int nums12[], int& n12)
{
	setlocale(LC_ALL, "ru");
	int kol = 0;
	for (int i = 0; i < n12; i++)
		if (nums12[i] > 0)
			kol++;

	if (kol == 0)
		cout << "\n\n1. в массиве нет положительных элементов" << endl;
	else
		cout << "\n\n1. в массиве " << kol << " положительных элементов" << endl;
}

//сумма элементов массива, расположенных после последнего элемента, равного нулю
void var12_2(int nums12[], int& n12)
{
	setlocale(LC_ALL, "ru");
	int ind_0 = -1, sum = 0;

	for (int i = 0; i < n12; i++)
		if (nums12[i] == 0)
			ind_0 = i;

	if (ind_0 == -1)
		cout << "2. в массиве нет ни одного элемента, равного нулю" << endl;
	else if (ind_0 == (n12-1))
		cout << "2. элемент, равный нулю, - последний элемент в массиве" << endl;
	else
	{
		for (int i = (ind_0 + 1); i < n12; i++)
			sum += nums12[i];
		cout << "2. сумма элементов массива, расположенных после последнего элемента, равного нулю = " << sum << endl;
	}
}

//расположение элементовf
void var12_3(int nums12[], int& n12)
{
	setlocale(LC_ALL, "ru");
	cout << "\nисходный массив:\t";
	for (int i = 0; i < n12; i++)
		cout << nums12[i] << " ";

	for (int i = 0; i < n12; i++)
	{
		int c = 0;
		if (nums12[i] > 0)
		{
			for (int j = i; j < n12; j++)
			{
				if ((nums12[i] > nums12[j]) and (nums12[j] > 0))
				{
					c = nums12[i];
					nums12[i] = nums12[j];
					nums12[j] = c;
				}
			}
		}
		else if (nums12[i] < 0)
		{
			for (int j = i; j < n12; j++)
			{
				if ((nums12[i] < nums12[j]) and (nums12[j] < 0))
				{
					c = nums12[i];
					nums12[i] = nums12[j];
					nums12[j] = c;
				}
			}
		}
	}

	cout << "\nполученный массив:\t";
	for (int i = 0; i < n12; i++)
		cout << nums12[i] << " ";
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	const int nmax = 100;
	int n2, n12, var, nums12[nmax];
	double nums2[nmax];
	bool flag = true;

	//вариант 2 ввод
	cout << "вариант 2" << endl;
	cout << "введите количество элементов в массиве: ";
	cin >> n2; 
	if ((n2 <= 0) or (n2 > nmax) or (n2 * 10 != (int)n2 * 10))
	{
		cout << "недопустимое количество элементов в массиве" << endl;
		return 0;
	}
	else
	{
		cout << "выберите формат ввода элементов массива (массив из n вещественных элементов):\n1. ввод с клавиатуры\n2. генерация случайных чисел\n\nвведите вариант ввода:" << endl;
		cin >> var;

		switch (var)
		{
		case 1:
			//ввод с клавиатуры
			cout << "введите элементы массива: ";
			for (int i = 0; i < n2; i++)
				cin >> nums2[i];
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
			if (a > b)
				flag = false;
			else
			{
				for (int i = 0; i < n2; i++)
				{
					nums2[i] = (b - a) * rand() / (float)RAND_MAX + a;
					cout << nums2[i] << " ";
				}
			}
			break;
		default:
			cout << "такого варианта нет" << endl;
			return 0;
			break;
		}
	}

	if (flag)
	{
		var2_1(nums2, n2);
		var2_2(nums2, n2);
		var2_3(nums2, n2);
	}
	else
		cout << "недопустимый промежуток" << endl;

	//выриант 12 ввод
	flag = true;
	cout << "\nвариант 12" << endl;
	cout << "введите количество элементов в массиве: ";
	cin >> n12;
	if (!((n12 > 0) and (n12 <= nmax) and (n12 * 10 == (int)n12 * 10)))
	{
		cout << "недопустимое количество элементов в массиве" << endl;
		return 0;
	}
	else
	{
		cout << "выберите формат ввода элементов массива (массив из n целых элементов):\n1. ввод с клавиатуры\n2. генерация случайных чисел\n\nвведите вариант ввода:" << endl;
		cin >> var;

		switch (var)
		{
		case 1:
			//ввод с клавиатуры
			cout << "введите элементы массива: ";
			for (int i = 0; i < n12; i++)
				cin >> nums12[i];
			break;

		case 2:
			//генерация случайных чисел
			srand(time(NULL));
			//ввод промежутка случайных чисел
			int a, b;
			cout << "введите границы интервала [a, b], которому должны принадлежать элементы массива\na = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			if (a > b)
				flag = false;
			else
			{
				for (int i = 0; i < n12; i++)
				{
					if (a < 0 and b > 0)
						nums12[i] = (b + 2 - a) * rand() / (float)RAND_MAX + a - 1;
					else if (a > 0 and b > 0)
						nums12[i] = (b + 1 - a) * rand() / (float)RAND_MAX + a;
					else
						nums12[i] = (b + 1 - a) * rand() / (float)RAND_MAX + a - 1;
					cout << nums12[i] << " ";
				}
			}
			break;
		default:
			cout << "такого варианта нет" << endl;
			return 0;
			break;
		}
	}

	if (flag)
	{
		var12_1(nums12, n12);
		var12_2(nums12, n12);
		var12_3(nums12, n12);
	}
	else
		cout << "недопустимый промежуток" << endl;
}