#include "Book.h"

void Book::printBook() const {
    cout << "Название: " << title << endl
        << "УДК: " << UDC << endl
        << "Год издания: " << year << endl;

    string aStr;

    for (auto& it : authors) {
        aStr += it.secondName + " " + it.firstName + " " + it.thirdName + ", ";
    }
    
    if (authors.size() == 1) {
        cout << "Автор: ";
    }
    else {
        cout << "Авторы: ";
    }

    cout << aStr.substr(0, aStr.size() - 2) << endl;
}

bool Book::isEmpty() const {
    return UDC == "" && title == "" && year == 0 && authors.size() == 0;

}

Book::Book(const string& udc, const string& title, const int& year, const set<Author>& authors) {
    this->UDC = udc;
    this->title = title;
    this->year = year;
    this->authors = authors;
}

void Book::addAuthor(const Author& author) {
    if (authors.find(author) != authors.end()) {
        cout << "Такой автор уже есть в книге, поэтому результат не изменится" << endl;
    }
    authors.insert(author);
}

bool Book::removeAuthor(const Author& author) {
    if (authors.find(author) != authors.end()) {
        authors.erase(author);
        return true;
    }
    
    cout << "В книге нет такого автора" << endl;
    return false;
}

bool Book::operator<(const Book& other) const {
    if (title != other.title) {
        return title < other.title;
    }
    else if (year != other.year) {
        return year < other.year;
    }
    else {
        return authors < other.authors;
    }
}

istream& operator>>(istream& input, Book& book) {
    string line;
    getline(input, line);
    int start = 0, end = 0;


    book.UDC = line.substr(0, line.find_first_of('|', start) - 1);
    line.erase(0, line.find_first_of('|', start) + 2);


    book.title = line.substr(0, line.find_first_of('|', start) - 1);
    line.erase(0, line.find_first_of('|', start) + 2);
    
    string x = line.substr(0, line.find_first_of('|', start) - 1);

    book.year = stoi(line.substr(0, line.find_first_of('|', start) - 1));
    line.erase(0, line.find_first_of('|', start) + 2);


    while (line.find_first_not_of(",", end) != -1) {
        start = line.find_first_not_of(", ", end);
        end = line.find_first_of(",", start);

        string nameLine;
        string f, s, t;

        if (end != -1) {
            nameLine = line.substr(start, end - start);
        }
        else {
            nameLine = line.substr(start);
        }

        s = nameLine.substr(0, nameLine.find(" "));
        f = nameLine.substr(nameLine.find(" ") + 1, nameLine.rfind(" ") - nameLine.find(" ") - 1);
        t = nameLine.substr(nameLine.rfind(" ") + 1);

        Author author;
        author.firstName = f;
        author.secondName = s;
        author.thirdName = t;

        book.authors.insert(author);

    }

    return input;
}
ostream& operator<<(ostream& output, const Book& book) {
    cout << book.title
        << " | " << book.UDC
        << " | " << book.year
        << " | ";

    string aStr;

    for (auto& it : book.authors) {
        aStr += it.secondName + " " + it.firstName + " " + it.thirdName + ", ";
    }

    cout << aStr.substr(0, aStr.size() - 2);

    return output;
}
