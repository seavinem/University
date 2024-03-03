#include "Drinks.h"

ostream& operator<<(ostream& out, const Vodka& drink) {
    out << "Водка: " << endl
        << "\tID: " << drink.id << endl
        << "\tобъём: " << drink.volume << "л." << endl
        << "\tцена: " << drink.price << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет";
    return out;
}

ostream& operator<<(ostream& out, const Cognac& drink) {
    out << "Коньяк: " << endl
        << "\tID: " << drink.id << endl
        << "\tобъём: " << drink.volume << "л." << endl
        << "\tцена: " << drink.price << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет";
    return out;
}

ostream& operator<<(ostream& out, const Сhampagne& drink) {
    out << "Шампанское: " << endl
        << "\tID: " << drink.id << endl
        << "\tобъём: " << drink.volume << "л." << endl
        << "\tцена: " << drink.price << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет" << endl
        << "\tгазированный напиток";
    return out;
}

ostream& operator<<(ostream& out, const Wine& drink)
{
    out << "Вино: " << endl
        << "\tID: " << drink.id << endl
        << "\tтип: " << drink.type << endl
        << "\tобъём: " << drink.volume << "л." << endl
        << "\tцена: " << drink.price << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет";
    return out;
}

ostream& operator<<(ostream& out, const Beer& drink)
{
    out << "Пиво: " << endl
        << "\tID: " << drink.id << endl
        << "\tтип: " << drink.type << endl
        << "\tобъём: " << drink.volume << "л." << endl
        << "\tцена: " << drink.price << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет";
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

void Сhampagne::shareWithFriend() {
    volume /= 2;
}
