#include "matrix.h"
#include <iostream>
#include <list>
using namespace std;

matrix::matrix(int row, int col, int max) {
    if (row < 1 || col < 1) {
        throw IncorrectInput();
    }

    this->row = row;
    this->col = col;
    this->max = max;

    for (int i = 0; i < row; i++) {
        list<int> row;
        p.push_back(row);
    }
}


void matrix::fillWithRandom() {
    srand(time(NULL));

    for (auto& row : p) {
        for (int i = 0; i < col; i++) {
            row.push_back(rand() % (max + 1));
        }
    }
}

void matrix::deleteMaxRowCol() {
    int maxPoint = 0;
    int maxRow = 0;
    int maxCol = 0;
    int i = 0;
    int j = 0;

    for (auto& row : p) {
        j = 0;
        for (auto& it : row) {
            if (it > maxPoint) {
                maxPoint = it;
                maxRow = i;
                maxCol = j;
            }
            j++;
        }
        i++;
    }

    auto it = p.begin();
    advance(it, maxRow);
    p.erase(it);

    for (auto& row : p) {
        auto it = row.begin();
        advance(it, maxCol);
        row.erase(it);
    }
    row--;
    col--;

    if (row < 1 || col < 1) {
        throw EmptyMatrix();
    }
}

void matrix::sortEachRow() {
    for (auto& row : p) {
        row.sort();
    }
}

void matrix::sortRowsByLex() {
    p.sort();
}

void matrix::sortRowsBySum() {
    list<pair<int, list<int>>> listOfSum;

    for (auto& row : p) {

        int sum = 0;
        for (auto& it : row) {
            sum += it;
        }

        listOfSum.push_back(make_pair(sum, row));
    }

    listOfSum.sort();
    p.clear();

    for (auto& it : listOfSum) {
        p.push_back(it.second);
    }
}


ostream& operator<<(ostream& output, const matrix& m)
{
    for (auto& row : m.p) {
        for (auto& it : row) {
            output << it << "\t";
        }
        output << endl;
    }

    return output;
}
