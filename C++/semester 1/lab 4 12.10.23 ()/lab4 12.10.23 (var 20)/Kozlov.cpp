#include <iostream>;
#include <ctime>;
using namespace std;

void var_1(int** matrix, int* n)
{
	bool flag = false;

	//обход матрицы по столбцам
	for (int j = 0; j < *n; j++)
	{
		for (int i = 0; i < *n; i++)
		{
			if (matrix[i][j] > 0)
			{
				flag = false;
				break;
			}
			else
				flag = true;
		}

		if (flag)
		{
			cout << "номер первого из столбцов, не содержащих положительных элементов: " << j + 1 << endl;
			break;
		}	
	}
	if (!flag)
		cout << "в матрице нет столбцов, не содержащих положительных элементов" << endl;
}

void var_2(int** matrix, int* n)
{
	int i_pos = *n / 2, j_pos = *n / 2, pos = 1;

	cout << "\nобход матрицы из центра по спирали против часовой стрелки, первый ход вправо:" << endl;

	for (int x = 1; x < *n; x++)
	{
		//обход спирали вертикально
		for (int j = 0; j < x; j++)
		{
			cout << matrix[i_pos][j_pos] << " ";
			j_pos += pos;
		}

		//обход спирали горизонтально
		for (int i = 0; i < x; i++)
		{
			cout << matrix[i_pos][j_pos] << " ";
			i_pos -= pos;
		}

		//вывод последней строки
		if (x == *n - 1)
		{
			pos *= -1;
			for (int j = 0; j <= x; j++)
			{
				cout << matrix[i_pos][j_pos] << " ";
				j_pos += pos;
			}
		}

		pos *= -1;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int var, n;
	cout << "введите размер матрицы: ";
	cin >> n;

	while (!(n >= 3 && n <= 101) || n % 2 == 0)
	{
		cout << "недопустимое значение (3<=n<=101,  n - нечетное); повторите ввод: ";
		cin >> n;
	}

	int** matrix = new int* [n] {};
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n] {};

	cout << "\nвыберите формат ввода элементов:\n1. ввод с клавиатуры\n2. генерация случайных чисел\n0. выход\n\nвведите вариант: ";
	cin >> var;

	while (!(var == 1 or var == 2 or var == 0))
	{
		cout << "неверный ввод; введите вариант заново: ";
		cin >> var;
	}
	switch (var)
	{
	case 1:
		//ввод с клавиатуры
		cout << "введите элементы массива: ";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> matrix[i][j];
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

		//проверка правильности промежутка
		if (a > b)
		{
			a = a + b;
			b = a - b;
			a = a - b;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = rand() % (b + 1 - a) + a;
		break;
	case 0:
		return 0;
	}

	cout << "исходная матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (matrix[i][j] < 0)
				cout << matrix[i][j] << " ";
			else
				cout << " " << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	var_1(matrix, &n);
	var_2(matrix, &n);
}