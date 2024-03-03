#include <string>
using namespace std;

class weddingDress {
protected:

	struct DressItem {
		string Info;
		DressItem* Next;
	};
	DressItem* First;

public:

	void InsertFirst(const string&); //добавление нового элемента в начало списка
	void InsertLast(const string&); //добавление новогоэлемента в конец списка

	bool DeleteFirst(); //удаление элемента из начала списка
	bool DeleteLast(); //удаление элемента из конца списка 
	bool Delete(const string&); //удаление элемента по значению

	const int Find(const string&) const; //поиск элемента по значению с подсчетом числа сравнений, выполненных в процессе поиска

	const string Top() const; //посмотреть первый элемент списка
	
	void ElementsPrint() const; //печать элементов списка
	
	void ForEach(void fun(string)) const; //выполнить действи€ над всеми элементами списка, не измен€€ его
	void ForEach(void fun(string&)); //выполнить действи€ над всеми элементами списка, измен€€ его
	
	weddingDress() { First = nullptr; } //конструктор без параметров

	weddingDress(const weddingDress&); //конструктор копировани€

	const weddingDress& operator = (const weddingDress&); //оператор присваивани€
	
	virtual ~weddingDress(); //деструктор

	void Erase(); //удаление элементов списка

protected:

	void Clone(const weddingDress&); //клонирование
};