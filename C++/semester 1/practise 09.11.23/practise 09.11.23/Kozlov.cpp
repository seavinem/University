#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	ifstream input("input.txt");

	if (!input) {
		cerr << "Ошибка открытия входного файла\n";
		return 1;
	}
	if (input.peek() == EOF) {
		cerr << "Входной файл пуст" << endl;
		return 1;
	}

	string word1, word2, line;
	vector<string> text;
	int indexword1 = -1, indexword2 = -1, index = 0;

	input >> word1 >> word2;

	while (getline(input, line)) {
		string wordline;

		for (int i = 0; i < line.size() + 1; i++) {
			if (line[i] == ' ' || line[i] == '\0' || line[i] == '\n') {
				if (wordline == word1 && indexword1 == -1) {
					indexword1 = index;
					text.push_back(word1);
				}
				else if (wordline == word2 && indexword2 == -1) {
					indexword2 = index;
					text.push_back(word2);
				}
				else {
					text.push_back(wordline);
				}
				text.push_back(" ");
				index += 2;
				wordline = "";
			}
			else {
				wordline += line[i];
			}
		}

		text.pop_back();
		text.push_back("\n");
	}

	input.close();


	ofstream output("output.txt");

	if (!output) {
		cerr << "Ошибка открытия выходного файла\n";
		return 1;
	}

	if (indexword1 == -1 && indexword2 == -1)
		output << "в тексте нет обоих слов";
	else if (indexword1 == -1 && indexword2 != -1)
		output << "в тексте нет первого слова";
	else if (indexword1 != -1 && indexword2 == -1)
		output << "в тексте нет второго слова";
	else {
		swap(text[indexword1], text[indexword2]);
		for (int i = 2; i < text.size() - 1; i++)
			output << text[i];
	}

	output.close();
}