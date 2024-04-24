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
    map<string, vector<pair<string, int>>> hotelsByCity;
    string line;
    while (getline(dataFile, line)) {
        stringstream lineStream(line);
        string city, hotelName;
        int stars;
        lineStream >> city >> hotelName >> stars;
        hotelsByCity[city].push_back(make_pair(hotelName, stars));
    }

    // Обработка запросов из QUERY.TXT
    ifstream queryFile("QUERY.TXT");
    ofstream answerFile("ANSWER.TXT");
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

    return 0;
}