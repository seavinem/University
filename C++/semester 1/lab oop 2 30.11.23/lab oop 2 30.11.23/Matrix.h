#include <iostream>
using namespace std;

class matrix {

	int m, n;
	double** p;

public:

	matrix();
	matrix(int m, int n);
	matrix(const matrix& m);
	~matrix();


	void operator = (const matrix& m);


	void operator += (const matrix& m);
	void operator -= (const matrix& m);
	void operator *= (const matrix& m);
	void operator *= (const double& x);
	void operator /= (const double& x);


	friend matrix operator * (const matrix& m, const double& x);
	friend matrix operator * (const double& x, const matrix& m);


	matrix operator / (const double& x);


	matrix operator + (const matrix& m);
	matrix operator - (const matrix& m);
	matrix operator * (const matrix& m);


	bool operator == (const matrix& m) const;
	bool operator != (const matrix& m) const;


	friend istream& operator >> (istream& input, matrix& m);
	friend ostream& operator << (ostream& output, const matrix& m);
};



class DivisionByZero : public exception {
public:
	const char* what() const throw()
	{
		return "На 0 делить нельзя";
	}
};

class DifferentFormats: public exception {
public:
	const char* what() const throw()
	{
		return "У матриц разные форматы - такие матрица нельзя складывать и вычитать";
	}
};

class NoMultiplication : public exception
{
public:
	const char* what() const throw()
	{
		return "Для умножения двух матриц, число столбцов первой матрицы должно быть равно число строк второй";
	}
};

class IncorrectInput : public exception
{
public:
	const char* what() const throw()
	{
		return "Недопустимый ввод";
	}
};

class IncorrectMatrix : public exception
{
public:
	const char* what() const throw()
	{
		return "Недопустимый размер матрицы";
	}
};