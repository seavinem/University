#pragma once
#include<iostream>
#include<ostream>
using namespace std;

class KDequeIterator1;
class KDequeIterator2;

class KDeque {
private:
    int* data;
    int size;
    int capacity;

    friend class KDequeIterator1;
    friend class KDequeIterator2;

    void copy(const KDeque& other);
    void resize();

public:

    // Конструкторы
    KDeque() : data(nullptr), size(0), capacity(0) {}

    KDeque(const KDeque& other);

    // Деструктор
    ~KDeque();

    // Перегрузка оператора присваивания
    KDeque& operator=(const KDeque& other);


    // Методы
    int Size() const;
    void Clear();
    bool IsEmpty() const;
    bool IsFull() const;

    int Front() const;
    int Back() const;

    void PushFront(const int& value);
    void PushBack(const int& value);
    int PopFront();
    int PopBack();


    // **Оператор вывода**
    friend ostream& operator<< (ostream& os, const KDeque& deque);


    // **Метод для создания итератора**
    KDequeIterator1* CreateIterator() const;

};

// **Итератор через методы**
class KDequeIterator1 {
private:
    const KDeque* deque;
    int index;

public:
    KDequeIterator1(const KDeque* deque) : deque(deque), index(0) {}

    // **Методы итератора**
    void First();
    bool IsDone() const;
    void Next();
    int CurrentItem() const;
};


// **Итератор через операторы**
class KDequeIterator2 {
private:
    const KDeque& deque;
    int index;

public:
    KDequeIterator2(const KDeque& deque) : deque(deque), index(0) {}

    // **Операторы итератора**
    void operator++();
    bool operator()() const;
    int operator*() const;
};
