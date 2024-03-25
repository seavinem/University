#include <iostream>
#include <cctype>
#include <vector>
#include "TicketSale.h"

int main() {
    setlocale(LC_ALL, "ru");

    Carriage carriage1("1-й класс", Type::sleeping, 10);
    Carriage carriage2("2-й класс", Type::compartment, 25);
    Carriage carriage3("без класса", Type::general, 50);

    Carriage carriage4("1-й класс", Type::sleeping, 15);
    Carriage carriage5("2-й класс", Type::compartment, 40);
    Carriage carriage6("без класса", Type::general, 75);

    Carriage carriage7 = carriage4;
    Carriage carriage8(carriage5);
    Carriage carriage9(move(carriage6));

    cout << carriage1 << endl
        << carriage7 << endl
        << carriage8 << endl
        << carriage9 << endl;
    cout << endl;

    int* arr1 = new int[3] {10, 15, 15};
    int* arr2 = new int[3] {25, 40, 40};
    int* arr3 = new int[3] {50, 75, 75};

    TicketSale sale1("1-й класс", Type::sleeping, 20, 5, 3, arr1);
    TicketSale sale2("2-й класс", Type::compartment, 45, 10, 3, arr2);
    TicketSale sale3("без класса", Type::general, 80, 15, 3, arr3);

    TicketSale sale4 = sale1;
    TicketSale sale5(move(sale4));

    cout << sale1 << endl
        << sale4 << endl
        << sale5 << endl;



    cout << endl;
    cout << (carriage7 == carriage4) <<endl
        << (sale1 == sale2) << endl
        << (carriage2 == sale2) << endl;
    cout << endl;

    vector<Carriage*> carriages;

    carriages.push_back(&carriage1);
    carriages.push_back(&carriage2);
    carriages.push_back(new Carriage("люкс", Type::general, 15));

    int* arr4 = new int[2] {15, 15};
    carriages.push_back(&sale1);
    carriages.push_back(&sale2);
    carriages.push_back(new TicketSale("люкс", Type::reserved, 15, 10, 2, arr4));

    int sleepingCount = 0, compartmentCount = 0, reservedCount = 0, generalCount = 0, carriageCount = 0, saleCount = 0;

    int countSeat = 15;

    for (const auto& i : carriages) {
        if (typeid(*i).name() == typeid(TicketSale).name())
            saleCount++;
        else
            carriageCount++;

        switch (i->getType())
        {
        case(Type::sleeping):
            sleepingCount++;
            break;
        case(Type::compartment):
            compartmentCount++;
            break;
        case(Type::reserved):
            reservedCount++;
            break;
        case(Type::general):
            generalCount++;
            break;
        default:
            break;
        }

        i->print();
        cout << endl;
    }

    cout << endl;
    cout << "Вагоны спального типа: " << sleepingCount << endl
        << "Вагоны купейного типа: " << compartmentCount << endl
        << "Вагоны плацкартного типа: " << reservedCount << endl
        << "Вагоны общего типа: " << generalCount << endl
        << endl
        << "Объекты класса вагон поезда: " << carriageCount << endl
        << "Объекты класса продажа билетов: " << saleCount << endl;
    cout << endl;



}
