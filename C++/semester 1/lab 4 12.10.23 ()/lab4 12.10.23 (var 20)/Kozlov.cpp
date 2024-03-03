#include <iostream>;
#include <ctime>;
using namespace std;

void var_1(int** matrix, int* n)
{
	bool flag = false;

	//����� ������� �� ��������
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
			cout << "����� ������� �� ��������, �� ���������� ������������� ���������: " << j + 1 << endl;
			break;
		}	
	}
	if (!flag)
		cout << "� ������� ��� ��������, �� ���������� ������������� ���������" << endl;
}

void var_2(int** matrix, int* n)
{
	int i_pos = *n / 2, j_pos = *n / 2, pos = 1;

	cout << "\n����� ������� �� ������ �� ������� ������ ������� �������, ������ ��� ������:" << endl;

	for (int x = 1; x < *n; x++)
	{
		//����� ������� �����������
		for (int j = 0; j < x; j++)
		{
			cout << matrix[i_pos][j_pos] << " ";
			j_pos += pos;
		}

		//����� ������� �������������
		for (int i = 0; i < x; i++)
		{
			cout << matrix[i_pos][j_pos] << " ";
			i_pos -= pos;
		}

		//����� ��������� ������
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
	cout << "������� ������ �������: ";
	cin >> n;

	while (!(n >= 3 && n <= 101) || n % 2 == 0)
	{
		cout << "������������ �������� (3<=n<=101,  n - ��������); ��������� ����: ";
		cin >> n;
	}

	int** matrix = new int* [n] {};
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n] {};

	cout << "\n�������� ������ ����� ���������:\n1. ���� � ����������\n2. ��������� ��������� �����\n0. �����\n\n������� �������: ";
	cin >> var;

	while (!(var == 1 or var == 2 or var == 0))
	{
		cout << "�������� ����; ������� ������� ������: ";
		cin >> var;
	}
	switch (var)
	{
	case 1:
		//���� � ����������
		cout << "������� �������� �������: ";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> matrix[i][j];
		break;

	case 2:
		//��������� ��������� �����
		srand(time(NULL));

		//���� ���������� ��������� �����
		int a, b;
		cout << "������� ������� ��������� [a, b], �������� ������ ������������ �������� �������\na = ";
		cin >> a;
		cout << "b = ";
		cin >> b;

		//�������� ������������ ����������
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

	cout << "�������� �������: " << endl;
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