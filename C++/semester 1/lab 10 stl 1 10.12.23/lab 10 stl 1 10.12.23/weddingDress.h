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

	void InsertFirst(const string&); //���������� ������ �������� � ������ ������
	void InsertLast(const string&); //���������� �������������� � ����� ������

	bool DeleteFirst(); //�������� �������� �� ������ ������
	bool DeleteLast(); //�������� �������� �� ����� ������ 
	bool Delete(const string&); //�������� �������� �� ��������

	const int Find(const string&) const; //����� �������� �� �������� � ��������� ����� ���������, ����������� � �������� ������

	const string Top() const; //���������� ������ ������� ������
	
	void ElementsPrint() const; //������ ��������� ������
	
	void ForEach(void fun(string)) const; //��������� �������� ��� ����� ���������� ������, �� ������� ���
	void ForEach(void fun(string&)); //��������� �������� ��� ����� ���������� ������, ������� ���
	
	weddingDress() { First = nullptr; } //����������� ��� ����������

	weddingDress(const weddingDress&); //����������� �����������

	const weddingDress& operator = (const weddingDress&); //�������� ������������
	
	virtual ~weddingDress(); //����������

	void Erase(); //�������� ��������� ������

protected:

	void Clone(const weddingDress&); //������������
};