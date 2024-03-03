#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

//      ------- Функция для считывания вагонов со входного пути (файла) ----------

list<unsigned int> GetCarriageEntrance(list<unsigned int>& carriage_entrance) {
    ifstream entrance("A1.txt");
    unsigned int buffer;

    while (!entrance.eof()) {
        entrance >> buffer;
        carriage_entrance.push_back(buffer);
    }

    entrance.close();
    return carriage_entrance;
}

//      ---------- Функция для въезда вагонов в выходной путь(файл) ---------------

void ShowActivity(list<unsigned int>& carriage_entanse, list<unsigned int>& carriage_impasse, list<unsigned int>& carriage_exit) {
    ofstream exit("A2.txt", ios::app);

    exit << "Вход: ";
    for (auto i : carriage_entanse)
        exit << i << " ";
    exit << endl << "Выход: ";
    for (auto i : carriage_exit)
        exit << i << " ";
    exit << endl << "Тупик: ";
    for (auto i : carriage_impasse)
        exit << i << " ";
    exit << endl << endl;

    exit.close();
}

//              Функция для для проверки на наличие:
//              1. в тупике вагона отличного от первого вагона на выходе;
//              2. на входе последнего вагона отличного от первого вагона на выходе.

int CheckWay(list<unsigned int>& carriage_exit, list<unsigned int>& carriage_impasse, list<unsigned int>& carriage_entrance) {
    if (!carriage_impasse.empty() && carriage_exit.back() != carriage_impasse.back()) {
        return 1;
    }
    else if(carriage_exit.back() != carriage_entrance.back()) {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {

    //    ----------------- Проверка на существование входа, выхода и тупика,---------------
    //    ------------ а также создание выхода и тупика, если таковых не найдено -----------

    setlocale(LC_ALL, "Rus");
    ifstream entrance("A1.txt");
    if (!entrance)
    {
        system("pause");
        return 1;
    }

    string line;
    bool isEmpty = true;
    while (getline(entrance, line)) {
        if (line.find_first_not_of(" \n\t") != -1) {
            isEmpty = false;
            break;
        }
    }

    if (isEmpty) {
        cout << "Входной файл пуст" << endl;
        return 1;
    }


    ofstream exit("A2.txt");
    if (!exit)
    {
        entrance.close();
        system("pause");
        return 2;
    }

    entrance.close();
    exit.clear();
    exit.close();

    // вектор для вагонов на входе
    list <unsigned int> carriage_entrance;
    // вектор для вагонов на выходе
    list <unsigned int> carriage_exit;
    // вектор для вагонов в тупике
    list <unsigned int> carriage_impasse;

    // берём информацию о вагонах на входе
    GetCarriageEntrance(carriage_entrance);

    ShowActivity(carriage_entrance, carriage_impasse, carriage_exit);

    // отправляем первый вагон на выход
    carriage_exit.push_back(carriage_entrance.back());
    carriage_entrance.pop_back();
    ShowActivity(carriage_entrance, carriage_impasse, carriage_exit);

    //  ------------ Сортировка вагонов на выход до тех пор, --------------
    //  ------------ пока на входе и в тупике их не останется -------------

    while (!carriage_entrance.empty() || !carriage_impasse.empty()) {
        switch (CheckWay(carriage_exit, carriage_impasse, carriage_entrance)) {

            //  ---------------- Перевозка вагона из тупика ------------------------
            //  ---------------- на вход и из входа на выход -----------------------

        case 1:
            carriage_entrance.push_back(carriage_impasse.back());
            carriage_impasse.pop_back();
            ShowActivity(carriage_entrance, carriage_impasse, carriage_exit);
            carriage_exit.push_back(carriage_entrance.back());
            carriage_entrance.pop_back();
            ShowActivity(carriage_entrance, carriage_impasse, carriage_exit);
            break;

            //  -------- Перевозка вагона из входа на выход (мимо тупика) ---------

        case 2:
            carriage_exit.push_back(carriage_entrance.back());
            carriage_entrance.pop_back();
            ShowActivity(carriage_entrance, carriage_impasse, carriage_exit);
            break;

            //  -------------- Перевозка вагона из входа в тупик -------------------

        case 3:
            carriage_impasse.push_back(carriage_entrance.back());
            carriage_entrance.pop_back();
            ShowActivity(carriage_entrance, carriage_impasse, carriage_exit);
            break;

        default:
            break;
        }
    }

    //  ----------------------------- Конец --------------------------------

    cout << "Задача выполнена успешно" << endl;
    return 0;
}