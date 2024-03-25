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

    // ������������
    KDeque() : data(nullptr), size(0), capacity(0) {}

    KDeque(const KDeque& other);

    // ����������
    ~KDeque();

    // ���������� ��������� ������������
    KDeque& operator=(const KDeque& other);


    // ������
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


    // **�������� ������**
    friend ostream& operator<< (ostream& os, const KDeque& deque);


    // **����� ��� �������� ���������**
    KDequeIterator1* CreateIterator() const;

};

// **�������� ����� ������**
class KDequeIterator1 {
private:
    const KDeque* deque;
    int index;

public:
    KDequeIterator1(const KDeque* deque) : deque(deque), index(0) {}

    // **������ ���������**
    void First();
    bool IsDone() const;
    void Next();
    int CurrentItem() const;
};


// **�������� ����� ���������**
class KDequeIterator2 {
private:
    const KDeque& deque;
    int index;

public:
    KDequeIterator2(const KDeque& deque) : deque(deque), index(0) {}

    // **��������� ���������**
    void operator++();
    bool operator()() const;
    int operator*() const;
};
