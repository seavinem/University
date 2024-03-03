#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "train.h"
using namespace std;


Train::Train() {
	N = 0;
	place = "";
	type = "";
	timeLeave.hours = 0;
	timeLeave.minutes = 0;
	timeLeave.hours = 0;
	timeLeave.minutes = 0;
}


int Train::GetTimeLeave() const
{
	return timeLeave.total;
}

int Train::GetTimeWay() const
{
	return timeWay.total;
}

string Train::GetDestination() const
{
	return place;
}

string Train::GetType() const
{
	return type;
}

vector<Train> Train::readTrainsFromFile(const string& file) {
	vector<Train> trains;
	ifstream input(file);
	Train train;
	string time1, time2;	

	while (input >> train.N >> train.place >> train.type >> time1 >> time2) {
		train.setTime(time1, train.timeLeave);
		train.setTime(time2, train.timeWay);

		trains.push_back(train);
	}

	return trains;
}


void Train::setTime(const string str, Time& time) {
	int hours = stoi(str.substr(0, str.find(':')));
	int minutes = stoi(str.substr(str.find(':') + 1));

	time.hours = hours;
	time.minutes = minutes;

	timeToTotal(time);
}

void Train::timeToTotal(Time& time) {
	time.total = time.hours * 60 + time.minutes;
}

string Train::timeToString(Time time) const {
	string hoursStr = to_string(time.hours), minutesStr = to_string(time.minutes);
	
	if (hoursStr.size() == 1) {
		hoursStr = '0' + hoursStr;
	}

	if (minutesStr.size() == 1) {
		minutesStr = '0' + minutesStr;
	}

	return hoursStr + ":" + minutesStr;
}


void Train::printInfo() const {
	cout << setw(10) << right << N << setfill(' ');
	cout << "\t| " << setw(15) << left << place << setfill(' ');
	cout << "\t| " << setw(15) << left << type << setfill(' ');
	cout << "\t| " << setw(15) << left << timeToString(timeLeave) << setfill(' ');
	cout << "\t| " << setw(10) << left << timeToString(timeWay) << endl;
}


bool Train::operator<(const Train& other) const {
	return (timeLeave.hours * 60 + timeLeave.minutes) < (other.timeLeave.hours * 60 + other.timeLeave.minutes);
}

istream& operator >> (istream& input, Train& train) {
	string time1, time2;

	input >> train.N >> train.place >> train.type >> time1 >> time2;


	train.setTime(time1, train.timeLeave);
	train.setTime(time2, train.timeWay);

	return input;
}

