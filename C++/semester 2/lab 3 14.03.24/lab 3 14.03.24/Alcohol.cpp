#include "Alcohol.h"

int Alcohol::nextId = 1;

Alcohol::Alcohol() : id(nextId++), name("не задано"), brand("не задано"), country("не задано"), volume(0.0), price(0),
degree(0), aging(0), isCarbonated(false) {}

Alcohol::Alcohol(string name, string brand, string country, double volume, int price, int degree, int aging, bool isCarbonated) :
    id(nextId++), name(name), brand(brand), country(country), volume(volume), price(price),
    degree(degree), aging(aging), isCarbonated(isCarbonated) {

    if (volume <= 0 || price < 0 || degree < 0 || aging < 0)
        throw exception();
}

Alcohol::Alcohol(const Alcohol& other) {
    name = other.name;
    brand = other.brand;
    country = other.country;
    volume = other.volume;
    price = other.price;
    degree = other.degree;
    aging = other.aging;
    aging = other.aging;
    isCarbonated = other.isCarbonated;
}


Alcohol& Alcohol::operator=(const Alcohol& other) {
    if (this != &other) {
        name = other.name;
        brand = other.brand;
        country = other.country;
        volume = other.volume;
        price = other.price;
        degree = other.degree;
        aging = other.aging;
        isCarbonated = other.isCarbonated;
    }
    return *this;
}

bool Alcohol::operator==(const Alcohol& other) const {
    return abs(price / volume - other.price / other.volume) < 250 && abs(degree - other.degree) < 5;
}


ostream& operator<<(ostream& out, const Alcohol& drink) {
    out << "Напиток: " << drink.name << endl
        << "\tID: " << drink.id << endl
        << "\tобъём: " << drink.volume << "л." << endl
        << "\tцена: " << drink.price << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет" << endl
        << "\tгазированность: " << drink.isCarbonated;
    return out;
}






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

ostream& operator<<(ostream& out, const Champagne& drink) {
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



bool Wine::operator==(const Wine& other) const {
    return abs(price / volume - other.price / other.volume) < 10 && abs(degree - other.degree) < 5 && type == other.type;
}


bool Beer::operator==(const Beer& other) const
{
    return abs(price / volume - other.price / other.volume) < 10 && abs(degree - other.degree) < 5 && type == other.type;
}



void Wine::shareWithFriend() {
    volume *= 0.75;
}


void Beer::shareWithFriend() {
    volume /= 3;
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

void Champagne::shareWithFriend() {
    volume /= 2;
}

