#pragma once
#include "Alcohol.h"


class Vodka : public Alcohol {



public:
    Vodka(double volume, double price, string brand, string country, double aging, int degree = 40) :
        Alcohol("¬Ó‰Í‡", brand, country, volume, price, degree, aging, false) {}

    ~Vodka() override {}

    void shareWithFriend() override;

    friend ostream& operator<<(ostream& out, const Vodka& drink);
};


class Cognac : public Alcohol {

public:
    Cognac(double volume, double price, string brand, string country, double aging, int degree = 45) :
        Alcohol(" ÓÌ¸ˇÍ", brand, country, volume, price, degree, aging, false) {}

    ~Cognac() override {}

    void shareWithFriend() override;

    friend ostream& operator<<(ostream& out, const Cognac& drink);
};


class —hampagne : public Alcohol {

public:
    —hampagne(double volume, double price, string brand, string country, double aging, int degree = 15) :
        Alcohol("ÿ‡ÏÔ‡ÌÒÍÓÂ", brand, country, volume, price, degree, aging, true) {}

    ~—hampagne() override {}

    void shareWithFriend() override;

    friend ostream& operator<<(ostream& out, const —hampagne& drink);
};


class Wine : public Alcohol {

private:
    string type;

public:
    Wine(string type, double volume, double price, string brand, string country, double aging, int degree = 20) :
        Alcohol("¬ËÌÓ", brand, country, volume, price, degree, aging, false), type(type) {}

    ~Wine() override {}

    void shareWithFriend() override;

    bool operator==(const Wine& other) const;

    friend ostream& operator<<(ostream& out, const Wine& drink);


    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }
};


class Beer : public Alcohol {

private:
    string type;

public:
    Beer(string type, double volume, double price, string brand, string country, int aging = 0, int degree = 5) :
        Alcohol("œË‚Ó", brand, country, volume, price, degree, aging, false), type(type) {}

    ~Beer() override {}

    void shareWithFriend() override;

    bool operator==(const Beer& other) const;

    friend ostream& operator<<(ostream& out, const Beer& drink);


    string getType() const { return type; }
    void setType(const string& type) { this->type = type; }
};