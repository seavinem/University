#include <iostream>
#include "KDeque.h"
using namespace std;

class Employee {
    int age;
    int experience;
public:
    Employee() : age(18), experience(0) {}
    Employee(int age, int experience) : age(age), experience(experience) {}

    bool operator==(const Employee& other) const { 
        return age == other.age && experience == other.experience;
    }
};




template <typename T>
bool equal(const KDeque<T>& deque1, const KDeque<T>& deque2) {
    if (deque1.Size() != deque2.Size()) {
        return false;
    }

    KDequeIterator<T> it1(deque1), it2(deque2);
    for (; it1(); ++it1, ++it2)
        if (!(*it1 == *it2))
            break;

    return !it1() && !it2();
}



int main() {
    setlocale(LC_ALL, "ru");

    // ----------------- int -----------------

    KDeque<int> deque1;
    for (int i = 1; i <= 5; ++i) {
        deque1.PushBack(i);
    }

    KDeque<int> deque2(deque1);
    KDeque<int> deque3(deque1);
    KDeque<int> deque4(deque1);
    KDeque<int> deque5(deque1);

    deque3.PopBack();
    deque5.PopFront();
    deque4.PushBack(2);
    deque5.PushFront(9);

    cout << "**Внешняя функция equal() для типа данных int**" << endl;

    cout << "deque1 == deque2: " << equal(deque1, deque2) << endl;
    cout << "deque1 == deque3: " << equal(deque1, deque3) << endl;
    cout << "deque1 == deque4: " << equal(deque1, deque4) << endl;
    cout << "deque1 == deque5: " << equal(deque1, deque5) << endl;
    cout << endl;


    // ----------------- Employee -----------------

    KDeque<Employee> deque6;
    for (int i = 1; i <= 5; ++i) {
        deque6.PushBack(Employee(i + 5, i));
    }

    KDeque<Employee> deque7(deque6);
    KDeque<Employee> deque8(deque6);
    KDeque<Employee> deque9(deque6);
    KDeque<Employee> deque10(deque6);

    deque8.PopBack();
    deque10.PopFront();
    deque9.PushBack(Employee(19, 3));
    deque10.PushFront(Employee(21, 2));

    cout << "**Внешняя функция equal() для пользовательского класса Employee**" << endl;

    cout << "deque1 == deque2: " << equal(deque6, deque7) << endl;
    cout << "deque1 == deque3: " << equal(deque6, deque8) << endl;
    cout << "deque1 == deque4: " << equal(deque6, deque9) << endl;
    cout << "deque1 == deque5: " << equal(deque6, deque10) << endl;
    cout << endl;

}