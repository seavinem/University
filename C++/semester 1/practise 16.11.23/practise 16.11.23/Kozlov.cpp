#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class RationalNumber {
    int chisl, znam;

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    void reduce(int& num, int& denom) {
        if ((num < 0 && denom < 0) || (num > 0 && denom < 0)) {
            num /= -1;
            denom /= -1;
        }
        int gcdNew = gcd(num, denom);
        num /= gcdNew;
        denom /= gcdNew;
    }

public:
    //1 часть

    RationalNumber(int num, int denom) {
        if (denom == 0) {
            throw exception("Знаменатель не может быть равен нулю");
        }
        chisl = num;
        znam = denom;
        reduce(chisl, znam);
    }

    RationalNumber(const RationalNumber& rn) : chisl(rn.chisl), znam(rn.znam) {}

    RationalNumber() = delete;

    int getChisl() {
        return chisl;
    }
    int getZnam() {
        return znam;
    }

    void printNumber() const {
        if (chisl == 0)
        {
            cout << 0;
        }
        else if (chisl == 1 && znam == 1)
        {
            cout << 1;
        }
        else if (chisl > 1 && znam == 1)
        {
            cout << chisl;
        }
        else
        {
            cout << chisl << "/" << znam;
        }
    }


    //2 часть

    RationalNumber operator ++()
    {
        int newChisl = chisl + znam;
        int newZnam = znam;
        reduce(newChisl, newZnam);
        return RationalNumber(newChisl, newZnam);
    }
    RationalNumber operator --()
    {
        int newChisl = chisl - znam;
        int newZnam = znam;
        reduce(newChisl, newZnam);
        return RationalNumber(newChisl, newZnam);
    }

    RationalNumber operator +(const RationalNumber& other)
    {
        int newChisl = (chisl * other.znam) + (other.chisl * znam);
        int newZnam = znam * other.znam;
        reduce(newChisl, newZnam);
        return RationalNumber(newChisl, newZnam);
    }
    RationalNumber operator -(const RationalNumber& other)
    {
        int newChisl = (chisl * other.znam) - (other.chisl * znam);
        int newZnam = znam * other.znam;
        reduce(newChisl, newZnam);
        return RationalNumber(newChisl, newZnam);
    }
    RationalNumber operator *(const RationalNumber& other)
    {
        int newChisl = chisl * other.chisl;
        int newZnam = znam * other.znam;
        reduce(newChisl, newZnam);
        return RationalNumber(newChisl, newZnam);
    }
    RationalNumber operator /(const RationalNumber& other)
    {
        int newChisl = chisl * other.znam;
        int newZnam = other.chisl * znam;
        if (newZnam == 0) {
            throw exception("Деление на ноль");
        }
        reduce(newChisl, newZnam);
        return RationalNumber(newChisl, newZnam);
    }

    bool operator ==(const RationalNumber& other)
    {
        RationalNumber value1(chisl, znam), value2(other.chisl, other.znam);
        RationalNumber LessGreaterEqual = value1 - value2;
        bool equal = LessGreaterEqual.chisl == 0;
        return equal;
    }
    bool operator <(const RationalNumber& other)
    {
        RationalNumber value1(chisl, znam), value2(other.chisl, other.znam);
        RationalNumber LessGreaterEqual = value1 - value2;
        bool less = LessGreaterEqual.chisl < 0;
        return less;
    }
    bool operator >(const RationalNumber& other)
    {
        RationalNumber value1(chisl, znam), value2(other.chisl, other.znam);
        RationalNumber LessGreaterEqual = value1 - value2;
        bool greater = LessGreaterEqual.chisl > 0;
        return greater;
    }

    operator double() const {
        return (double)chisl / znam;
    }

    friend istream& operator>>(istream& input, RationalNumber& rn)
    {
        input >> rn.chisl >> rn.znam;
        return input;
    }
    friend ostream& operator<<(ostream& output, const RationalNumber& rn)
    {
        if (rn.chisl == 0)
        {
            output << 0;
        }
        else if (rn.chisl == 1 && rn.znam == 1)
        {
            output << 1;
        }
        else if (rn.chisl != 1 && rn.znam == 1)
        {
            output << rn.chisl;
        }
        else
        {
            output << rn.chisl << "/" << rn.znam;
        }
        return output;
    }
};


