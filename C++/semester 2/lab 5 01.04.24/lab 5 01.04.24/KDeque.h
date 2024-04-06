#pragma once
#include <iostream>
#include <ostream>
using namespace std;

template <typename T>
class KDequeIterator;

template <typename T>
class KDeque {
private:
    T* data;
    int size;
    int capacity;

    template <typename T>
    friend class KDequeIterator;

    void copy(const KDeque& other) {
        data = new T[other.capacity];

        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i];
        }

        size = other.size;
        capacity = other.capacity;
    };

    void resize() {
        capacity = capacity ? capacity * 2 : 1;
        T* newData = new T[capacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    };

public:
    // Constructors
    KDeque() : data(nullptr), size(0), capacity(0) {}

    KDeque(const KDeque& other) {
        copy(other);
    }

    // Destructor
    ~KDeque() {
        delete[] data;
    }

    // Assignment operator
    KDeque& operator=(const KDeque& other) {
        if (this != &other) {
            copy(other);
        }
        return *this;
    }

    // Methods
    int Size() const {
        return size;
    }

    void Clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size == capacity;
    }

    T Front() const {
        if (IsEmpty()) {
            throw exception("Deque is empty");
        }
        return data[0];
    }

    T Back() const {
        if (IsEmpty()) {
            throw exception("Deque is empty");
        }
        return data[size - 1];
    }

    void PushFront(const T& value) {
        if (IsFull()) {
            resize();
        }
        for (int i = size - 1; i >= 0; --i) {
            data[i + 1] = data[i];
        }
        data[0] = value;
        ++size;
    }

    void PushBack(const T& value) {
        if (IsFull()) {
            resize();
        }
        data[size++] = value;
    }

    T PopFront() {
        if (IsEmpty()) {
            throw exception("Deque is empty");
        }
        T front = data[0];
        for (int i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        --size;
        return front;
    }

    T PopBack() {
        if (IsEmpty()) {
            throw exception("Deque is empty");
        }
        return data[--size];
    }

    // Output operator
    friend ostream& operator<<(ostream& os, const KDeque& deque) {
        os << "[";
        for (int i = 0; i < deque.size; ++i) {
            os << deque.data[i] << (i < deque.size - 1 ? ", " : "");
        }
        os << "]";
        return os;
    }


};


template <typename T>
class KDequeIterator {
private:
    const KDeque<T>& deque;
    int index;

public:
    KDequeIterator(const KDeque<T>& deque) : deque(deque), index(0) {}

    // **Операторы итератора**
    void operator++() {
        ++index;
    };
    bool operator()() const {
        return index != deque.size;
    };
    T operator*() const {
        return deque.data[index];
    };
};
