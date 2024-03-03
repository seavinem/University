#include <iostream>;
#include <ctime>;
using namespace std;

void var20_1(int** matrix, float** newmatrix, int* n)
{
	int s_i[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int s_j[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < *n; i++) 
	{
		for (int j = 0; j < *n; j++)
		{
			float sum = 0;
			int cnt = 0;
			bool flag = false;

			for (int k = 0; k < 8; k++) 
			{
				int new_i = i + s_i[k];
				int new_j = j + s_j[k];

				if (new_i >= 0 && new_i < *n && new_j >= 0 && new_j < *n) 
				{
					if (matrix[i][j] > matrix[new_i][new_j])
					{
						sum += matrix[new_i][new_j];
						cnt++;
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}
			}

			if (flag)
			{
				newmatrix[i][j] = sum / cnt;
			}
			else
				newmatrix[i][j] = matrix[i][j];
		}
	}

	cout << "матрица, полученная после операции сглаживания для каждого из локальных максимумов:" << endl;
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *n; j++)
			if (newmatrix[i][j] < 0)
				cout << newmatrix[i][j] << " ";
			else
				cout << " " << newmatrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void var20_2(int** matrix, float** newmatrix, int* n)
{
	float sum = 0;
	for (int i = 0; i < *n - 1; i++)
		for (int j = 0; j < *n - 1 - i; j++)
			sum += matrix[i][j];
	cout << "сумма элементов, находящихся выше побочной диагонали исходной матрицы: " << sum << endl;

	sum = 0;
	for (int i = 0; i < *n - 1; i++)
		for (int j = 0; j < *n - 1 - i; j++)
			sum += newmatrix[i][j];
	cout << "сумма элементов, находящихся выше побочной диагонали полученной матрицы: " << sum << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int var, n;
	cout << "введите размер матрицы: ";
	cin >> n;

	while (n < 2)
	{
		cout << "недопустимое значение; повторите ввод: ";
		cin >> n;
	}

	int** matrix = new int* [n] {};
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n] {};

	float** newmatrix = new float* [n] {};
	for (int i = 0; i < n; i++)
		newmatrix[i] = new float[n] {};

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

	cout << "\nисходная матрица:" << endl;
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

	var20_1(matrix, newmatrix,  &n);
	var20_2(matrix, newmatrix, &n);
}