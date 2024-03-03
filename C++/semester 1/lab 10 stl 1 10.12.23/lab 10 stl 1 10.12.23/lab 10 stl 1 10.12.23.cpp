#include "weddingDress.h"
#include <iostream>
#include <string>
using namespace std;

void view(string Info) {
    cout << "- " << Info << endl;
}

void isUsing(string& Info) {
    Info += " - используется";
}

int main() {
    setlocale(LC_ALL, "ru");

    weddingDress dress;


    cout << "  --- Первое платье:" << endl;
    dress.InsertFirst("Кружевные элементы");
    dress.InsertLast("Стразы и камни");
    dress.ElementsPrint();


    cout << endl;


    cout << "\n  --- Второе платье после копирования элементов из первого платья" << endl;
    weddingDress dressSecond(dress);
    dressSecond.ElementsPrint();


    cout << endl;


    cout << "\n  --- Удаление первого элемента из второго платья:" << endl;
    if (dressSecond.DeleteFirst())
        dressSecond.ElementsPrint();
    else
        cout << "В платье нет элементов" << endl;


    cout << endl;


    cout << "\n  --- Удаление последнего элемента из первого платья:" << endl;
    if (dress.DeleteLast())
        dress.ElementsPrint();
    else
        cout << "В платье нет элементов" << endl;


    cout << endl;


    cout << "\n --- Второе платье после использования оператора присваивания элементов из первого платья" << endl;
    dressSecond = dress;
    dressSecond.ElementsPrint();


    cout << endl;


    cout << "\n --- Добавление элементов \"Ажурная вышивка\" и \"Аппликации из бисера\" в первое платье:" << endl;
    dress.InsertLast("Ажурная вышивка");
    dress.InsertFirst("Аппликации из бисера");
    dress.ElementsPrint();


    cout << endl;


    cout << "\n  --- Удаление \"Ажурная вышивка\" из элементов первго платья:" << endl;
    if (dress.Delete("Ажурная вышивка"))
        dress.ElementsPrint();
    else
        cout << "Элемент не найден" << endl;
    

    cout << endl;


    cout << "\n  --- Удаление \"Стразы и камни\" из элементов первго платья:" << endl;
    if (dress.Delete("Стразы и камни"))
        dress.ElementsPrint();
    else
        cout << "Элемент не найден" << endl;


    cout << endl;


    cout << "\n  --- Поиск элемента \"Кружевные элементы\" в первом платье:" << endl;
    if (dress.Find("Кружевные элементы") != -1)
        cout << " Количество сравнений: " << dress.Find("Кружевные элементы") << endl;
    else
        cout << "Элемент не найден" << endl;


    cout << endl;


    cout << "\n --- Использование ForEach const для просмотра элементов первого платья:" << endl;
    dress.ForEach(view);


    cout << endl;


    cout << "\n --- ForEach для пометки, что все элементы первого платья используются:" << endl;
    dress.ForEach(isUsing);
    dress.ElementsPrint();


    cout << endl;


    cout << "Первый элемент:" << endl;
    try
    {
        cout << dress.Top() << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}
