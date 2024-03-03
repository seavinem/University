#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "train.h"
using namespace std;

struct Time {
	int hours;
	int minutes;
	int total;
};

void printCategories() {
	cout << setw(10) << right << "номер поезда" << setfill(' ');
	cout << "\t| " << setw(15) << left << "пункт назначения" << setfill(' ');
	cout << "\t| " << setw(15) << left << "тип поезда" << setfill(' ');
	cout << "\t| " << setw(15) << left << "время отпраления" << setfill(' ');
	cout << "\t| " << setw(10) << left << "время в пути" << endl;
	cout << string(105, '-') << endl;
}

void sorting(vector<Train>& trains) {

	cout << "Упорядочение данных по времени отправления поездов:" << endl << endl;
	printCategories();

	sort(trains.begin(), trains.end());

	for (auto& it : trains) {
		it.printInfo();
	}
}

void isValidTime(const vector <Train> trains, const string time1Str, const string time2Str) {

	cout << "Информация обо всех поездах из заданного диапазона времени " << time1Str << " - " << time2Str << " :" << endl << endl;
	printCategories();

	bool isFound = false;
	Time time1, time2;

	time1.hours = stoi(time1Str.substr(0, time1Str.find(':')));
	time1.minutes = stoi(time1Str.substr(time1Str.find(':') + 1));
	time1.total = time1.minutes + time1.hours * 60;

	time2.hours = stoi(time2Str.substr(0, time2Str.find(':')));
	time2.minutes = stoi(time2Str.substr(time2Str.find(':') + 1));
	time2.total = time2.minutes + time2.hours * 60;


	for (auto& it : trains) {
		if (it.GetTimeLeave() > time1.total && it.GetTimeLeave() < time2.total) {
			it.printInfo();
			isFound = true;
		}
	}

	if (!isFound) {
		cout << "Нет поездов в заданном диапазоне времени" << endl;
	}
}

void isValidDestination(const vector <Train> trains, const string place) {

	cout << "Информация о всех поездах, направляющихся в заданный пункт назначения - " << place << " :" << endl << endl;
	printCategories();

	bool isFound = false;

	for (auto& it : trains) {
		if (it.GetDestination() == place) {
			it.printInfo();
			isFound = true;
		}
	}

	if (!isFound) {
		cout << "Нет поездов, идущих в заданный пункт назначения" << endl;
	}
}

void isValidDestinationForFast(const vector <Train> trains, const string place) {

	cout << "Все скорые поезда, направляющиеся в заданный пункт назначения - " << place << " :" << endl << endl;
	printCategories();

	bool isFound = false;

	for (auto& it : trains) {
		if (it.GetDestination() == place && it.GetType() == "скорый") {
			it.printInfo();
			isFound = true;
		}
	}

	if (!isFound) {
		cout << "Нет поездов типа \"скорый\", идущих в заданный пункт назначения" << endl;
	}
}

void isValidDestinationForTheFastest(const vector <Train> trains, const string place) {

	cout << "Самый быстрый поезд, следующий в заданный пункт назначения - " << place << " :" << endl << endl;
	printCategories();

	vector<pair<int, Train>> timeWayTrains;

	for (auto& it : trains) {
		if (it.GetDestination() == place) {
			timeWayTrains.push_back(make_pair(it.GetTimeWay(), it));
		}
	}

	if (timeWayTrains.size() == 0) {
		cout << "Нет поездов, идущих в заданный пункт назначения" << endl;
	}

	sort(timeWayTrains.begin(), timeWayTrains.end());

	vector<pair<int, Train>>::iterator it = timeWayTrains.begin();
	(*it).second.printInfo();
}

int main() {
	setlocale(LC_ALL, "ru");

	ifstream input("in.txt");

	if (!input) {
		cout << "Ошибка открытия файла" << endl;
		return 1;
	}

	if (input.peek() == EOF) {
		cout << "Файл пуст" << endl;
		return 1;
	}


	Train train;
	vector<Train> trains;
	string time1Str, time2Str, place;

	input >> time1Str >> time2Str >> place;


	if (time1Str.size() == 0 || time2Str.size() == 0 || place.size() == 0) {
		cout << "Недостаточно данных" << endl;
		return 0;
	}


	input.ignore();

	while (input.peek() != EOF) {
		try 
		{
			input >> train;
			trains.push_back(train);
			input.ignore();
		}
		catch (...) {
			cout << "Неверно введена информация о поездах" << endl;
			return 1;
		}
	}

	input.close();

	if (trains.size() != 0) {
		sorting(trains);
		cout << endl << endl;

		isValidTime(trains, time1Str, time2Str);
		cout << endl << endl;

		isValidDestination(trains, place);
		cout << endl << endl;

		isValidDestinationForFast(trains, place);
		cout << endl << endl;

		isValidDestinationForTheFastest(trains, place);
	}
	else {
		cout << "В файле нет информации о поездах" << endl;
	}
}