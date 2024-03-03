#include "Character.h"
#include <iostream>
#include <map>
using namespace std;

int Character::nextID = 1;
unsigned int Character::ammount = 0;


map<Artifact, string> artifactToString{
	{ Artifact::BOOK, "����� ����������" },
	{ Artifact::STAFF, "����� ����" },
	{ Artifact::DICE, "��������� �����" },
	{ Artifact::MANUAL, "���������� �� �����" },
	{ Artifact::TALISMAN, "��������� ��������" },
	{ Artifact::SPHERE, "���������� �����" },
	{ Artifact::STONE, "����������� ������" }
};



Character::Character(const Character& other) :
	ID(nextID++), name(other.name), state(other.state), race(other.race), moveAbility(other.moveAbility) {}


Character& Character::operator=(const Character& other) {
	if (this != &other) {
		*this = Character(other);
	}
	return *this;
}

bool Character::operator<(const Character& other) const {
	return ID < other.ID;
}

string Character::getState() const {
	switch (state) {
	case State::NORMAL:
		return "����������";
		break;
	case State::PARALYZED:
		return "�����������";
		break;
	case State::DEAD:
		return "̸���";
		break;
	}
}

string Character::getRace() const {
	switch (race) {
	case Race::HUMAN:
		return "�������";
		break;
	case Race::DWARF:
		return "����";
		break;
	case Race::ELF:
		return "����";
		break;
	}
}


ostream& operator<<(ostream& os, const Character& character) {

	os << "�������� ������� ����:" << endl
		<< "ID: " << character.ID << endl
		<< "����: " << character.getRace() << endl
		<< "���: " << character.name << endl
		<< "���������: " << character.getState() << endl
		<< "����������� ���������: " << character.moveAbility << endl;

	return os;
}

ostream& operator<<(ostream& os, const Wirard& wizard) {
	
	os << "���������:" << endl
		<< "ID: " << wizard.ID << endl
		<< "����: " << wizard.getRace() << endl
		<< "���: " << wizard.name << endl
		<< "������� ���������� ����: " << wizard.manaCurrent << endl
		<< "������������ ���������� ����: " << wizard.manaTotal << endl
		<< "��������� ����������: " << wizard.manaTotal << endl;
	
	string art = "";
	for (auto artifact : wizard.artifacts) {
		art += artifactToString[artifact] + ", ";
	}
	art.substr(0, art.size() - 2);

	os << "���������: " << art << endl
		<< "��������� ����������: " << wizard.manaTotal << endl
		<< "���������: " << wizard.getState() << endl
		<< "����������� ���������: " << wizard.moveAbility << endl;
	return os;
}

Wirard::Wirard(Race race, string name, int manaCurrent, int manaTotal, int atrifactsAmmount) :
	Character(race, name), manaTotal(manaTotal), manaCurrent(manaCurrent), artifacts(vector<Artifact>(atrifactsAmmount)), artifactAmmount(atrifactsAmmount) {

	if (manaCurrent > manaTotal) {
		throw exception("������� ���������� ���� �� ����� ���� ������ �������������");
	}

}

Wirard& Wirard::operator=(const Wirard& other) {
	if (this != &other) {
		*this = Wirard(other);
	}
	return *this;
}
