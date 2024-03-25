#include "KDeque.h"

void KDeque::copy(const KDeque& other) {
    data = new int[other.capacity];

    for (int i = 0; i < other.size; ++i) {
        data[i] = other.data[i];
    }

    size = other.size;
    capacity = other.capacity;
}

void KDeque::resize() {
    int* newData = new int[++capacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

KDeque::KDeque(const KDeque& other) {
    copy(other);
}

KDeque::~KDeque() {
    delete[] data;
}

KDeque& KDeque::operator=(const KDeque& other) {
    if (this != &other) {
        copy(other);
    }
    return *this;
}

int KDeque::Size() const {
    return size;
}

void KDeque::Clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

bool KDeque::IsEmpty() const {
    return size == 0;
}

bool KDeque::IsFull() const {
    return size == capacity;
}

int KDeque::Front() const {
    if (IsEmpty()) {
        throw exception("Deque is empty");
    }
    return data[0];
}

int KDeque::Back() const {
    if (IsEmpty()) {
        throw exception("Deque is empty");
    }
    return data[size - 1];
}

void KDeque::PushFront(const int& value) {
    if (IsFull()) {
        resize();
    }
    for (int i = size - 1; i >= 0; --i) {
        data[i + 1] = data[i];
    }
    data[0] = value;
    ++size;
}

void KDeque::PushBack(const int& value) {
    if (IsFull()) {
        resize();
    }
    data[size++] = value;
}

int KDeque::PopFront() {
    if (IsEmpty()) {
        throw exception("Deque is empty");
    }
    int front = data[0];
    for (int i = 1; i < size; ++i) {
        data[i - 1] = data[i];
    }
    --size;
    return front;
}

int KDeque::PopBack() {
    if (IsEmpty()) {
        throw exception("Deque is empty");
    }
    return data[--size];
}

ostream& operator<<(ostream& os, const KDeque& deque) {
    os << "";
    for (int i = 0; i < deque.size; ++i) {
        os << deque.data[i] << (i < deque.size - 1 ? ", " : "");
    }

    return os;
}


// **Итератор через методы**

KDequeIterator1* KDeque::CreateIterator() const {
    return new KDequeIterator1(this);
}

void KDequeIterator1::First() {
    index = 0;
}

bool KDequeIterator1::IsDone() const {
    return index == deque->size;
}

void KDequeIterator1::Next() {
    ++index;
}

int KDequeIterator1::CurrentItem() const {
    if (IsDone()) {
        throw exception("Iterator is out of bounds");
    }
    return deque->data[index];
}


// **Итератор через операторы**

void KDequeIterator2::operator++() {
    ++index;
}

bool KDequeIterator2::operator()() const {
    return index != deque.size;
}

int KDequeIterator2::operator*() const {
    return deque.data[index];
}


