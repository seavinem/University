#include <iostream>
#include "matrix.h"
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int row, col, max;

    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> row >> col;

    string check = to_string(row);
    for (auto& it : check) {
        if (!isdigit(it)) {
            cerr << "Недопустимый ввод";
            return 1;
        }
    }

    check = to_string(col);
    for (auto& it : check) {
        if (!isdigit(it)) {
            cerr << "Недопустимый ввод";
            return 1;
        }
    }


    cout << "Введите максимальный элемент матрицы: ";
    cin >> max;

    check = to_string(max);
    for (auto& it : check) {
        if (!isdigit(it)) {
            cerr << "Недопустимый ввод";
            return 1;
        }
    }


    try {
        matrix matrix(row, col, max);


        matrix.fillWithRandom();
        cout << "Начальная матрица:" << endl;
        cout << matrix;

        matrix.deleteMaxRowCol();
        cout << "\nМатрица после удаления строки и столбца, на пересечении которых стоит максимальный элемент:" << endl;
        cout << matrix;

        matrix.sortEachRow();
        cout << "\nМатрица после сортировки элементов каждой строки по возрастанию:" << endl;
        cout << matrix;

        matrix.sortRowsByLex();
        cout << "\nМатрица после сортировки строк лексикографически по возрастанию:" << endl;
        cout << matrix;

        matrix.sortRowsBySum();
        cout << "\nМатрица после сортировки строк по возрастанию сумм элементов строк:" << endl;
        cout << matrix;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }

}