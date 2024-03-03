#pragma once
#include "Book.h"
using namespace std;

class Libruary {

	friend class Book;
	friend struct Author;

	set<Book> libruary;

public:

	Libruary() {};

	void addBook(const Book&);
	bool removeBook(const Book&);

	void printBooks() const;

	set<Book> searchByBookTitle(const string&) const;
	set<Book> searchByAuthor(const Author&) const;
};

