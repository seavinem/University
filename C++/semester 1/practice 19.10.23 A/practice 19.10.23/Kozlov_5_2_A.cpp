#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void A1()
{
	string str, newStr, a, b;
	cout << "������� ������: ";
	getline(cin, str);
	while (str.empty())
	{
		cout << "������������ ��������, ��������� ����: ";
		getline(cin, str);
	}

	cout << "������� ������, � �������� ����� ���������� ���������: ";
	getline(cin, a);
	while (a.empty() or str.find(a) == -1 or a == " ")
	{
		cout << "������������ ��������, ��������� ����: ";
		getline(cin, a);
	}
	
	cout << "������� ������, ������� ����� ������������� ���������: ";
	getline(cin, b);
	while (b.empty() or str.find(b) == -1 or b == " ")
	{
		cout << "������������ ��������, ��������� ����: ";
		getline(cin, b);
	}
	
	int ia = str.find(a); int ib = str.rfind(b);
	newStr = str.substr(ia, ib - ia + 1);
	
	cout << "\n���������� ���������: " << newStr << endl;
}

void A2()
{
	string str, newStr = "";
	int letter = 0, cnt4 = 0, cnt5 = 0;
	bool flag = true;
	
	cout << "������� ������: ";
	getline(cin, str);
	while (str.empty())
	{
		cout << "������������ ��������, ��������� ����: ";
		getline(cin, str);
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ' && flag) {
			newStr += ' ';
			flag = false;
		}
		else if (str[i] != ' ') {
			newStr += str[i];
			flag = true;
		}
	}

	for (int i = 0; i < newStr.size(); i++) {
		if (newStr[i] != ' ') {
			letter++;
		}

		if (newStr[i] == ' ' || i == newStr.size() - 1)
		{
			if (letter == 4)
				cnt4++;
			else if (letter == 5)
				cnt5++;
			letter = 0;
		}
	}

	cout << "\n���������� ���������������� ����: " << cnt4 << "\t���������� ������������� ����: " << cnt5 << endl;

	if (cnt4 > cnt5)
		cout << "���������������� ���� ������" << endl;
	else if (cnt4 < cnt5)
		cout << "������������� ���� ������" << endl;
	else if (cnt4 == 0 && cnt5 == 0)
		cout << "� ������ ��� �� ����������������, �� ������������ ����" << endl;
	else if (cnt4 == cnt5)
		cout << "���������� ���������������� ���� ����� ���������� ������������" << endl;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "A (1)" << endl;
	A1();
	cout << "\nA (2)" << endl;
	A2();
}