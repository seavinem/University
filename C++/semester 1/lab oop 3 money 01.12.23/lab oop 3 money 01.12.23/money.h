#include <iostream>
using namespace std;


class money
{
	double pd, sh, p, total;

	void convert();
	void reverseConvert();

public:

	money();
	money(double pd, double sh, double p);


	void operator = (const money& cash);

	void operator += (const money& cash);
	void operator -= (const money& cash);

	money operator + (const money& cash);
	money operator - (const money& cash);
	money operator - ();

	bool operator == (const money& cash) const;
	bool operator < (const money& cash) const;
	bool operator > (const money& cash) const;

	friend istream& operator >> (istream& input, money& cash);
	friend ostream& operator << (ostream& output, const money& cash);
};

class IncorrectInput : public exception
{
public:
	const char* what() const throw()
	{
		return "������������ ����\n����� ����� ���������������; ���������� ��������� ������ ���� ������ 20, � ���������� ������ - ������ 12";
	}
};

class IncorrectCoin : public exception
{
public:
	const char* what() const throw()
	{
		return "������������ ����\n����� ��������� ������ (\"�������\") ��������� �������� �����";
	}
};