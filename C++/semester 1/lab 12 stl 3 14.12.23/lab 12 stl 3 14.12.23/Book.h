#pragma once
#include <iostream>
#include <set>
#include <string>
#include "Libruary.h"
using namespace std;


struct Author {
	string firstName;
	string secondName;
	string thirdName;

	bool isEmpty() const {
		return firstName == "" && secondName == "" && thirdName == "";
	}
	bool operator<(const Author& other) const {
		return secondName < other.secondName;
	}
	friend istream& operator >> (istream& input, Author& author) {
		string nameLine;
		getline(input, nameLine);

		string f, s, t;

		s = nameLine.substr(0, nameLine.find(" "));
		f = nameLine.substr(nameLine.find(" ") + 1, nameLine.rfind(" ") - nameLine.find(" ") - 1);
		t = nameLine.substr(nameLine.rfind(" ") + 1);

		author.firstName = f;
		author.secondName = s;
		author.thirdName = t;

		return input;
	}
	friend ostream& operator << (ostream& output, const Author& author) {
		output << author.secondName + " " + author.firstName + " " + author.thirdName;
		return output;
	}
};




class Book {
	friend class Libruary;

protected:

	string UDC;
	string title;
	int year;
	set<Author> authors;

public:

	Book() { year = 0; };
	Book(const string&, const string&, const int&, const set<Author>&);

	void addAuthor(const Author& author);
	bool removeAuthor(const Author& author);

	void printBook() const;
	bool isEmpty() const;

	bool operator < (const Book& other) const;

	friend istream& operator >> (istream& input, Book& book);
	friend ostream& operator << (ostream& output, const Book& book);
};

