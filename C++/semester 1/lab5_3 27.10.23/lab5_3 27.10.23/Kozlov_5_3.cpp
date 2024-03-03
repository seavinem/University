#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

void problem1()
{
	string str;
	cout << "введите строку: ";
	getline(cin, str);

	while (str.empty())
	{
		cout << "введите строку: ";
		getline(cin, str);
	}

	string newStr = "", answer = "";
	bool flag = false;
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] != ' ') 
		{
			newStr += str[i];
			flag = true;
		}
		if (((str[i] == ' ' && i != 0) || i == str.size() - 1) && flag)
		{
			string word = newStr;
			reverse(newStr.begin(), newStr.end());
			if (word == newStr)
				answer += word + ' ';
			flag = false;
			newStr = "";
		}
	}
	if (answer.empty())
		cout << "слов полиндромов нет" << endl;
	else
		cout << "слова полиндромы: " << answer << endl;;
}

void problem2()
{
	string str;
	cout << "введите римское число: ";
	getline(cin, str);

	while (str.empty())
	{
		cout << "введите римское число: ";
		getline(cin, str);
	}

	vector<int> arabLetters = {1, 5, 10, 50, 100, 500, 1000};
	vector<char> romeLetters = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int ans = 0, indNext, indNow;

	for (int i = 0; i < str.size() - 1; i++)
	{
		for (int l = 0; l < romeLetters.size(); l++)
		{
			if (str[i] == romeLetters[l])
				indNow = l;
			if (str[i+1] == romeLetters[l])
				indNext = l;
		}
			
		if (arabLetters[indNow] < arabLetters[indNext])
			ans -= arabLetters[indNow];
		else 
			ans += arabLetters[indNow];

		if (i == str.size() - 2)
			ans += arabLetters[indNext];
	}
	cout << "арабское число: " << ans << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "C (1)" << endl;
	problem1();
	cout << "C (2)" << endl;
	problem2();
}