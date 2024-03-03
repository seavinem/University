#include <iostream>
#include "Libruary.h"
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Libruary libruary;
	Book bookToAdd, bookToRemove;
	string titleToFind;
	Author authorToFind, authorToAdd, authorToRemove;
	set<Book> found;


	ifstream input("in.txt");
	if (!input) {
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}
	if (input.peek() == EOF) {
		cout << "Файл пуст" << endl;
		return 1;
	}


	string line;

	try {
		input >> bookToAdd;
		input.ignore();

		input >> bookToRemove;
		input.ignore();

		getline(input, titleToFind);
		input.ignore();

		input >> authorToFind;
		input.ignore();

		input >> authorToAdd;
		input.ignore();

		input >> authorToRemove;
		input.ignore();
	}
	catch (...) {
		cout << "Недостаточно данных или информация введена неверно" << endl;
		return 1;
	}

	if (titleToFind.size() == 0 || bookToAdd.isEmpty() || bookToRemove.isEmpty()
		|| authorToAdd.isEmpty() || authorToRemove.isEmpty() || authorToFind.isEmpty()) {
		cout << "Недостаточно данных" << endl;
		return 1;
	}

	while (input.peek() != EOF) {
		try
		{
			Book book;
			input >> book;
			libruary.addBook(book);
		}
		catch (...) {
			cout << "Неверно введена информация о книгах" << endl;
			return 1;
		}
		
	}

	input.close();



	cout << "Все книги библиотеки:" << endl << endl;
	libruary.printBooks();

	cout << endl << "-----------------------------------------------------------------------" << endl << endl;
	cout << "Добавление книги " << bookToAdd << " в библиотеку:" << endl << endl;
	libruary.addBook(bookToAdd);
	libruary.printBooks();

	cout << endl << "-----------------------------------------------------------------------" << endl << endl;
	cout << "Удаление книги " << bookToRemove << " в библиотеку:" << endl << endl;
	if (libruary.removeBook(bookToRemove)) {
		libruary.printBooks();
	}
	
	cout << endl << "-----------------------------------------------------------------------" << endl << endl;
	cout << "Все книги с названием " << titleToFind << endl << endl;
	found = libruary.searchByBookTitle(titleToFind);
	
	bool isSetted = false;
	Book bookAuthor;
	for (auto& it : found) {
		if (!isSetted) {
			bookAuthor = it;
			isSetted = true;
		}

		it.printBook();
		cout << endl;
	}

	cout << endl << "-----------------------------------------------------------------------" << endl << endl;
	cout << "Все книги с автором " << authorToFind << endl << endl;
	found = libruary.searchByAuthor(authorToFind);
	for (auto& it : found) {
		it.printBook();
		cout << endl;
	}

	cout << endl << "-----------------------------------------------------------------------" << endl << endl;
	cout << "Добавление автора " << authorToAdd  << " в книгу " << bookAuthor << endl << endl;
	bookAuthor.addAuthor(authorToAdd);
	bookAuthor.printBook();

	cout << endl << "-----------------------------------------------------------------------" << endl << endl;
	cout << "Удаление автора " << authorToRemove << " из книги " << bookAuthor << endl << endl;
	if (bookAuthor.removeAuthor(authorToRemove)) {
		bookAuthor.printBook();
	}
}