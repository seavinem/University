#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Type { sleeping, compartment, reserved, general };

class Carriage {

protected:
	static int next_ID;
	const int ID;

	string classType;
	Type type;
	const int seatAmmount;
	
public:

	Carriage() = delete;

	Carriage(const string&, const Type&, const int&);

	~Carriage();

	Carriage(const Carriage&);
	Carriage(Carriage&&) noexcept;

	int getID() const;
	string getClassType() const;
	Type getType() const;
	int getSeatAmmount() const;


	void setClassType(const string&);
	void setType(const Type&);


	Carriage& operator=(const Carriage&);
	Carriage& operator=(Carriage&&) noexcept;

	bool operator==(const Carriage&);

	friend ostream& operator<<(ostream&, const Carriage&);

	virtual void print() const;
};

