#include <iostream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>

using namespace std;

class matrix {
    int row, col, max;
    list<list<int>> p;

public:
    matrix(int row, int col, int max);

    void fillWithRandom();
    void deleteMaxRowCol();
    void sortEachRow();
    void sortRowsByLex();
    void sortRowsBySum();

    friend ostream& operator << (ostream& output, const matrix& m);
};

class IncorrectInput : public exception
{
public:
    const char* what() const throw()
    {
        return "������������ ����";
    }
};

class EmptyMatrix : public exception
{
public:
    const char* what() const throw()
    {
        return "����� �������� �������� ������ � ������� ������� �� �������� ���������";
    }
};