#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

void matrixInput(matrix &matrix1, matrix &matrix2) {
	cout << "Введите формат первой матрицы (кол-во колонок и столбцов), а затем её элементы: ";
	cin >> matrix1;
	cout << "Введите формат второй матрицы(кол - во колонок и столбцов), а затем её элементы : ";
	cin >> matrix2;
}
void numberInput(double& num) {
	cout << "Введите число для операций: ";

	string value;
	int pos = 0;

	cin >> value;

	if (value[0] == '-' || value[0] == '+') {
		pos = 1;
	}

	for (int i = pos; i < value.length(); i++) {
		if (!isdigit(value[i]) && value[i] != '.') {
			throw IncorrectInput();
		}
	}

	if (value.find('.') != -1) {
		num = stoi(value.substr(0, value.find('.'))) + stoi(value.substr(value.find('.') + 1)) / value.substr(value.find('.') + 1).size();
	}
	else {
		num = stoi(value);
	}
}

void assignmentOperations(matrix matrix1, matrix matrix2, double num) {
	cout << "Присваивание: -> A = B" << endl;
	matrix A = matrix2;
	cout << A;
	A = matrix1;

	cout << "\nСоставное присваивание:\n";
	cout << "\nA += B" << endl;
	A += matrix2;
	cout << A;
	A = matrix1;

	cout << "\nA -= B" << endl;
	A -= matrix2;
	cout << A;
	A = matrix1;

	cout << "\nA *= B" << endl;
	A *= matrix2;
	cout << A;
	A = matrix1;

	cout << "\nA *= x" << endl;
	A *= num;
	cout << A;
	A = matrix1;

	cout << "\nA /= x" << endl;
	A /= num;
	cout << A;
}
void commonOperations(matrix matrix1, matrix matrix2, double num) {
	cout << "Умножение на число слева: -> x * A" << endl;
	cout << num * matrix1;

	cout << "\nУмножение на число справа: -> A * x" << endl;
	cout << matrix1 * num;

	cout << "\nДеление на число: -> A / x" << endl;
	cout << matrix1 / num;

	cout << "\nУмножение матриц: -> A * B" << endl;
	cout << matrix1 * matrix2;

	cout << "\nСложение матриц: -> A + B" << endl;
	cout << matrix1 + matrix2;

	cout << "\nВычитание матриц: -> A - B" << endl;
	cout << matrix1 - matrix2;
}
void comparisonOperations(matrix matrix1, matrix matrix2) {
	cout.setf(ios_base::boolalpha);
	cout << "Сравнение матриц:\n";

	cout << "\nA == B -> " << (matrix1 == matrix2) << endl;
	cout << "\nA != B -> " << (matrix1 != matrix2) << endl;
}

int main() {
	setlocale(LC_ALL, "ru");

	matrix matrix1, matrix2;
	double number;

	try {
		matrixInput(matrix1, matrix2);
		numberInput(number);

		cout << "A:\n" << matrix1 << endl << "B:\n" << matrix2 << endl;

		commonOperations(matrix1, matrix2, number);
		cout << endl;
		assignmentOperations(matrix1, matrix2, number);
		cout << endl;
		comparisonOperations(matrix1, matrix2);
	}
	catch (const exception& e) {
		cout << "Ошибка: " << e.what() << endl;
	}
}
