#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//функция отвечает за поиск стороны, в которую можно пойти
int sideToGo(vector<vector<int>>& labyrinth, int i, int j) {
	if (labyrinth[i][j + 1] == 1 && !(i == 1 && j + 1 == 1)) {
		return 1;
	}
	else if (labyrinth[i + 1][j] == 1 && !(i + 1 == 1 && j == 1)) {
		return 2;
	}
	else if (labyrinth[i][j - 1] == 1 && !(i == 1 && j - 1 == 1)) {
		return 3;
	}
	else if (labyrinth[i - 1][j] == 1 && !(i - 1 == 1 && j == 1)) {
		return 4;
	}
	else if (labyrinth[i][j + 1] == 0 &&
		labyrinth[i][j - 1] == 0 &&
		labyrinth[i + 1][j] == 0 &&
		labyrinth[i - 1][j] == 0) {
		return 0;
	}
	else {
		return -1;
	}
}
////функция отвечает за шаг в допутимую сторону
void step(int& i, int& j, int side, int& K, string& answer) {
	switch (side) {
	case 1:
		j++;
		break;
	case 2:
		i++;
		break;
	case 3:
		j--;
		break;
	case 4:
		i--;
		break;
	}
	K++;
	answer += " - (" + to_string(i) + ", " + to_string(j) + ")";
}
//функция отвечает за откат шага, т.е. возвращение на 1 шаг назад
void goBack(vector<vector<int>>& labyrinth, int& i, int& j, int& K, string& way) {
	labyrinth[i][j] = 0;
	way.erase(way.rfind(" - "), way.rfind(")") - way.rfind(" - ") + 1);
	int iPrev = stoi(way.substr(way.rfind("(") + 1, way.rfind(",") - way.rfind("(") - 1));
	int jPrev = stoi(way.substr(way.rfind(",") + 2, way.rfind(")") - way.rfind("(") - 1));
	i = iPrev;
	j = jPrev;
	K = labyrinth[iPrev][jPrev];
}


int main() {
	setlocale(LC_ALL, "ru");
	int iCur = 1, jCur = 1, N = 11, M = 11, K = 1;
	char value;
	vector<vector<int>>labyrinth(N + 1, vector<int>(M + 1, 0));
	string way = "(1, 1)";


	//открытие входного файла
	ifstream input("A1.txt");
	//проверка файла на открытие и пустоту
	if (!input.is_open()) {
		cerr << "Ошибка открытия входного файла" << endl;
		return 1;
	}
	if (input.peek() == EOF) {
		cerr << "Входной файл пуст" << endl;
		return 1;
	}

	//чтение лабиринта в двумерный вектор и обработка возможных ошибок
	try {
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				value = input.get();
				if (value == EOF) {
					throw exception("Недостаточно данных");
				}
				if (!isdigit(value)) {
					throw exception("Матрица введена неверно");
				}
				labyrinth[i][j] = value - '0';
			}
			input.ignore();
		}
	} 
	catch (const exception& err) {
		cerr << err.what() << endl;
		return 1;
	}
	//закрытие входного файла
	input.close();


	//поиск пути в лабиринте
	int side = sideToGo(labyrinth, iCur, jCur);
	while (!(iCur == N - 1 && jCur == M - 1) && side != 0) {

		while (side == -1) {
			goBack(labyrinth, iCur, jCur, K, way);
			side = sideToGo(labyrinth, iCur, jCur);
		}

		step(iCur, jCur, side, K, way);
		labyrinth[iCur][jCur] = K;
		side = sideToGo(labyrinth, iCur, jCur);
	}


	//открытие выходного файла
	ofstream output("A2.txt");
	//проверка файла на открытие
	if (!output.is_open()) {
		cerr << "Ошибка открытия выходного файла" << endl;
		return 1;
	}

	//вывод результата в файл
	if (iCur == N - 1 && jCur == M - 1) {
		output << way;
	}
	else {
		output << "Хода нет";
	}

	//закрытие выходного файла
	output.close();
}