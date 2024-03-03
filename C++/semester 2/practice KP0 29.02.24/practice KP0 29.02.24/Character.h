#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


enum class State { NORMAL, PARALYZED, DEAD };
enum class Race { HUMAN, DWARF, ELF };
enum class Artifact { BOOK, STAFF, DICE, MANUAL, TALISMAN, SPHERE, STONE };



class Character {

	static int nextID;
	static unsigned int ammount;

protected:
	const int ID;
	string name;
	State state;
	const Race race;
	bool moveAbility;

public:
	Character() :
		ID(nextID++), name(""), state(State::NORMAL), race(Race::HUMAN), moveAbility(false) { ammount++; }

	Character(Race race, string name, State state= State::NORMAL, bool moveAbility = true) :
		ID(nextID++), name(name), state(state), race(race), moveAbility(moveAbility) { ammount++; }

	~Character() {
		ammount--;
	};

	Character(const Character& other);
	Character& operator=(const Character& other);
	bool operator<(const Character& other) const;

	int getID() const { return ID; }
	string getName() const { return name; }
	string getState() const;
	string getRace() const;
	bool getMoveAbility() const { return moveAbility; }
	

	void setName(const string& name) { this->name = name; }
	void setState(const State& state) { this->state = state; }
	void setMoveAbility(const bool& moveAbility) { this->moveAbility = moveAbility; }

	friend ostream& operator << (ostream& os, const Character& character);
};

class Wirard : public Character {

	unsigned int manaTotal;
	unsigned int manaCurrent;
	unsigned int artifactAmmount;
	vector<Artifact> artifacts;

public:
	Wirard() : Character(), manaTotal(0), manaCurrent(0), artifacts(vector<Artifact>()), artifactAmmount(artifacts.size()) {};

	Wirard(Race race, string name, int manaCurrent, int manaTotal = 0, int atrifactsAmmount = 0);
		
		

	int getManaTotal() const { return manaTotal; };
	int getManaCurrent() const { return manaCurrent; };
	int getArtifactAmmount() const { return artifactAmmount; };
	vector<Artifact> getArtifacts() const { return artifacts; };


	void setManaTotal(const int& manaTotal) { this->manaTotal = manaTotal; };
	void setManaCurrent(const int& manaCurrent) { this->manaCurrent = manaCurrent; };
	void addArtifact(const Artifact& artifact) { this->artifacts.push_back(artifact); };

	Wirard& operator=(const Wirard& other);

	friend ostream& operator<<(ostream& os, const Wirard& wizard);

};









//
//
//#include <iostream>
//#include <string>
//
//enum class Condition { NORMAL, PARALYZED, DEAD };
//enum class Race { HUMAN, DWARF, ELF };
//enum class ArtifactType { TYPE1, TYPE2, TYPE3 };
//
//class Character {
//protected:
//    static int nextId;
//    int id;
//    std::string name;
//    Condition condition;
//    const Race race;
//    bool canMove;
//    static int numObjects;
//
//public:
//    Character(std::string name, Race race, bool canMove) :
//        name(name), race(race), canMove(canMove), id(nextId++), numObjects(numObjects++) {
//        condition = Condition::NORMAL;
//    }
//
//    Character(const Character& other) :
//        name(other.name), race(other.race), canMove(other.canMove), id(nextId++), numObjects(numObjects++) {
//        condition = other.condition;
//    }
//
//    Character& operator=(const Character& other) {
//        if (this != &other) {
//            name = other.name;
//            race = other.race;
//            canMove = other.canMove;
//            condition = other.condition;
//        }
//        return *this;
//    }
//
//    bool operator<(const Character& other) const {
//        return id < other.id;
//    }
//
//    friend std::ostream& operator<<(std::ostream& os, const Character& character);
//
//    // Getters and setters
//    int getId() const { return id; }
//    std::string getName() const { return name; }
//    Condition getCondition() const { return condition; }
//    Race getRace() const { return race; }
//    bool getCanMove() const { return canMove; }
//    static int getNumObjects() { return numObjects; }
//
//    void setName(std::string name) { this->name = name; }
//    void setCondition(Condition condition) { this->condition = condition; }
//    void setCanMove(bool canMove) { this->canMove = canMove; }
//};
//
//int Character::nextId = 0;
//int Character::numObjects = 0;
//
//std::ostream& operator<<(std::ostream & os, const Character & character) {
//    os << "Character id: " << character.id << ", Name: " << character.name
//        << ", Race: " << static_cast<int>(character.race) << ", Condition: " << static_cast<int>(character.condition)
//        << ", Can move: " << (character.canMove ? "Yes" : "No");
//    return os;
//}
//
//class MagicalCharacter : public Character {
//    int maxMana;
//    int currentMana;
//    int numArtifacts;
//    ArtifactType* artifacts;
//
//public:
//    MagicalCharacter(std::string name, Race race, bool canMove, int maxMana, int numArtifacts) :
//        Character(name, race, canMove), maxMana(maxMana), numArtifacts(numArtifacts) {
//        currentMana = maxMana;
//        artifacts = new ArtifactType[numArtifacts];
//    }
//
//    ~MagicalCharacter() {
//        delete[] artifacts;
//    }
//
//    // Add copy constructor, assignment operator, getters and setters here...
//
//    friend std::ostream& operator<<(std::ostream& os, const MagicalCharacter& character);
//};
//
//std::ostream& operator<<(std::ostream & os, const MagicalCharacter & character) {
//    os << static_cast<const Character&>(character);
//    os << ", Max mana: " << character.maxMana << ", Current mana: " << character.currentMana
//        << ", Number of artifacts: " << character.numArtifacts;
//    return os;
//}