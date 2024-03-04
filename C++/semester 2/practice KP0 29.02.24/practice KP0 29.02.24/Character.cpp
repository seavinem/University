#include "Character.h"
#include <iostream>
#include <map>
using namespace std;

int Character::nextID = 1;
unsigned int Character::ammount = 0;


map<Artifact, string> artifactToString{
	{ Artifact::BOOK, "Книга заклинаний" },
	{ Artifact::STAFF, "Посох мага" },
	{ Artifact::DICE, "Игральные кости" },
	{ Artifact::MANUAL, "Справочник по магии" },
	{ Artifact::TALISMAN, "Волшебный талисман" },
	{ Artifact::SPHERE, "Магическая сфера" },
	{ Artifact::STONE, "Философский камень" }
};



Character::Character(Race race, string name, State state, bool moveAbility) :
	ID(nextID++), name(name), state(state), race(race), moveAbility(moveAbility) {

	if ((state == State::DEAD || state == State::PARALYZED) && moveAbility == true) {
		throw exception("Парализованные и мёртвые персонажи ходить не могут");
	}

	ammount++;
}


Character::Character(const Character& other) :
	ID(nextID++), name(other.name), state(other.state), race(other.race), moveAbility(other.moveAbility) {}

Character::Character(Character&& other) noexcept :
	ID(nextID++), name(other.name), state(other.state), race(other.race), moveAbility(other.moveAbility) {}


Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->name = other.name;
		this->state = other.state;
		this->moveAbility = other.moveAbility;
	}
	return *this;
}

Character& Character::operator=(Character&& other) noexcept {
	if (this != &other) {
		this->name = other.name;
		this->state = other.state;
		this->moveAbility = other.moveAbility;
	}
	return *this;
}

bool Character::operator<(const Character& other) const {
	return ID < other.ID;
}

string Character::getState() const {
	switch (state) {
	case State::NORMAL:
		return "Нормальное";
		break;
	case State::PARALYZED:
		return "Парализован";
		break;
	case State::DEAD:
		return "Мёртв";
		break;
	}
}

string Character::getRace() const {
	switch (race) {
	case Race::HUMAN:
		return "Человек";
		break;
	case Race::DWARF:
		return "Гном";
		break;
	case Race::ELF:
		return "Эльф";
		break;
	}
}


ostream& operator<<(ostream& os, const Character& character) {

	os << "Персонаж ролевой игры:" << endl
		<< "ID: " << character.ID << endl
		<< "Раса: " << character.getRace() << endl
		<< "Имя: " << character.name << endl
		<< "Состояние: " << character.getState() << endl
		<< "Возможность двигаться: " << character.moveAbility << endl;

	return os;
}

ostream& operator<<(ostream& os, const Wizard& wizard) {
	
	os << "Волшебник:" << endl
		<< "ID: " << wizard.ID << endl
		<< "Раса: " << wizard.getRace() << endl
		<< "Имя: " << wizard.name << endl
		<< "Текущее количество маны: " << wizard.manaCurrent << endl
		<< "Максимальное количество маны: " << wizard.manaTotal << endl
		<< "Количесво артифактов: " << wizard.manaTotal << endl;
	
	string art = "";
	for (auto artifact : wizard.artifacts) {
		art += artifactToString[artifact] + ", ";
	}
	art = art.substr(0, art.size() - 2);

	os << "Артифакты: " << art << endl
		<< "Количесво артифактов: " << wizard.manaTotal << endl
		<< "Состояние: " << wizard.getState() << endl
		<< "Возможность двигаться: " << wizard.moveAbility << endl;
	return os;
}

Wizard::Wizard(Race race, string name, int manaCurrent, int manaTotal, int atrifactsAmmount, vector<Artifact> artifacts, State state, bool moveAbility) :
	Character(race, name, state, moveAbility), manaTotal(manaTotal), manaCurrent(manaCurrent), artifacts(artifacts), artifactAmmount(atrifactsAmmount) {

	if (manaCurrent > manaTotal) {
		throw exception("Текущее количество маны не может быть больше максимального");
	}
	if (artifactAmmount != artifacts.size()) {
		throw exception("Количество артифактов не совпадает с действительностью");
	}

}

Wizard::Wizard(Wizard&& other) noexcept :
	manaTotal(other.manaTotal), manaCurrent(other.manaCurrent), artifactAmmount(other.artifactAmmount), artifacts(artifacts) {}

Wizard::Wizard(const Wizard& other) :
	manaTotal(other.manaTotal), manaCurrent(other.manaCurrent), artifactAmmount(other.artifactAmmount), artifacts(artifacts) {}

Wizard Wizard::operator=(Wizard&& other) noexcept{
	if (this != &other) {
		*this = Wizard(other);
	}
	return *this;
}

Wizard& Wizard::operator=(const Wizard& other) {
	if (this != &other) {
		*this = Wizard(other);
	}
	return *this;
}
