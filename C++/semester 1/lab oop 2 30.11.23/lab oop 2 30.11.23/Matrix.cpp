#include "Matrix.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



matrix::matrix() {
	m = 0;
	n = 0;
	p = nullptr;
}

matrix::matrix(int m, int n) {
	if (m < 1 || n < 1) {
		throw IncorrectMatrix();
	}

	this->m = m;
	this->n = n;

	p = new double* [m];

	for (int i = 0; i < m; i++) {
		p[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = 0;
		}
	}
}

matrix::matrix(const matrix& m) {
	this->n = m.n;
	this->m = m.m;

	p = new double* [m.m];
	for (int i = 0; i < m.m; i++) {
		p[i] = new double[m.n];
	}

	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			p[i][j] = m.p[i][j];
		}
	}
}

matrix::~matrix() {
	for (int i = 0; i < m; i++)
	{
		delete[] p[i];
	}

	delete[] p;
}



void matrix::operator = (const matrix& m) {
	this->n = m.n;
	this->m = m.m;
	
	if (this != &m) {
		delete[] p;
	}
	p = new double* [m.m];

	for (int i = 0; i < m.m; i++) {
		p[i] = new double[m.n];
	}

	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			p[i][j] = m.p[i][j];
		}
	}
}

void matrix::operator += (const matrix& m) {
	if (!((this->n == m.n) && (this->m == m.m))) {
		throw DifferentFormats();
	}

	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			p[i][j] += m.p[i][j];
		}
	}
}

void matrix::operator -= (const matrix& m) {
	if (!((this->n == m.n) && (this->m == m.m))) {
		throw DifferentFormats();
	}

	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			p[i][j] -= m.p[i][j];
		}
	}
}

void matrix::operator *= (const matrix& m) {
	if (this->n != m.m) {
		throw NoMultiplication();
	}

	matrix temp(this->m, m.n);

	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < m.n; j++) {
			for (int k = 0; k < m.m; k++) {
				temp.p[i][j] += p[i][k] * m.p[k][j];
			}
		}
	}

	*this = temp;
}

void matrix::operator *= (const double& x) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] *= x;
		}
	}
}

void matrix::operator /= (const double& x) {
	if (x == 0) {
		throw DivisionByZero();
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] /= x;
		}
	}
}



matrix matrix::operator / (const double& x) {
	if (x == 0) {
		throw DivisionByZero();
	}

	matrix newM(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			newM.p[i][j] = p[i][j] / x;
		}
	}

	return newM;
}

matrix matrix::operator + (const matrix& m) {
	if (!((this->n == m.n) && (this->m == m.m))) {
		throw DifferentFormats();
	}

	matrix newM(this->m, this->n);


	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			newM.p[i][j] = p[i][j] + m.p[i][j];
		}
	}

	return newM;
}

matrix matrix::operator - (const matrix& m) {
	if (!((this->n == m.n) && (this->m == m.m))) {
		throw DifferentFormats();
	}

	matrix newM(this->m, this->n);

	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			newM.p[i][j] = p[i][j] - m.p[i][j];
		}
	}

	return newM;
}

matrix matrix::operator * (const matrix& m) {
	if (this->n != m.m) {
		throw NoMultiplication();
	}

	matrix newM(this->m, m.n);

	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < m.n; j++) {
			newM.p[i][j] = 0;

			for (int k = 0; k < m.m; k++) {
				newM.p[i][j] += p[i][k] * m.p[k][j];
			}
		}
	}

	return newM;
}



bool matrix::operator == (const matrix& m) const {
	if (this->n == m.n && this->m == m.m) {

		for (int i = 0; i < m.m; i++) {
			for (int j = 0; j < m.n; j++) {

				if (p[i][j] != m.p[i][j]) {
					return false;
				}

			}
		}

	}
	else {
		return false;
	}	
}

bool matrix::operator != (const matrix& m) const {
	if (this->n == m.n && this->m == m.m) {

		for (int i = 0; i < m.m; i++) {
			for (int j = 0; j < m.n; j++) {

				if (p[i][j] != m.p[i][j]) {
					return true;
				}

			}
		}

	}
	else {
		return true;
	}
}



matrix operator * (const matrix& m, const double& x) {
	matrix newM(m.m, m.n);

	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			newM.p[i][j] = m.p[i][j] * x;
		}
	}

	return newM;
}

matrix operator * (const double& x, const matrix& m)
{
	return m * x;
}



istream& operator >> (istream& input, matrix& m) {
	string col, row;

	input >> row >> col;

	for (int i = 0; i < row.length(); i++) {
		if (!isdigit(row[i])) {
			throw IncorrectInput();
		}
	}
	for (int i = 0; i < col.length(); i++) {
		if (!isdigit(col[i])) {
			throw IncorrectInput();
		}
	}

	m.m = stoi(row);
	m.n = stoi(col);

	if (m.m < 1 || m.n < 1) {
		throw IncorrectMatrix();
	}

	m.p = new double* [m.m];
	for (int i = 0; i < m.m; i++) {
		m.p[i] = new double[m.n];
	}


	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			
			string value;
			int pos = 0;
			input >> value;

			if (value[0] == '-' || value[0] == '+') {
				pos = 1;
			}

			for (int i = pos; i < value.length(); i++) {
				if (!isdigit(value[i]) && value[i] != '.') {
					throw IncorrectInput();
				}
			}

			if (value.find('.') != -1) {
				m.p[i][j] = stoi(value.substr(0, value.find('.'))) + stoi(value.substr(value.find('.') + 1)) / pow(10, value.substr(value.find('.') + 1).size());
			}
			else {
				m.p[i][j] = stoi(value);
			}
		}
	}

	return input;
}

ostream& operator << (ostream& output, const matrix& m) {
	for (int i = 0; i < m.m; i++) {
		for (int j = 0; j < m.n; j++) {
			if(m.p[i][j] != (int)m.p[i][j])
				cout.precision(4);

			output << m.p[i][j] << "\t";
		}
		cout << endl;
	}

	return output;
}