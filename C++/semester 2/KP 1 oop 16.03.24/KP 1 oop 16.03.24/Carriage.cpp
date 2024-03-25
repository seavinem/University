#include "Carriage.h"
#include <map>

int Carriage::next_ID = 1;

Carriage::Carriage(const string& _classType, const Type& _type, const int& _seatAmmount) :
	ID(next_ID++), classType(_classType), type(_type), seatAmmount(_seatAmmount) {

	if (seatAmmount < 0) {
		throw exception("Количество мест в вагоне не может быть отрицательным");
	}
}

Carriage::~Carriage() {
	
}

Carriage::Carriage(const Carriage& carriage) :
	Carriage(carriage.classType, carriage.type, carriage.seatAmmount) {}


Carriage::Carriage(Carriage&& carrige) noexcept :
	Carriage(carrige) {}

int Carriage::getID() const { return ID; }

string Carriage::getClassType() const { return classType; }

Type Carriage::getType() const { return type; }

int Carriage::getSeatAmmount() const { return seatAmmount; }

void Carriage::setClassType(const string& classType) { this->classType = classType; }

void Carriage::setType(const Type&)  { this->type = type; }

Carriage& Carriage::operator=(const Carriage& carriage) {
	if (this != &carriage) {
		*this = Carriage(carriage);
	}
	return *this;
}

Carriage& Carriage::operator=(Carriage&& carriage) noexcept {
	if (this != &carriage) {
		*this = carriage;
	}
	return *this;
}

bool Carriage::operator==(const Carriage& other) {
	return classType == other.classType && type == other.type && seatAmmount == other.seatAmmount;
}

void Carriage::print() const {
	map<Type, string> typeToString{ {Type::sleeping, "спальный"}, {Type::compartment, "купейный"}, {Type::reserved, "плацкартный"}, {Type::general, "общий"} };

	cout << "Вагон поезда: " << endl
		<< "ID: " << getID() << endl
		<< "Класс: " << getClassType() << endl
		<< "Тип: " << typeToString[getType()] << endl
		<< "Количество мест: " << getSeatAmmount() << endl;
}

ostream& operator<<(ostream& out, const Carriage& carriage){

	map<Type, string> typeToString{ {Type::sleeping, "спальный"}, {Type::compartment, "купейный"}, {Type::reserved, "плацкартный"}, {Type::general, "общий"} };

	out << "Вагон поезда: " << endl
		<< "ID: " << carriage.getID() << endl
		<< "Класс: " << carriage.getClassType() << endl
		<< "Тип: " << typeToString[carriage.getType()] << endl
		<< "Количество мест: " << carriage.getSeatAmmount() << endl;

	return out;
}