void comparisonOperations(RationalNumber rnValue1, RationalNumber rnValue2) {
    cout << "Сравнение дробей:\n";
    if (rnValue1 == rnValue2)
        cout << rnValue1 << " = " << rnValue2 << endl;
    if (rnValue1 < rnValue2)
        cout << rnValue1 << " < " << rnValue2 << endl;
    if (rnValue1 > rnValue2)
        cout << rnValue1 << " > " << rnValue2 << endl;
}
void RationalToDouble(RationalNumber rnValue1, RationalNumber rnValue2) {
    cout << "Дроби в виде действительных чисел:\n";
    cout << (double)rnValue1 << '\t' << (double)rnValue2 << endl;
}
void unaryOperations(RationalNumber rnValue1, RationalNumber rnValue2) {
    cout << "Унарный плюс\n";
    cout << rnValue1 << "++ = " << ++rnValue1 << '\n' << rnValue2 << "++ = " << ++rnValue2 << endl;
    cout << "Унарный минус\n";
    cout << rnValue1 << "-- = " << --rnValue1 << '\n' << rnValue2 << "-- = " << --rnValue2 << endl;
}
void numericalOperations(RationalNumber rnValue1, RationalNumber rnValue2) {
    cout << "Сумма\n";
    cout << rnValue1 << " + " << rnValue2 << " = " << rnValue1 + rnValue2 << endl;
    cout << "Вычитание\n";
    cout << rnValue1 << " - " << rnValue2 << " = " << rnValue1 - rnValue2 << endl;
    cout << "Умножение\n";
    cout << rnValue1 << " * " << rnValue2 << " = " << rnValue1 * rnValue2 << endl;
    cout << "Деление\n";
    cout << rnValue1 << " / " << rnValue2 << " = " << rnValue1 / rnValue2 << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    string value1, value2;
    int value1Chisl, value1Znam, value2Chisl, value2Znam;

    cout << "Введите две дроби (пример ввода: 10 20 - это дробь 10/20)" << endl;
    try {
        cout << "Числитель и знаменатель первой дроби: ";
        getline(cin, value1);
        if (value1.find(" ") != -1) {
            value1Chisl = stoi(value1.substr(0, value1.find_first_of(" ")));
            value1Znam = stoi(value1.substr(value1.find_last_of(" ") + 1));
        }
        else {
            value1Chisl = stoi(value1.substr(0, value1.find_first_of(" ")));
            value1Znam = 1;
        }


        cout << "Числитель и знаменатель второй дроби: ";
        getline(cin, value2);
        if (value2.find(" ") != -1) {
            value2Chisl = stoi(value2.substr(0, value2.find_first_of(" ")));
            value2Znam = stoi(value2.substr(value2.find_last_of(" ") + 1));
        }
        else {
            value2Chisl = stoi(value2.substr(0, value2.find_first_of(" ")));
            value2Znam = 1;
        }

        try {
            RationalNumber rnValue1(value1Chisl, value1Znam), rnValue2(value2Chisl, value2Znam);
            cout << "Первая дробь: " << rnValue1 << "\tВторая дробь: " << rnValue2 << endl;

            cout << endl;
            comparisonOperations(rnValue1, rnValue2);
            cout << endl;
            RationalToDouble(rnValue1, rnValue2);
            cout << endl;
            unaryOperations(rnValue1, rnValue2);
            cout << endl;
            numericalOperations(rnValue1, rnValue2);
        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
    }
    catch (...) {
        cout << "Неверный ввод" << endl;
    }
}