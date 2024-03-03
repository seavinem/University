#include <iostream>
#include <vector>
using namespace std;


class Train {

	struct Time {
		int hours;
		int minutes;
		int total;
	};

	int N;
	string place, type;
	Time timeLeave, timeWay;
public:

	Train();

	int GetTimeLeave() const;
	int GetTimeWay() const;
	string GetDestination() const;
	string GetType() const;

	vector<Train> readTrainsFromFile(const string& file);

	void setTime(const string, Time&);
	void timeToTotal(Time&);
	string timeToString(Time) const;

	void printInfo() const;

	friend istream& operator >> (istream& input, Train& train);
	bool operator < (const Train& other) const;
};