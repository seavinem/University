#include "weddingDress.h"
#include <iostream>
using namespace std;



void weddingDress::InsertFirst(const string& DInfo) {
	DressItem* P = new DressItem;
	P->Info = DInfo;
	P->Next = First;
	First = P;
}

void weddingDress::InsertLast(const string& DInfo) {
	DressItem* P = new DressItem;
	P->Info = DInfo;
	P->Next = nullptr;

	if (First == nullptr) {
		First = P;
	}
	else {
		DressItem* Last = First;
		while (Last->Next != nullptr) {
			Last = Last->Next;
		}
		Last->Next = P;
	}
}



bool weddingDress::DeleteFirst() {
	if(First == nullptr)
		return false;

	DressItem* P = First;
	First = First->Next;
	delete P;
	return true;
}

bool weddingDress::DeleteLast()
{
	if (First == nullptr)
		return false;

	if (First->Next == nullptr) {
		delete First;
		First = nullptr;
	}
	else {
		DressItem* Last = First;
		while (Last->Next->Next != nullptr) {
			Last = Last->Next;
		}
		delete Last->Next;
		Last->Next = nullptr;
	}

	return true;
}

bool weddingDress::Delete(const string& DInfo) {
	if (First == nullptr)
		return false;

	if (First->Info == DInfo) {
		DressItem* P = First;
		P = P->Next;
		delete P;
	}
	else {
		DressItem* P = First;

		while (P->Next != nullptr && P->Next->Info != DInfo) {
			P = P->Next;
		}

		if (P->Next == nullptr) {
			return false;
		}

		DressItem* X = P->Next;
		P->Next = P->Next->Next;
		delete X;
	}

	return true;
}



const int weddingDress::Find(const string& DInfo) const {
	DressItem* P = First;
	int count = 0;
	bool isFound = false;
	while (P != nullptr) {
		count++;
		if (P->Info == DInfo) {
			isFound = true;
			break;
		}
		P = P->Next;
	}

	if (isFound) {
		return count;
	}
	else {
		return -1;
	}
}


const string weddingDress::Top() const {
	if (First == nullptr)
		throw "В платье не добавлен ни один элемент";

	string x = First->Info;
	return x;
}



void weddingDress::ElementsPrint() const {
	DressItem* P = First;

	if (P == nullptr) {
		cout << "В платье не добавлен ни один элемент" << endl;
	}
	else {
		cout << "Элементы свадебного платья:" << endl;

		while (P != nullptr) {
			cout << P->Info << endl;
			P = P->Next;
		}
	}
}



void weddingDress::ForEach(void fun(string)) const {
	DressItem* P = First;

	if (P == nullptr) {
		cout << "В платье не добавлен ни один элемент" << endl;
	}
	else {
		while (P != nullptr) {
			fun(P->Info);
			P = P->Next;
		}
	}
}

void weddingDress::ForEach(void fun(string&)) {
	DressItem* P = First;

	if (P == nullptr) {
		cout << "В платье не добавлен ни один элемент" << endl;
	}
	else {
		while (P != nullptr) {
			fun(P->Info);
			P = P->Next;
		}
	}
}



weddingDress::weddingDress(const weddingDress& D) {
	Clone(D);
}


const weddingDress& weddingDress::operator=(const weddingDress& D) {
	if (&D == this) {
		return *this;
	}

	Erase();
	Clone(D);
	return *this;
}


weddingDress::~weddingDress() {
	Erase();
}


void weddingDress::Erase() {
	DressItem* p, * q;
	p = First;

	while (p != nullptr) {
		q = p->Next;
		delete p;
		p = q;
	}

	First = nullptr;
}


void weddingDress::Clone(const weddingDress& D) {
	DressItem* p, * q, * r;
	r = nullptr;
	p = D.First;

	while (p != nullptr) {
		q = new DressItem;
		q->Info = p->Info;
		q->Next = nullptr;

		if (r == nullptr) {
			First = q;
		}
		else {
			r->Next = q;
		}

		r = q;
		p = p->Next;
	}
}
