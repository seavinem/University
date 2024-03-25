#include "TicketSale.h"
#include <map>

TicketSale::TicketSale(const string& _classType, const Type& _type, const int& _seatAmmount, const int& _carriageMaxAmmount, const int& _carriageRealAmmount, const int* _freeSeats) :
	Carriage(_classType, _type, _seatAmmount), carriageMaxAmmount(_carriageMaxAmmount), carriageRealAmmount(_carriageRealAmmount) {

	if (carriageMaxAmmount < 0 || carriageRealAmmount < 0) {
		throw exception("Количество вагонов не может быть меньше нуля");
	}

	for (int i = 0; i < carriageRealAmmount; i++) {
		if (_freeSeats[i] < 0) {
			throw exception("Количество свободных мест в вагоне не может быть меньше нуля");
		}
	}

	int* freeSeatsTemp = new int[carriageRealAmmount];
	for (int i = 0; i < carriageRealAmmount; i++) {
		freeSeatsTemp[i] = _freeSeats[i];
	}

	freeSeats = freeSeatsTemp;
}

TicketSale::~TicketSale() {
	delete[] freeSeats;
}

TicketSale::TicketSale(const TicketSale& sale) :
	TicketSale(sale.classType, sale.type, sale.seatAmmount, sale.carriageMaxAmmount, sale.carriageRealAmmount, sale.freeSeats) {}

TicketSale::TicketSale(TicketSale&& sale) noexcept :
	TicketSale(sale.classType, sale.type, sale.seatAmmount, sale.carriageMaxAmmount, sale.carriageRealAmmount, sale.freeSeats) {}

int TicketSale::getCarriageMaxAmmount() const { return carriageMaxAmmount; }

int TicketSale::getCarriageRealAmmount() const { return carriageRealAmmount; }

int* TicketSale::getFreeSeats() const { return freeSeats; }

void TicketSale::setCarriageRealAmmount(const int& ammount) {
	if (ammount > carriageMaxAmmount) {
		throw exception("превышении максимума вагонов");
	}

	this->carriageRealAmmount = ammount;
}

void TicketSale::setFreeSeats(const int* _freeSeats) {

	int* freeSeatsTemp = new int[carriageRealAmmount];
	for (int i = 0; i < carriageRealAmmount; i++) {
		freeSeatsTemp[i] = _freeSeats[i];
	}

	freeSeats = freeSeatsTemp;
}

TicketSale& TicketSale::operator=(const TicketSale& sale) {
	if (this != &sale) {
		*this = TicketSale(sale);
	}
	return *this;
}

TicketSale& TicketSale::operator=(TicketSale&& sale) noexcept {
	if (this != &sale) {
		*this = TicketSale(sale);
	}
	return *this;
}

void TicketSale::print() const {
	map<Type, string> typeToString{ {Type::sleeping, "спальный"}, {Type::compartment, "купейный"}, {Type::reserved, "плацкартный"}, {Type::general, "общий"} };

	cout << "Вагон поезда: " << endl
		<< "ID: " << getID() << endl
		<< "Класс: " << getClassType() << endl
		<< "Тип: " << typeToString[getType()] << endl
		<< "Максимальное количество таких вагонов: " << getCarriageMaxAmmount() << endl
		<< "Реальное количество таких вагонов: " << getCarriageRealAmmount() << endl
		<< "Количество мест в таких вагонов: ";

	for (int i = 0; i < getCarriageRealAmmount(); i++) {
		cout << freeSeats[i] << " ";
	}
	cout << endl;
}

ostream& operator<<(ostream& out, const TicketSale& sale) {

	map<Type, string> typeToString{ {Type::sleeping, "спальный"}, {Type::compartment, "купейный"}, {Type::reserved, "плацкартный"}, {Type::general, "общий"} };

	out << "Вагон поезда: " << endl
		<< "ID: " << sale.getID() << endl
		<< "Класс: " << sale.getClassType() << endl
		<< "Тип: " << typeToString[sale.getType()] << endl
		<< "Максимальное количество таких вагонов: " << sale.getCarriageMaxAmmount() << endl
		<< "Реальное количество таких вагонов: " << sale.getCarriageRealAmmount() << endl
		<< "Количество мест в таких вагонов: ";

	for (int i = 0; i < sale.getCarriageRealAmmount(); i++) {
		out << sale.freeSeats[i] << " ";
	}
	out << endl;

	return out;
}
