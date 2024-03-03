#include <iostream>
#include <ctime>
using namespace std;

//������� 22
//���������� ��������� ���������
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
	cout << "\n1. ���������� ��������� ��������� - " << kol << endl;
}

//������������ ��������� �������, ������������� �� ������������ �� ������ ��������
void var22_2(double nums[], int& n)
{
	setlocale(LC_ALL, "ru");
	int ind_min = 0;
	double mult = 1, min;

	//���������� ������������ �� ������ ��������
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
		cout << "2. ����������� �� ������ ������� - ������ � �������" << endl;
	else
	{
		for (int i = 0; i < ind_min; i++)
			mult *= nums[i];
		cout << "2. ������������ ��������� �������, ������������� �� ���������� ������������ �� ������ ��������, - " << mult << endl;
	}
}

//�������������� �������
void var22_3(double nums[], int& n)
{
	setlocale(LC_ALL, "ru");
	int ind_neg = 0, ind_0 = 0;
	double c;

	//ind_neg - ������, � ������� ��������� ������������� �������, ind_0 - ������, � ������� ��������� ������� ������� 
	// (�.�. ������� �������� ������� ����� ������������, �� ��� ���������� ������� �������������� �����, ������������� � ������ ��������) 

	cout << "\n�������� ������:\t";
	for (int i = 0; i < n; i++)
		cout << nums[i] << " ";

	for (int i = 0; i < n; i++) 
	{
		//�������� ������������� ���������
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
		//�������� �������� ��������
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

	cout << "\n���������� ������:\t";
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

	//������� 22 ����
	cout << "������� 22" << endl;
	cout << "������� ���������� ��������� � �������: ";
	cin >> n;
	if ((n < 1) or (n > nmax) or (n * 10 != (int)n * 10))
		flag = 1;
	else
	{
		cout << "�������� ������ ����� ��������� ������� (������ �� n ������������ ���������):\n1. ���� � ����������\n2. ��������� ��������� �����\n\n������� ������� �����:" << endl;
		cin >> var;

		switch (var)
		{
		case 1:
			//���� � ����������
			cout << "������� �������� �������: ";
			for (int i = 0; i < n; i++)
				cin >> nums[i];
			break;

		case 2:
			//��������� ��������� �����
			srand(time(NULL));

			//���� ���������� ��������� �����
			double a, b;
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
		cout << "������������ ���������� ��������� � �������" << endl;
	else
		cout << "������ �������� ���" << endl;
}