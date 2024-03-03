#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

int q1(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". ��� ����� C++?\n 1) ���� ����������������\n 2) ������������ �������\n 3) �������\n 4) ��������� ��������";
	char key;
	cout << "\n��� �����: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "��� ������ ��������; ������� ������� ������: ";
		cin >> key;
	}

	switch (key)
	{
	case '1':
		correct = true;
		break;

	default:
		correct = false;
		break;
	}

	if (correct)
	{
		cnt++;
		cout << "\n�����! ���������� ����� � \"���� ����������������\"." << endl << endl;
	}
	else
		cout << "�������... ����� ����������������" << endl << endl;
	return cnt;
}

int q2(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". ����� �������� ������������ ��� ������ ������ � C++?\n 1) >>\n 2) << \n 3) <=\n 4) >= ";
	char key;
	cout << "\n��� �����: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "��� ������ ��������; ������� ������� ������: ";
		cin >> key;
	}

	switch (key)
	{
	case '2':
		correct = true;
		break;

	default:
		correct = false;
		break;
	}

	if (correct)
	{
		cnt++;
		cout << "\n�����! ���������� ����� � \"<<\"." << endl << endl;
	}
	else
		cout << "�������... ����� ����������������" << endl << endl;

	return cnt;
}

int q3(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". ����� �������� ������������ ��� ����� ������ � C++?\n 1) >> \n 2) <<\n 3) <=\n 4) >= ";
	char key;
	cout << "\n��� �����: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "��� ������ ��������; ������� ������� ������: ";
		cin >> key;
	}

	switch (key)
	{
	case '1':
		correct = true;
		break;

	default:
		correct = false;
		break;
	}

	if (correct)
	{
		cnt++;
		cout << "\n�����! ���������� ����� � \">>\"." << endl << endl;
	}
	else
		cout << "�������... ����� ����������������" << endl << endl;

	return cnt;
}

int q4(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". ����� ��� ������ ������������ ��� �������� ����� ����� � C++?\n 1) float\n 2) double\n 3) int\n 4) char";
	char key;
	cout << "\n��� �����: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "��� ������ ��������; ������� ������� ������: ";
		cin >> key;
	}

	switch (key)
	{
	case '3':
		correct = true;
		break;

	default:
		correct = false;
		break;
	}

	if (correct)
	{
		cnt++;
		cout << "\n�����! ���������� ����� � \"int\"." << endl << endl;
	}
	else
		cout << "�������... ����� ����������������" << endl << endl;

	return cnt;
}

int q5(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". ����� �������� ������������ ��� ���������� �������� � C++?\n 1) const\n 2) define\n 3) constant\n 4) con";
	char key;
	cout << "\n��� �����: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "��� ������ ��������; ������� ������� ������: ";
		cin >> key;
	}

	switch (key)
	{
	case '1':
		correct = true;
		break;

	default:
		correct = false;
		break;
	}

	if (correct)
	{
		cnt++;
		cout << "\n�����! ���������� ����� � \"const\"." << endl << endl;
	}
	else
		cout << "�������... ����� ����������������" << endl << endl;

	return cnt;
}

int main()
{
	int sum = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n��� �����: ";
	cin >> key;\`

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "��� ������ ��������; ������� ������� ������: ";
		cin >> key;
	}

	switch (key)
	{
	case '1':
		correct = true;
		break;

	default:
		correct = false;
		break;
	}

	string numbers = "12345";

	for (int i =1; i < 6; i++)
	{
		srand(time(NULL));
		int r = rand() % (6 - i);
		switch (numbers[r])
		{
		case '1':
			sum +=q1(i);
			break;
		case '2':
			sum += q2(i);
			break;
		case '3':
			sum += q3(i);
			break;
		case '4':
			sum += q4(i);
			break;
		case '5':
			sum += q5(i);
			break;
		}
		numbers.erase(r, 1);
	}

	cout << "���� �������\n��� �������� ����: " << sum << endl;

}