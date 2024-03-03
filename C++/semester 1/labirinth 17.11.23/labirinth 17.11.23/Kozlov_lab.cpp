#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//������� �������� �� ����� �������, � ������� ����� �����
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
////������� �������� �� ��� � ��������� �������
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
//������� �������� �� ����� ����, �.�. ����������� �� 1 ��� �����
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


	//�������� �������� �����
	ifstream input("A1.txt");
	//�������� ����� �� �������� � �������
	if (!input.is_open()) {
		cerr << "������ �������� �������� �����" << endl;
		return 1;
	}
	if (input.peek() == EOF) {
		cerr << "������� ���� ����" << endl;
		return 1;
	}

	//������ ��������� � ��������� ������ � ��������� ��������� ������
	try {
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				value = input.get();
				if (value == EOF) {
					throw exception("������������ ������");
				}
				if (!isdigit(value)) {
					throw exception("������� ������� �������");
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
	//�������� �������� �����
	input.close();


	//����� ���� � ���������
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


	//�������� ��������� �����
	ofstream output("A2.txt");
	//�������� ����� �� ��������
	if (!output.is_open()) {
		cerr << "������ �������� ��������� �����" << endl;
		return 1;
	}

	//����� ���������� � ����
	if (iCur == N - 1 && jCur == M - 1) {
		output << way;
	}
	else {
		output << "���� ���";
	}

	//�������� ��������� �����
	output.close();
}