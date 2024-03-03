#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void A1()
{
	string str, newStr, a, b;
	cout << "введите строку: ";
	getline(cin, str);
	while (str.empty())
	{
		cout << "недопустимое значение, повторите ввод: ";
		getline(cin, str);
	}

	cout << "введите символ, с которого будет начинаться подстрока: ";
	getline(cin, a);
	while (a.empty() or str.find(a) == -1 or a == " ")
	{
		cout << "недопустимое значение, повторите ввод: ";
		getline(cin, a);
	}
	
	cout << "введите символ, которым будет заканчиваться подстрока: ";
	getline(cin, b);
	while (b.empty() or str.find(b) == -1 or b == " ")
	{
		cout << "недопустимое значение, повторите ввод: ";
		getline(cin, b);
	}
	
	int ia = str.find(a); int ib = str.rfind(b);
	newStr = str.substr(ia, ib - ia + 1);
	
	cout << "\nполученная подстрока: " << newStr << endl;
}

void A2()
{
	string str, newStr = "";
	int letter = 0, cnt4 = 0, cnt5 = 0;
	bool flag = true;
	
	cout << "введите строку: ";
	getline(cin, str);
	while (str.empty())
	{
		cout << "недопустимое значение, повторите ввод: ";
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

	cout << "\nколичество четырехбуквенных слов: " << cnt4 << "\tколичество пятибуквенных слов: " << cnt5 << endl;

	if (cnt4 > cnt5)
		cout << "четырехбуквенных слов больше" << endl;
	else if (cnt4 < cnt5)
		cout << "пятибуквенных слов больше" << endl;
	else if (cnt4 == 0 && cnt5 == 0)
		cout << "в строке нет ни четырехбуквенных, ни пятибукенных слов" << endl;
	else if (cnt4 == cnt5)
		cout << "количество четырехбуквенных слов равно количеству пятибукенных" << endl;
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