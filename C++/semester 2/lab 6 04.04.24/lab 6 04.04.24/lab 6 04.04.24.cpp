#include "Tree.h"

int main() {
    setlocale(LC_ALL, "ru");

    TreeContainer container;
    container.loadFromFile("trees.txt");

    cout << "----------------------- Информация о деревьях -----------------------" << endl;
    cout << endl;
    container.printTreesInfo();

    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
    container.countTreesByType();
    cout << endl;
    container.countTreesByNameType();

    cout << endl;
    cout << "----------------- Сортированный контейнер деревьев -----------------" << endl;
    cout << endl;
    container.sortTrees();
    container.printTreesInfo();

}