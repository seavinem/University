#include "Libruary.h"

void Libruary::addBook(const Book& book) {
	if (libruary.find(book) != libruary.end()) {
		cout << "����� ����� ��� ���� � ���������, ������� ��������� �� ���������" << endl;
	}

	libruary.insert(book);
}

bool Libruary::removeBook(const Book& book) {
	if (libruary.find(book) != libruary.end()) {
		libruary.erase(book);
		return true;
	}

	cout << "����� ����� � ���������� ���" << endl;
	return false;
}

void Libruary::printBooks() const {
	for (auto& book : libruary) {
		book.printBook();
		cout << endl;
	}
}

set<Book> Libruary::searchByBookTitle(const string& title) const {
	set<Book> foundBooks;

	for (auto& book : libruary) {
		if (book.title == title) {
			foundBooks.insert(book);
		}
	}

	if(foundBooks.size() == 0) {
		cout << "���� � ����� ��������� ���" << endl;
	}
	return foundBooks;
}

set<Book> Libruary::searchByAuthor(const Author& author) const {
	set<Book> foundByAuthor;

	for (auto& book : libruary) {
		if (book.authors.find(author) != book.authors.end()) {
			foundByAuthor.insert(book);
		}
	}

	if (foundByAuthor.size() == 0) {
		cout << "���� � ����� ������� ���" << endl;
	}
	return foundByAuthor;
}
