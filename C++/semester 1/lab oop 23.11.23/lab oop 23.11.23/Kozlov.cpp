#include <iostream>
#include <string>
using namespace std;


class DivisionByZeroException : public exception
{
public:
	const char* what() const throw()
	{
		return "����������� ����� 0 - �� 0 ������ ������";
	}
};
class LessThenZero : public exception
{
public:
	const char* what() const throw()
	{
		return "����������� ������ ���� ������ 0";
	}
};
class ReverseZero : public exception
{
public:
	const char* what() const throw()
	{
		return "� 0 ��� ��������� �����";
	}
};
class IncorrectInput : public exception
{
public:
	const char* what() const throw()
	{
		return "������������ ����";
	}
};



class Fraction {
private:
	int n, d;

	int gcd(int a, int b) {
		a = abs(a);
		while (b != 0) {
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	void reduce(int& num, int& denom) {
		if (denom < 0) {
			num /= -1;
			denom /= -1;
		}
		int gcdNew = gcd(num, denom);
		num /= gcdNew;
		denom /= gcdNew;
	}

public:
	Fraction(int _n, int _d) {
		if (_d == 0) {
			throw DivisionByZeroException();
		}
		if (_d < 0) {
			throw LessThenZero();
		}

		string nWord = to_string(n), dWord = to_string(d);

		for (int i = 0; i < nWord.length(); i++) {
			if (!isdigit(nWord[i])) {
				throw IncorrectInput();
			}
		}

		for (int i = 0; i < dWord.length(); i++) {
			if (!isdigit(dWord[i])) {
				throw IncorrectInput();
			}
		}

		n = _n;
		d = _d;
		reduce(n, d);
	}
	Fraction() {
		n = 1;
		d = 1;
	}
	Fraction(const Fraction& cf) {
		n = cf.n;
		d = cf.d;
	}

	int getN() {
		return n;
	}
	int getD() {
		return d;
	}


	Fraction operator ++ () {
		n += d;
		return Fraction(n, d);
	}
	Fraction operator ++ (int value)
	{
		Fraction temp(n, d);
		n = n + d;
		return temp;
	}
	Fraction operator -- () {
		n -= d;
		return Fraction(n, d);
	}
	Fraction operator -- (int value) {
		Fraction temp(n, d);
		n -= d;
		return temp;
	}

	Fraction operator + (const Fraction& other) {
		int newN = (n * other.d) + (other.n * d);
		int newD = d * other.d;
		return Fraction(newN, newD);
	}
	Fraction operator - (const Fraction& other) {
		int newN = (n * other.d) - (other.n * d);
		int newD = d * other.d;
		return Fraction(newN, newD);
	}
	Fraction operator * (const Fraction& other) {
		int newN = n * other.n;
		int newD = d * other.d;
		return Fraction(newN, newD);
	}
	Fraction operator / (const Fraction& other) {
		int newN = n * other.d;
		int newD = other.n * d;
		if (newD == 0) {
			throw DivisionByZeroException();
		}
		return Fraction(newN, newD);
	}

	Fraction operator + (const int value) {
		int newN = n + d * value;
		int newD = d;
		return Fraction(newN, newD);
	}
	Fraction operator - (const int value) {
		int newN = n + d * value;
		int newD = d;
		return Fraction(newN, newD);
	}
	Fraction operator * (const int value) {
		int newN = n * value;
		int newD = d;
		return Fraction(newN, newD);
	}
	Fraction operator / (const int value) {
		int newN = n;
		int newD = value * d;
		if (newD == 0) {
			throw DivisionByZeroException();
		}
		return Fraction(newN, newD);
	}

	Fraction operator - () {
		return Fraction(-n, d);
	}
	Fraction operator ! () {
		int newChisl = d;
		int newZnam = n;
		if (newZnam == 0) {
			throw ReverseZero();
		}
		reduce(newChisl, newZnam);
		return Fraction(newChisl, newZnam);
	}

	Fraction operator = (const Fraction& other) {
		n = other.n;
		d = other.d;
		return Fraction(n, d);
	}

	void operator += (const Fraction& other) {
		n = (n * other.d) + (other.n * d);
		d *= other.d;
		reduce(n, d);
	}
	void operator -= (const Fraction& other) {
		n = (n * other.d) - (other.n * d);
		d *= other.d;
		reduce(n, d);
	}
	void operator *= (const Fraction& other) {
		n *= other.n;
		d *= other.d;
		reduce(n, d);
	}
	void operator /= (const Fraction& other) {
		n *= other.d;
		d *= other.n;
		reduce(n, d);
		if (d == 0) {
			throw DivisionByZeroException();
		}
	}

	void operator += (const int value) {
		n += d * value;
	}
	void operator -= (const int value) {
		n -= d * value;
	}
	void operator *= (const int value) {
		n *= value;
	}
	void operator /= (const int value) {
		d *= value;
		if (d == 0) {
			throw DivisionByZeroException();
		}
	}


	bool operator == (const Fraction& other) const {
		return (double)n / d == (double)other.n / other.d;
	}
	bool operator != (const Fraction& other) const {
		return (double)n / d != (double)other.n / other.d;
	}
	bool operator < (const Fraction& other) const {
		return (double)n / d < (double)other.n / other.d;
	}
	bool operator <= (const Fraction& other) const {
		return (double)n / d <= (double)other.n / other.d;
	}
	bool operator > (const Fraction& other) const {
		return (double)n / d > (double)other.n / other.d;
	}
	bool operator >= (const Fraction& other) const {
		return (double)n / d >= (double)other.n / other.d;
	}

	operator double() const {
		return (double)n / d;
	}

	friend istream& operator >> (istream& input, Fraction& cf) {
		string nWord, dWord;
		input >> nWord >> dWord;

		for (int i = 0; i < nWord.length(); i++) {
			if (!isdigit(nWord[i])) {
				throw IncorrectInput();
			}
		}

		if (dWord[0] == '-') {
			throw LessThenZero();
		}

		for (int i = 0; i < dWord.length(); i++) {
			if (!isdigit(dWord[i])) {
				throw IncorrectInput();
			}
		}

		cf.n = stoi(nWord);
		cf.d = stoi(dWord);
		cf.reduce(cf.n, cf.d);

		if (cf.d == 0) {
			throw DivisionByZeroException();
		}

		return input;
	}
	friend ostream& operator << (ostream& output, const Fraction& cf) {
		if (cf.n == 0) {
			output << 0;
		}
		else if (cf.d == 1) {
			output << cf.n;
		}
		else {
			output << cf.n << "/" << cf.d;
		}

		return output;
	}
};



void assignmentOperations(Fraction value1, Fraction value2, int num) {
	cout << "������������ c ������� (X ������� ����� ������ ����� - X = " << value1 << "):\n";
	Fraction X = value1;

	X = value2;
	cout << "X = " << value2 << " -> X = " << X << endl;
	X = value1;


	cout << "\n��������� ������������:\n";

	X += value2;
	cout << "X += " << value2 << " -> X = " << X << endl;
	X = value1;

	X -= value2;
	cout << "X -= " << value2 << " -> X = " << X << endl;
	X = value1;

	X *= value2;
	cout << "X *= " << value2 << " -> X = " << X << endl;
	X = value1;

	X /= value2;
	cout << "X /= " << value2 << " -> X = " << X << endl;

	cout << "\n��������� ������������ c ������� (X ������� ����� ������ ����� - X = " << value1 << "):\n";
	X = value1;

	X += num;
	cout << "X += " << num << " -> X = " << X << endl;
	X = value1;

	X -= num;
	cout << "X -= " << num << " -> X = " << X << endl;
	X = value1;

	X *= num;
	cout << "X *= " << num << " -> X = " << X << endl;
	X = value1;

	X /= num;
	cout << "X /= " << num << " -> X = " << X << endl;
}
void numericalOperations(Fraction value1, Fraction value2, int num) {
	cout << "���������:\n";

	Fraction temp = value1, X = ++value1;
	cout << "\n����������:\n";
	cout << "X = ++" << temp << " --- X -> " << X << ",  " << temp << " -> " << value1 << endl;

	value1 = temp;
	X = value1++;
	cout << "�����������:\n";
	cout << "X = " << temp << "++ --- X -> " << X << ",  " << temp << " -> " << value1 << endl;


	cout << "\n���������:\n";

	value1 = temp;
	X = --value1;
	cout << "\n����������:\n";
	cout << "X = --" << temp << " --- X -> " << X << ",  " << temp << " -> " << value1 << endl;

	value1 = temp;
	X = value1--;
	cout << "�����������:\n";
	cout << "X = " << temp << "-- --- X -> " << X << ",  " << temp << " -> " << value1 << endl;
	value1 = temp;


	cout << "\n�������� � �������:\n";

	cout << "�����:\n";
	cout << value1 << " + " << value2 << " = " << value1 + value2 << endl;

	cout << "���������:\n";
	cout << value1 << " - " << value2 << " = " << value1 - value2 << endl;

	cout << "���������:\n";
	cout << value1 << " * " << value2 << " = " << value1 * value2 << endl;

	cout << "�������:\n";
	cout << value1 << " / " << value2 << " = " << value1 / value2 << endl;

	cout << "\n�������� � �������:\n";

	cout << "�����:\n";
	cout << value1 << " + " << num << " = " << value1 + num << endl;

	cout << "���������:\n";
	cout << value1 << " - " << num << " = " << value1 - num << endl;

	cout << "���������:\n";
	cout << value1 << " * " << num << " = " << value1 * num << endl;

	cout << "�������:\n";
	cout << value1 << " / " << num << " = " << value1 / num << endl;
}
void comparisonOperations(Fraction value1, Fraction value2) {
	cout.setf(ios_base::boolalpha);

	cout << "��������� ������:\n";

	cout << value1 << " == " << value2 << " -> " << (value1 == value2) << endl;
	cout << value1 << " != " << value2 << " -> " << (value1 != value2) << endl;
	cout << value1 << " < " << value2 << " -> " << (value1 < value2) << endl;
	cout << value1 << " <= " << value2 << " -> " << (value1 <= value2) << endl;
	cout << value1 << " > " << value2 << " -> " << (value1 > value2) << endl;
	cout << value1 << " >= " << value2 << " -> " << (value1 >= value2) << endl;
}
void FractionToDouble(Fraction value1, Fraction value2) {
	cout << "����� � ���� �������������� �����:\n";
	cout << (double)value1 << '\t' << (double)value2 << endl;
}
void reciprocalOperation(Fraction value1, Fraction value2) {
	cout << "�������� �����:\n";
	cout << value1 << " -> " << !value1 << "\t" << value2 << " -> " << !value2 << endl;
}
void unaryOperation(Fraction value1, Fraction value2) {
	cout << "������� �����:\n";
	cout << "-(" << value1 << ") = " << -value1 << '\n' << "-(" << value2 << ") = " << -value2 << endl;
}



int main() {
	setlocale(LC_ALL, "ru");
	int num;
	string numStr;
	Fraction value1, value2;

	cout << "������� ��� ����� (������ �����: 10 20 - ��� ����� 10/20)" << endl;
	try {
		cout << "��������� � ����������� ������ �����: ";
		cin >> value1;

		cout << "��������� � ����������� ������ �����: ";
		cin >> value2;

		cout << "������� ����� ��� ��������: ";
		cin >> numStr;

		for (int i = 0; i < numStr.length(); i++) {
			if (!isdigit(numStr[i])) {
				 throw IncorrectInput();
			}
		}
		num = stoi(numStr);

		cout << "\n������ �����: " << value1 << "\t������ �����: " << value2 << endl;

		cout << endl;
		assignmentOperations(value1, value2, num);
		cout << endl;
		numericalOperations(value1, value2, num);
		cout << endl;
		comparisonOperations(value1, value2);
		cout << endl;
		FractionToDouble(value1, value2);
		cout << endl;
		reciprocalOperation(value1, value2);
		cout << endl;
		unaryOperation(value1, value2);
	}
	catch (exception& e) {
		cerr << "\n������: " << e.what() << endl;
	}
}