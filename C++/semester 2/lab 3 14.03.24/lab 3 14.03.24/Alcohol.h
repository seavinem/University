#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <assert.h>
using namespace std;


// Component

class Alcohol {

protected:
    static int nextId;
    int id;
    string name;
    int aging;
    int price;
    int degree;
    double volume;
    string country;
    string brand;
    bool isCarbonated;

public:
    Alcohol();

    Alcohol(string name, string brand, string country, double volume, int price, int degree, int aging, bool isCarbonated);

    Alcohol(const Alcohol& other);

    virtual ~Alcohol() {}

    virtual void drink() {};
    virtual void shareWithFriend() {};

    virtual double getVolume() = 0;
    virtual int getPrice() = 0;


    /*int getId() const { return id; }
    int getAging() const { return aging; }
    double getVolume() const { return volume; }
    int getPrice() const { return price; }
    int getDegree() const { return degree; }
    string getCountry() const { return country; }
    string getBrand() const { return brand; }

    void setPrice(const int& price) { this->price = price; }
    void setVolume(const double& volume) { this->volume = volume; }
    void setDegree(const int& degree) { this->degree = degree; }
    void setCountry(const string& country) { this->country = country; }
    void setAging(const int& aging) { this->aging = aging; }
    void setBrand(const string& brand) { this->brand = brand; }*/

    Alcohol& operator=(const Alcohol& other);

    bool operator==(const Alcohol& other) const;

    friend ostream& operator<<(ostream& out, const Alcohol& drink);
};


// Primitive

class Vodka : public Alcohol {


public:
    Vodka() : Alcohol() {};
    Vodka(double volume, int price, string brand, string country, int aging, int degree = 40) :
        Alcohol("Водка", brand, country, volume, price, degree, aging, false) {}

    virtual ~Vodka() override {};

    virtual void drink() override { volume -= 0.1; };
    virtual void shareWithFriend() override;

    virtual double getVolume() override { return 0.75; };
    virtual int getPrice() override { return 1000;  };

    friend ostream& operator<<(ostream& out, const Vodka& drink);
};


// Primitive

class Cognac : public Alcohol {

public:
    Cognac() : Alcohol() {};
    Cognac(double volume, int price, string brand, string country, int aging, int degree = 45) :
        Alcohol("Коньяк", brand, country, volume, price, degree, aging, false) {}

    virtual ~Cognac() override {};

    virtual void drink() override { volume -= 0.15; };
    virtual void shareWithFriend() override;

    virtual double getVolume() override { return 1; };
    virtual int getPrice() override { return 2000; };

    friend ostream& operator<<(ostream& out, const Cognac& drink);
};


// Primitive

class Champagne : public Alcohol {

public:
    Champagne() : Alcohol() {};
    Champagne(double volume, int price, string brand, string country, int aging, int degree = 15) :
        Alcohol("Шампанское", brand, country, volume, price, degree, aging, true) {}

    virtual ~Champagne() override {};

    virtual void drink() override { volume -= 0.1; };
    virtual void shareWithFriend() override;

    virtual double getVolume() override { return 0.8; };
    virtual int getPrice() override { return 3000; };

    friend ostream& operator<<(ostream& out, const Champagne& drink);
};


// Primitive

class Wine : public Alcohol {

private:
    string type;

public:
    Wine() : Alcohol(), type("не задано") {};
    Wine(string type, double volume, int price, string brand, string country, int aging, int degree = 20) :
        Alcohol("Вино", brand, country, volume, price, degree, aging, false), type(type) {}

    virtual ~Wine() override {};

    virtual void drink() override { volume -= 0.05; };
    virtual void shareWithFriend() override;

    virtual double getVolume() override { return 1; };
    virtual int getPrice() override { return 5000; };

    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }

    bool operator==(const Wine& other) const;
    friend ostream& operator<<(ostream& out, const Wine& drink);
};


// Primitive

class Beer : public Alcohol {

private:
    string type;

public:
    Beer() : Alcohol(), type("не задано") {};
    Beer(string type, double volume, int price, string brand, string country, int aging = 0, int degree = 5) :
        Alcohol("Пиво", brand, country, volume, price, degree, aging, false), type(type) {}

    virtual ~Beer() override {};

    virtual void drink() override { volume -= 0.2; };
    virtual void shareWithFriend() override;

    virtual double getVolume() override { return 0.5; };
    virtual int getPrice() override { return 500; };

    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }

    bool operator==(const Beer& other) const;
    friend ostream& operator<<(ostream& out, const Beer& drink);
};


// Composite

class Composite : public Alcohol {

    vector<Alcohol*> bar;

public:
    double getVolume() {
        double total = 0;
        for (int i = 0; i < bar.size(); ++i)
            total += bar[i]->getVolume();
        return total;
    }

    int getPrice() {
        double total = 0;
        for (int i = 0; i < bar.size(); ++i)
            total += bar[i]->getPrice();
        return total;
    }

    void addDrink(Alcohol* drink) {
        bar.push_back(drink);
    }

    ~Composite() {
        for (int i = 0; i < bar.size(); ++i)
            delete bar[i];
    }
};
