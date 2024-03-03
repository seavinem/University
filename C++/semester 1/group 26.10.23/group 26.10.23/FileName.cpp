#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

int q1(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". Что такое C++?\n 1) Язык программирования\n 2) Операционная система\n 3) Браузер\n 4) Текстовый редактор";
	char key;
	cout << "\nВаш выбор: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "Нет такого варианта; введите вариант заново: ";
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
		cout << "\nВерно! Правильный ответ — \"Язык программирования\"." << endl << endl;
	}
	else
		cout << "Неверно... учите программирование" << endl << endl;
	return cnt;
}

int q2(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". Какой оператор используется для вывода данных в C++?\n 1) >>\n 2) << \n 3) <=\n 4) >= ";
	char key;
	cout << "\nВаш выбор: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "Нет такого варианта; введите вариант заново: ";
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
		cout << "\nВерно! Правильный ответ — \"<<\"." << endl << endl;
	}
	else
		cout << "Неверно... учите программирование" << endl << endl;

	return cnt;
}

int q3(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". Какой оператор используется для ввода данных в C++?\n 1) >> \n 2) <<\n 3) <=\n 4) >= ";
	char key;
	cout << "\nВаш выбор: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "Нет такого варианта; введите вариант заново: ";
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
		cout << "\nВерно! Правильный ответ — \">>\"." << endl << endl;
	}
	else
		cout << "Неверно... учите программирование" << endl << endl;

	return cnt;
}

int q4(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". Какой тип данных используется для хранения целых чисел в C++?\n 1) float\n 2) double\n 3) int\n 4) char";
	char key;
	cout << "\nВаш выбор: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "Нет такого варианта; введите вариант заново: ";
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
		cout << "\nВерно! Правильный ответ — \"int\"." << endl << endl;
	}
	else
		cout << "Неверно... учите программирование" << endl << endl;

	return cnt;
}

int q5(int i)
{
	bool correct;
	int cnt = 0;
	cout << i << ". Какой оператор используется для объявления констант в C++?\n 1) const\n 2) define\n 3) constant\n 4) con";
	char key;
	cout << "\nВаш выбор: ";
	cin >> key;

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "Нет такого варианта; введите вариант заново: ";
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
		cout << "\nВерно! Правильный ответ — \"const\"." << endl << endl;
	}
	else
		cout << "Неверно... учите программирование" << endl << endl;

	return cnt;
}

int main()
{
	int sum = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\nВаш выбор: ";
	cin >> key;\`

	while (!(key == '1' || key == '2' || key == '3' || key == '4' || key == '5'))
	{
		cout << "Нет такого варианта; введите вариант заново: ";
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

	cout << "Тест пройден\nВаш итоговый балл: " << sum << endl;

}