#pragma once
#include <iostream>
#include <string>
#include <ostream>
using namespace std;

class Alcohol {

private:
    static int nextId;

    string countryForID() {
        string newCountry;
        for (int i = 0; i < 3; i++) {
            newCountry += toupper(country[i]);
        }
        return newCountry;
    }

    void setID() {
        string newCountry;
        for (int i = 0; i < 3; i++) {
            newCountry += toupper(country[i]);
        }

        id = to_string(nextId++) + '.' + name[0] + '.' + newCountry + '.' + to_string(degree) + '.' + to_string(aging);
    }

protected:

    string id;
    string name;
    int aging;
	double price;
	int degree;
    double volume;
	string country;
    string brand;
    bool isCarbonated;

public:

    Alcohol(string name, string brand, string country, double volume, double price, double degree, int aging, bool isCarbonated);

    Alcohol(const Alcohol& other);

    virtual ~Alcohol() {}

    void drink();
    virtual void shareWithFriend();

    string getId() const { return id; }
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
};


