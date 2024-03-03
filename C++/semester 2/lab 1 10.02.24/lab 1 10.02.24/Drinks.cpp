#include "Drinks.h"

ostream& operator<<(ostream& out, const Vodka& drink) {
    out << "�����: " << endl
        << "\tID: " << drink.id << endl
        << "\t�����: " << drink.volume << "�." << endl
        << "\t����: " << drink.price << "�." << endl
        << "\t�����: " << drink.brand << endl
        << "\t������ �������������: " << drink.country << endl
        << "\t��������: " << drink.degree << "%" << endl
        << "\t��������: " << drink.aging << " ���";
    return out;
}

ostream& operator<<(ostream& out, const Cognac& drink) {
    out << "������: " << endl
        << "\tID: " << drink.id << endl
        << "\t�����: " << drink.volume << "�." << endl
        << "\t����: " << drink.price << "�." << endl
        << "\t�����: " << drink.brand << endl
        << "\t������ �������������: " << drink.country << endl
        << "\t��������: " << drink.degree << "%" << endl
        << "\t��������: " << drink.aging << " ���";
    return out;
}

ostream& operator<<(ostream& out, const �hampagne& drink) {
    out << "����������: " << endl
        << "\tID: " << drink.id << endl
        << "\t�����: " << drink.volume << "�." << endl
        << "\t����: " << drink.price << "�." << endl
        << "\t�����: " << drink.brand << endl
        << "\t������ �������������: " << drink.country << endl
        << "\t��������: " << drink.degree << "%" << endl
        << "\t��������: " << drink.aging << " ���" << endl
        << "\t������������ �������";
    return out;
}

ostream& operator<<(ostream& out, const Wine& drink)
{
    out << "����: " << endl
        << "\tID: " << drink.id << endl
        << "\t���: " << drink.type << endl
        << "\t�����: " << drink.volume << "�." << endl
        << "\t����: " << drink.price << "�." << endl
        << "\t�����: " << drink.brand << endl
        << "\t������ �������������: " << drink.country << endl
        << "\t��������: " << drink.degree << "%" << endl
        << "\t��������: " << drink.aging << " ���";
    return out;
}

ostream& operator<<(ostream& out, const Beer& drink)
{
    out << "����: " << endl
        << "\tID: " << drink.id << endl
        << "\t���: " << drink.type << endl
        << "\t�����: " << drink.volume << "�." << endl
        << "\t����: " << drink.price << "�." << endl
        << "\t�����: " << drink.brand << endl
        << "\t������ �������������: " << drink.country << endl
        << "\t��������: " << drink.degree << "%" << endl
        << "\t��������: " << drink.aging << " ���";
    return out;
}



void Wine::shareWithFriend() {
    volume *= 0.75;
}

bool Wine::operator==(const Wine& other) const {
    return abs(price / volume - other.price / other.volume) < 10 && abs(degree - other.degree) < 5 && type == other.type;
}



void Beer::shareWithFriend() {
    volume /= 3;
}

bool Beer::operator==(const Beer& other) const
{
    return abs(price / volume - other.price / other.volume) < 10 && abs(degree - other.degree) < 5 && type == other.type;
}

void Vodka::shareWithFriend() {
    if (degree >= 40)
        volume /= 2;
    else
        volume /= 3;
}

void Cognac::shareWithFriend() {
    volume *= 0.8;
}

void �hampagne::shareWithFriend() {
    volume /= 2;
}
