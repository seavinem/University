#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	ifstream input ("A1.txt");
	string stroka, word, num1Str;
	int num1, num2, count = 0, numRow, numCol, sum = 0, element = 1, numAnswer;
	bool flagNum = false, flagSearch = false;

	if (!input) { 
		cout << "Ошибка открытия входного файла\n";
		return 1;
	}
	if (!input.good()) {
		cout << "Входной файл пуст" << endl;
		return 1;
	}
	
	input >> numRow >> numCol;

	int** matrix = new int* [numRow];
	for (int i = 0; i < numRow; i++)
		matrix[i] = new int[numCol];

	for (int i = 0; i < numRow; i++)
		for (int j = 0; j < numCol; j++) {
			if (!(input >> matrix[i][j])) {
				cout << "Недостаточно данных";
				return 1;
			}
		}

	input >> word;
	input.ignore();
	getline(input, stroka);
	input >> num1 >> num2;


	for (int i = 0; i < numRow; i++)
		sum += matrix[i][i];

	num1Str = to_string(num1);
	if (stroka.find(num1Str) != -1) {
		while (stroka.find(num1Str) != -1) {
			stroka.erase(stroka.find(num1Str), num1Str.size());
			count++;
		}
	}

	for (int j = 0; j < numCol && !flagSearch; j++)
		for (int i = 0; i < numRow; i++, element++) {
			if (element == num1 + num2)
			{
				numAnswer = matrix[i][j];
				flagNum = true;
				flagSearch = true;
			}
		}

	input.close();


	ofstream output("A2.txt");

	if (!output) {
		cout << "Ошибка открытия выходного файла\n";
		return 1;
	}

	output << sum << endl;
	output << count << endl;
	if (flagNum)
		output << numAnswer;
	else
		output << "Нет";

	output.close();
	
	for (int i = 0; i < numRow; i++)
		delete[]matrix[i];
	delete[]matrix;
}