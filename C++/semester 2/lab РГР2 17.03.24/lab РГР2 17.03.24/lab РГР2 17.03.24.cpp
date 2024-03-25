#include "KDeque.h"
using namespace std;



// **Внешняя функция equal() -> Итератор через методы**
bool equal1(const KDeque& deque1, const KDeque& deque2) {
    if (deque1.Size() != deque2.Size()) {
        return false;
    }

    KDequeIterator1* it1 = deque1.CreateIterator();
    KDequeIterator1* it2 = deque2.CreateIterator();

    for (it1->First(), it2->First(); !it1->IsDone(); it1->Next(), it2->Next()) {
        if (it1->CurrentItem() != it2->CurrentItem()) {
            delete it1;
            delete it2;
            return false;
        }
    }

    delete it1;
    delete it2;
    return true;
}

// **Внешняя функция equal() -> Итератор через операторы**
bool equal2(const KDeque& deque1, const KDeque& deque2) {
    if (deque1.Size() != deque2.Size()) {
        return false;
    }

    KDequeIterator2 it1(deque1), it2(deque2);
    for (; it1(); ++it1, ++it2)
        if (*it1 != *it2)
            break;

    return !it1() && !it2();
}


int main() {
    setlocale(LC_ALL, "ru");

    KDeque deque1;
    for (int i = 1; i <= 5; ++i) {
        deque1.PushBack(i);
    }

    KDeque deque2(deque1);
    KDeque deque3(deque1);
    KDeque deque4(deque1);
    KDeque deque5(deque1);

    deque3.PopBack();
    deque5.PopFront();
    deque4.PushBack(2);
    deque5.PushFront(9);

    cout << "**Внешняя функция equal() -> Итератор через методы**" << endl;

    cout << "deque1 == deque2: " << equal1(deque1, deque2) << endl;
    cout << "deque1 == deque3: " << equal1(deque1, deque3) << endl;
    cout << "deque1 == deque4: " << equal1(deque1, deque4) << endl;
    cout << "deque1 == deque5: " << equal1(deque1, deque5) << endl;
    cout << endl;

    cout << "**Внешняя функция equal() -> Итератор через операторы**" << endl;

    cout << "deque1 == deque2: " << equal2(deque1, deque2) << endl;
    cout << "deque1 == deque3: " << equal2(deque1, deque3) << endl;
    cout << "deque1 == deque4: " << equal2(deque1, deque4) << endl;
    cout << "deque1 == deque5: " << equal2(deque1, deque5) << endl;
    cout << endl;
}