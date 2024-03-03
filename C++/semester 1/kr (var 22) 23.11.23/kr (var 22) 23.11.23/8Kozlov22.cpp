#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//сортировка по сумме цифр
void sortedByDigits(vector<int>* nums) {
	int sum1, sum2, k = (*nums).size() - 1;
	bool flag = true;
	while (k > 0 && flag) {
		flag = false;
		for (int i = 0; i < k; i++) {
			sum1 = 0;
			sum2 = 0;
			int val1 = abs((*nums)[i]), val2 = abs((*nums)[i + 1]);

			while (val1 > 0) {
				sum1 += val1 % 10;
				val1 /= 10;
			}

			while (val2 > 0) {
				sum2 += val2 % 10;
				val2 /= 10;
			}

			if (sum1 > sum2) {
				swap((*nums)[i], (*nums)[i + 1]);
				flag = true;
			}
		}
		k--;
	}
}

//обмен элементов местами
void swap(int* num1, int* num2) {
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

//проверка, является ли слово десятичным числом
bool isNumber(string word) {
	int pos = 0;

	if (word.size() == 0) {
		return false;
	}

	if (word[0] == '0' && word.size() != 1) {
		return false; 
	}

	if (word[0] == '+' || word[0] == '-') {
		pos = 1;
		if (word.size() == 1) { 
			return false; 
		} 
	}

	for (pos; pos < word.size(); pos++) {
		if (!isdigit(word[pos])) {
			return false;
		}
	}

	return true;
}


int main() {
	setlocale(LC_ALL, "ru");
	string dtr, line, word;
	vector<string> lines;
	vector<int> nums;
	int count = 0, countText = 0, countWords = 0, start = 0, end = 0;
	ifstream in("IN22.TXT");

	//проверка входного файла на открытие и пустоту
	if (!in.is_open()) {
		cout << "Ошибка открытия входного файла IN22.txt" << endl;
		return 1;
	}
	if (in.peek() == EOF) {
		cout << "Входной файл IN22.txt пуст" << endl;
		return 1;
	}

	getline(in, dtr);
	if (dtr.size() != 0) {
		count++;
	}

	while (getline(in, line)) {
		lines.push_back(line);
		if (line.find_first_not_of(dtr) != -1) {
			countWords++;
		}
		if (line.find_first_not_of(" \n\t") != -1) {
			countText++;
		}
	}

	in.close();


	//проверка введенных во входной файл данных
	if (countText == 0 && count != 0) {
		cout << "Строки входной файла IN22.txt, содержащие текст, пусты" << endl;
		return 1;
	}
	if (count + countText == 0) {
		cout << "Входной файл IN22.txt пуст" << endl;
		return 1;
	}
	if (countWords == 0) {
		cout << "Входной файл IN22.txt не содержит слов" << endl;
		return 1;
	}

	//занесение слов в вектор десятичных чисел
	for (int i = 0; i < lines.size(); i++) {
		start = 0;
		end = 0;

		while (lines[i].find_first_not_of(dtr, end) != -1) {
			start = lines[i].find_first_not_of(dtr, end);
			end = lines[i].find_first_of(dtr, start);

			if (end != -1) {
				word = lines[i].substr(start, end - start);
			}
			else {
				word = lines[i].substr(start);
			}

			if (isNumber(word)) {
				nums.push_back(stoi(word));
			}
		}
	}

	//проверка входного файла на наличие чисел
	if (nums.size() == 0) {
		cout << "Входной файл IN22.txt не содержит десятичных чисел" << endl;
		return 1;
	}


	ofstream out("OUT22.TXT");
	//проерка выходного файла на открытие
	if (!out.is_open()) {
		cout << "Ошибка открытия выходного файла OUT22.txt" << endl;
		return 1;
	}

	//вывод неотсортированных чисел
	for (int i = 0; i < nums.size(); i++) {
		if (i != nums.size() - 1) {
			out << nums[i] << "; ";
		}
		else {
			out << nums[i] << "\n";
		}
	}

	//сортировка вектора
	sortedByDigits(&nums);

	//вывод отсортированных чисел
	for (int i = 0; i < nums.size(); i++) {
		if (i != nums.size() - 1) {
			out << nums[i] << ", ";
		}
		else {
			out << nums[i];
		}
	}

	out.close();

	cout << "Программа завершена успешно" << endl;
	return 0; 
}