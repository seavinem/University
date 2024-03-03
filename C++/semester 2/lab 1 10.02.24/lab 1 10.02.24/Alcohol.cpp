#include "Alcohol.h"

int Alcohol::nextId = 1;

Alcohol::Alcohol(string name, string brand, string country, double volume, double price, double degree, int aging, bool isCarbonated) :
	name(name), brand(brand), country(country), volume(volume), price(price),
	degree(degree), aging(aging), isCarbonated(isCarbonated) {

    setID();

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
    isCarbonated = other.isCarbonated;
    setID();
}

void Alcohol::drink() {
    volume -= 0.05;
}

void Alcohol::shareWithFriend() {
    volume /= 2;
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
        << "\tцена: " << drink.price  << "р." << endl
        << "\tбренд: " << drink.brand << endl
        << "\tстрана производителя: " << drink.country << endl
        << "\tкрепость: " << drink.degree << "%" << endl
        << "\tвыдержка: " << drink.aging << " лет" << endl
        << "\tгазированность: " << drink.isCarbonated;
    return out;
}
