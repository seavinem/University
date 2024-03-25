#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <assert.h>
using namespace std;


enum class Alcohol_ID { Vodka_ID = 0, Cognac_ID, Champagne_ID, Wine_ID, Beer_ID };

class Alcohol {

protected:
    static int nextId;
    int id;
    string name;
    int aging;
	double price;
	int degree;
    double volume;
	string country;
    string brand;
    bool isCarbonated;

public:
    Alcohol();
    Alcohol(string name, string brand, string country, double volume, double price, double degree, int aging, bool isCarbonated);

    Alcohol(const Alcohol& other);

    virtual ~Alcohol() {}

    void drink();
    virtual void shareWithFriend();

    int getId() const { return id; }
    int getAging() const { return aging; }
    int getVolume() const { return volume; }
    double getPrice() const { return price; }
    int getDegree() const { return degree; }
    string getCountry() const { return country; }
    string getBrand() const { return brand; }

    void setPrice(const double& price) { this->price = price; }
    void setVolume(const double& volume) { this->volume = volume; }
    void setDegree(const double& degree) { this->degree = degree; }
    void setCountry(const string& country) { this->country = country; }
    void setAging(const int& aging) { this->aging = aging; }
    void setBrand(const string& brand) { this->brand = brand; }

    Alcohol& operator=(const Alcohol& other);

    bool operator==(const Alcohol& other) const;

    friend ostream& operator<<(ostream& out, const Alcohol& drink);



    static Alcohol* createDrink(Alcohol_ID id);
};



class Vodka : public Alcohol {


public:
    Vodka() : Alcohol() {};
    Vodka(double volume, double price, string brand, string country, double aging, int degree = 40) :
        Alcohol("Водка", brand, country, volume, price, degree, aging, false) {}

    ~Vodka() {};

    virtual void shareWithFriend() override;

    friend ostream& operator<<(ostream& out, const Vodka& drink);
};


class Cognac : public Alcohol {

public:
    Cognac() : Alcohol() {};
    Cognac(double volume, double price, string brand, string country, double aging, int degree = 45) :
        Alcohol("Коньяк", brand, country, volume, price, degree, aging, false) {}

    ~Cognac() {};

    virtual void shareWithFriend() override;

    friend ostream& operator<<(ostream& out, const Cognac& drink);
};


class Champagne : public Alcohol {

public:
    Champagne() : Alcohol() {};
    Champagne(double volume, double price, string brand, string country, double aging, int degree = 15) :
        Alcohol("Шампанское", brand, country, volume, price, degree, aging, true) {}

    ~Champagne() {};

    virtual void shareWithFriend() override;

    friend ostream& operator<<(ostream& out, const Champagne& drink);
};


class Wine : public Alcohol {

private:
    string type;

public:
    Wine() : Alcohol(), type("не задано") {};
    Wine(string type, double volume, double price, string brand, string country, double aging, int degree = 20) :
        Alcohol("Вино", brand, country, volume, price, degree, aging, false), type(type) {}

    ~Wine() {};

    virtual void shareWithFriend() override;

    bool operator==(const Wine& other) const;

    friend ostream& operator<<(ostream& out, const Wine& drink);


    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }
};


class Beer : public Alcohol {

private:
    string type;

public:
    Beer() : Alcohol(), type("не задано") {};
    Beer(string type, double volume, double price, string brand, string country, int aging = 0, int degree = 5) :
        Alcohol("Пиво", brand, country, volume, price, degree, aging, false), type(type) {}

    ~Beer() {};

    virtual void shareWithFriend() override;

    bool operator==(const Beer& other) const;

    friend ostream& operator<<(ostream& out, const Beer& drink);


    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }
};


class Factory {
public:
    virtual Alcohol* createDrink() = 0;
    virtual ~Factory() {}
};

class VodkaFactory : public Factory {
public:
    Alcohol* createDrink() override {
        return new Vodka;
    }
};
class CognacFactory : public Factory {
public:
    Alcohol* createDrink() override {
        return new Cognac;
    }
};
class ChampagneFactory : public Factory {
public:
    Alcohol* createDrink() override {
        return new Champagne;
    }
};
class WineFactory : public Factory {
public:
    Alcohol* createDrink() override {
        return new Wine;
    }
};
class BeerFactory : public Factory {
public:
    Alcohol* createDrink() override {
        return new Beer;
    }
};