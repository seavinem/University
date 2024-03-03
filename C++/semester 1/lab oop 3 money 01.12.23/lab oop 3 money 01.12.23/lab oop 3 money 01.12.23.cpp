#include <iostream>
#include "money.h"
using namespace std;

void numericalOperations(money cash1, money cash2) {
    cout << "Сложение:" << endl;
    cout << cash1 << " + " << cash2 << " = " << cash1 + cash2 << endl;
    cout << "Вычитание:" << endl;
    cout << cash1 << " - " << cash2 << " = " << cash1 - cash2 << endl;
}
void comparisonOperations(money cash1, money cash2) {
    cout.setf(ios_base::boolalpha);

    cout << "Сравнение:" << endl;
    cout << cash1 << " == " << cash2 << " -> " << (cash1 == cash2) << endl;
    cout << cash1 << " > " << cash2 << " -> " << (cash1 > cash2) << endl;
    cout << cash1 << " < " << cash2 << " -> " << (cash1 < cash2) << endl;
}
void assignmentOperations(money cash1, money cash2) {
    money X = cash1;
    cout << "Присвание и составное присваивание - вначале Х = " << X << endl;
    
    X = cash2;
    cout << "X = " << cash2 << " - > X = " << X << endl;
    X = cash1;

    X += cash2;
    cout << "X += " << cash2 << " - > X = " << X << endl;
    X = cash1;

    X -= cash2;
    cout << "X -= " << cash2 << " - > X = " << X << endl;
}
void unaryMinus(money cash1) {
    cout << "Унарный минус" << endl;
    cout << "-(" << cash1 << ") = " << -cash1 << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    try {
        money cash1, cash2, cash3(1, 2, 9);

        cout << "Введите первую сумму денег: ";
        cin >> cash1;
        cout << "Введите вторую сумму денег: ";
        cin >> cash2;

        cout << "Первая сумма денег: " << cash1 << "\tВторая сумма денег: " << cash2 << endl;

        cout << endl;
        numericalOperations(cash1, cash2);
        cout << endl;
        comparisonOperations(cash1, cash2);
        cout << endl;
        assignmentOperations(cash1, cash2);
        cout << endl;
        unaryMinus(cash1);
    }
    catch (exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}
