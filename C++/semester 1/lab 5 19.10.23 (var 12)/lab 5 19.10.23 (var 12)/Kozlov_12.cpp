#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string replace(string str)
{
	string newStr = str;
	string letters = "eyuioa";

	for (int i = 0; i < newStr.size(); i++)
	{
		if (newStr[i] == ' ')
			newStr[i] = '+';

		if (letters.find(newStr[i]) != -1)
			newStr[i] = toupper(newStr[i]);
	}
	return newStr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str, newStr;
	cout << "������� ������: ";
	getline(cin, str);

	while (str.empty())
	{
		cout << "������� ������: ";
		getline(cin, str);
	}
	
	cout << "\n�������� ������: " << str << "\n����� ������: " << replace(str) << endl;
}