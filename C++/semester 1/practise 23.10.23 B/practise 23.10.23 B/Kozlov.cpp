#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void A1()
{
	string str, a, b;
	cout << "введите строку: ";
	getline(cin, str);
	while (str.empty())
	{
		cout << "введите строку: ";
		getline(cin, str);
	}

	cout << "введите а: ";
	getline(cin, a);
	while (a.empty() || (str.find(a) == -1 && str.size() == 1) || a == " ")
	{
		cout << "введите a: ";
		getline(cin, a);
	}

	cout << "введите b: ";
	getline(cin, b);
	while (b.empty() || (str.find(b) == -1 && str.size() == 1) || b == " ")
	{
		cout << "введите b: ";
		getline(cin, b);
	}

	while (str.find(b) != -1 && str.find(a) != -1)
	{
		int ia = str.find(a); int ib = str.find(b);
		str = str.erase(ia, ib - ia + 1);
	}
	cout << str << endl;
}

void A2()
{
	const int N = 255;
	string str, newStr, words[N];
	int cnt = 0;
	bool flag = true;
	cout << "введите строку: ";
	getline(cin, str);
	while (str.empty()) {
		cout << "введите строку: ";
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

	flag = true;
	int k = 0, pos;
	for (int i = 0; i < newStr.size(); i++) 
	{
		if (newStr[i] != ' ' && flag)
		{
			if (newStr.find(' ') != -1)
				pos = newStr.find(' ');
			else
				pos = newStr.size() - 1;

			words[k] = newStr.substr(i, pos);
			newStr.erase(i, newStr.find(' '));
			k++;
			flag = false;
		}
		else
			flag = true;
	}

	for (int i = 0; i < k; i++)
	{
		bool lower = ((int)words[i][1] <= 122 && (int)words[i][1] >= 97) || ((int)words[i][1] <= -1 && (int)words[i][1] >= -32);
		if (lower)
			cnt++;
	}
	

	cout << cnt;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << (int)'a' << endl << (int)'z' << endl << (int)'б' << endl << (int)'ю' << endl;;
	//cout << "A (1)" << endl;
	//A1();
	cout << "\nA (2)" << endl;
	A2();
}