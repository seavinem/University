#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include "windows.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Чтение данных из DATA.TXT
    ifstream dataFile("DATA.TXT");
    if (!dataFile.is_open()) {
        cerr << "Input file error!\n";
        return 1;
    }
    if (dataFile.peek() == EOF) {
        cout << "Data file is empty\n";
        return 1;
    }

    map<string, vector<pair<string, int>>> hotelsByCity;
    string line;

    while (getline(dataFile, line)) {
        string city, hotelName;
        int stars;
        unsigned pos1 = 0;
        unsigned pos2 = 0;

        pos2 = line.find_first_of(";");
        city = line.substr(pos1, pos2 - pos1);
        pos1 = line.find_first_not_of(";", pos2);

        pos2 = line.find_first_of(";", pos1);
        hotelName = line.substr(pos1, pos2 - pos1);
        pos1 = line.find_first_not_of(";", pos2);

        stars = stoi(line.substr(pos1, line.size() - pos1));

        hotelsByCity[city].push_back(make_pair(hotelName, stars));
    }

    dataFile.close();

    // Обработка запросов из QUERY.TXT
    ifstream queryFile("QUERY.TXT");
    ofstream answerFile("ANSWER.TXT");

    if (!queryFile.is_open()) {
        cerr << "Input file error!\n";
        return 1;
    }
    if (!answerFile.is_open()) {
        cerr << "Output file error!\n";
        return 1;
    }
    if (queryFile.peek() == EOF) {
        cout << "Data file is empty\n";
        return 1;
    }

    while (getline(queryFile, line)) {
        stringstream lineStream(line);
        string type, value;
        lineStream >> type >> value;
        type = type.substr(0, type.size() - 1);

        if (type == "1") {
            // Запрос по городу
            auto it = hotelsByCity.find(value);
            if (it != hotelsByCity.end()) {
                answerFile << "Город: " << value << endl;
                for (const auto& hotel : it->second) {
                    cout << "  " << hotel.first << ", " << hotel.second << " звезд" << endl;
                    answerFile << "  " << hotel.first << ", " << hotel.second << " звезд" << endl;
                }
            }
            else {
                cout << "Город " << value << " не найден." << endl;
                answerFile << "Город " << value << " не найден." << endl;
            }
        }
        else if (type == "2") {
            // Запрос по названию отеля
            int count = 0;
            for (const auto& cityHotels : hotelsByCity) {
                if (any_of(cityHotels.second.begin(), cityHotels.second.end(), [&value](const pair<string, int> hotel) {
                    return hotel.first == value;
                    })) {
                    count++;
                }
            }
            cout << "Отель " << value << " найден в " << count << " городах." << endl;
            answerFile << "Отель " << value << " найден в " << count << " городах." << endl;
        }
        else if (type == "3") {
            // Запрос всех пар <город, количество звезд>
            set<pair<string, int>> uniquePairs;
            for (const auto& cityHotels : hotelsByCity) {
                for (const auto& hotel : cityHotels.second) {
                    uniquePairs.insert({ cityHotels.first, hotel.second });
                }
            }
            cout << "Уникальные пары <город, количество звезд>:" << endl;
            answerFile << "Уникальные пары <город, количество звезд>:" << endl;
            for (const auto& pair : uniquePairs) {
                cout << "  " << pair.first << ", " << pair.second << " звезд" << endl;
                answerFile << "  " << pair.first << ", " << pair.second << " звезд" << endl;
            }
        }
        else {
            cout << "Неизвестный тип запроса." << endl;
            answerFile << "Неизвестный тип запроса." << endl;
        }
        cout << endl;
        answerFile << endl;
    }
    queryFile.close();
    answerFile.close();

    return 0;
}





//
//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
//#include <fstream>
//#include <assert.h>
//
//bool find_pair(const std::vector<std::pair<std::string, int>>& vec, std::pair<std::string, int>& p) {
//	for (const auto& i : vec) {
//		if (i == p) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//
//	std::ifstream in("DATA.TXT");
//	if (!in.is_open()) {
//		std::cerr << "Input file error!\n";
//		return 1;
//	}
//	if (in.peek() == EOF) {
//		std::cout << "Data file is empty\n";
//		return 1;
//	}
//
//	std::map<std::string, std::pair<std::string, int>> m;
//	std::string line;
//	std::string city, name;
//	int amount_of_stars;
//
//	while (getline(in, line)) {
//		unsigned pos1 = 0;
//		unsigned pos2 = 0;
//		pos2 = line.find_first_of(";");
//		city = line.substr(pos1, pos2 - pos1);
//		pos1 = line.find_first_not_of(";", pos2);
//
//		pos2 = line.find_first_of(";", pos1);
//		name = line.substr(pos1, pos2 - pos1);
//		pos1 = line.find_first_not_of(";", pos2);
//
//		amount_of_stars = stoi(line.substr(pos1, line.size() - pos1));
//		m.insert(std::make_pair(city, std::make_pair(name, amount_of_stars)));
//	}
//	in.close();
//
//
//
//	std::ofstream out("ANSWER.TXT");
//	std::ifstream in1("QUERY.TXT");
//	if (!in1.is_open()) {
//		std::cerr << "Input file error!\n";
//		return 1;
//	}
//	if (!out.is_open()) {
//		std::cerr << "Output file error!\n";
//		return 1;
//	}
//	if (in1.peek() == EOF) {
//		std::cout << "Data file is empty\n";
//		return 1;
//	}
//
//
//	std::vector<std::pair<std::string, int>> vec;
//	bool flag;
//	while (getline(in1, line)) {
//		char oper = line[0];
//		switch (oper) {
//
//		case '1':
//			std::cout << "1st operation...\n";
//			flag = true;
//			city = line.substr(2, line.size() - 2);
//			out << "Hotels in " << city << ":\n";
//			for (const auto& i : m) {
//				if (city == i.first) {
//					out << i.second.first << " " << i.second.second << " star/s\n";
//					flag = false;
//				}
//			}
//			if (flag)
//				out << "No any hotels there\n";
//			out << "============================\n";
//			break;
//
//
//		case '2':
//			std::cout << "2nd operation...\n";
//			flag = true;
//			name = line.substr(2, line.size() - 2);
//			out << "Cities, where you can find " << name << ":\n";
//			for (const auto& i : m) {
//				if (name == i.second.first) {
//					out << i.first << "\n";
//					flag = false;
//				}
//			}
//			if (flag)
//				out << "No any cities where you can find " << name << "\n";
//			out << "============================\n";
//			break;
//
//
//		case '3':
//			std::cout << "3rd operation...\n";
//			out << "Different pairs:\n";
//			vec.clear();
//			for (const auto& i : m) {
//				std::pair<std::string, int> p = std::make_pair(i.second.first, i.second.second);
//				if (!find_pair(vec, p)) {
//					vec.push_back(p);
//					out << i.second.first << "," << i.second.second << "\n";
//				}
//			}
//			out << "============================\n";
//			break;
//
//
//		default:
//			assert(false);
//			break;
//		}
//	}
//
//	in1.close();
//	out.close();
//};