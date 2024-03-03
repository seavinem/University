#include "money.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void money::convert() {
	this->total = 4 * (this->pd * 20 * 12 + this->sh * 12 + this->p);
}

void money::reverseConvert() {;
	double AbsTotal = abs(this->total);

	this->p = AbsTotal / 4;

	this->sh = (int)this->p / 12;
	this->p =(int)this->p % 12;

	this->pd = (int)this->sh / 20;
	this->sh = (int)this->sh % 20;

	if (AbsTotal != this->total) {
		this->p = -this->p;
		this->sh = -this->sh;
		this->pd = -this->pd;
	}
}


money::money() {
	this->pd = 0;
	this->sh = 0;
	this->p = 0;
	this->total = 0;
}

money::money(double pd, double sh, double p) {
	if (p >= 12 || sh >= 20 || p < 0 || sh < 0 || pd < 0) {
		throw IncorrectInput();
	}

	if (p * 4 != (int)p * 4) {
		throw IncorrectCoin();
	}


	this->pd = pd;
	this->sh = sh;
	this->p = p;

	convert();
}


void money::operator = (const money& cash) {
	this->pd = cash.pd;
	this->sh = cash.sh;
	this->p = cash.p;
	this->total = cash.total;
}

money money::operator - () {
	money newCash;
	newCash.total = -this->total;
	newCash.reverseConvert();

	return newCash;
}

void money::operator += (const money& cash) {
	this->total += cash.total;

	(*this).reverseConvert();
}

void money::operator -= (const money& cash) {
	this->total -= cash.total;

	(*this).reverseConvert();
}


money money::operator + (const money& cash)
{
	money newCash;

	newCash.total = this->total + cash.total;
	newCash.reverseConvert();

	return newCash;
}

money money::operator - (const money& cash)
{
	money newCash;

	newCash.total = this->total - cash.total;
	newCash.reverseConvert();

	return newCash;
}


bool money::operator == (const money& cash) const
{
	return this->total == cash.total;
}

bool money::operator < (const money& cash) const
{
	return this->total < cash.total;
}

bool money::operator > (const money& cash) const
{
	return this->total > cash.total;
}


istream& operator >> (istream& input, money& cash)
{
	string pd, sh, p;

	input >> pd >> sh >> p;

	

	for (int i = 0; i < pd.size(); i++) {
		if (!isdigit(pd[i]) && pd[i] != '.') {
			throw IncorrectInput();
		}
	}
	for (int i = 0; i < sh.size(); i++) {
		if (!isdigit(sh[i]) && sh[i] != '.') {
			throw IncorrectInput();
		}
	}
	for (int i = 0; i < p.size(); i++) {
		if (!isdigit(p[i]) && p[i] != '.') {
			throw IncorrectInput();
		}
	}

	if (pd.find('.') != -1) {
		cash.pd = stoi(pd.substr(0, pd.find('.'))) + stoi(pd.substr(pd.find('.') + 1)) / pow(10, pd.substr(pd.find('.') + 1).size());
	}
	else {
		cash.pd = stoi(pd);
	}

	if (sh.find('.') != -1) {
		cash.sh = stoi(sh.substr(0, sh.find('.'))) + stoi(sh.substr(sh.find('.') + 1)) / pow(10, sh.substr(sh.find('.') + 1).size());
	}
	else {
		cash.sh = stoi(sh);
	}

	if (p.find('.') != -1) {
		cash.p = stoi(p.substr(0, p.find('.'))) + stoi(p.substr(p.find('.') + 1)) / pow(10, p.substr(p.find('.') + 1).size());
	}
	else {
		cash.p = stoi(p);
	}
	
	

	if (cash.p >= 12 || cash.sh >= 20 || cash.p < 0 || cash.sh < 0 || cash.pd < 0) {
		throw IncorrectInput();
	}

	if (cash.p * 4 != (int)cash.p * 4) {
		throw IncorrectCoin();
	}

	cash.convert();

	return input;
}

ostream& operator << (ostream& output, const money& cash)
{
	if (cash.pd == 0 && cash.sh == 0 && cash.p == 0) {
		output << "0p.";
	}
	else if (cash.pd != 0 && cash.sh == 0 && cash.p == 0) {
		output << cash.pd << "pd.";
	}
	else if (cash.pd == 0 && cash.sh != 0 && cash.p == 0) {
		output << cash.sh << "sh.";
	}
	else if (cash.pd == 0 && cash.sh == 0 && cash.p != 0) {
		output << cash.p << "p.";
	}
	else if (cash.pd != 0 && cash.sh != 0 && cash.p == 0) {
		output << cash.pd << "pd. " << cash.sh << "sh.";
	}
	else if (cash.pd == 0 && cash.sh != 0 && cash.p != 0) {
		output << cash.sh << "sh. " << cash.p << "p.";
	}
	else if (cash.pd != 0 && cash.sh == 0 && cash.p != 0) {
		output << cash.pd << "pd. " << cash.p << "p.";
	}
	else {
		output << cash.pd << "pd. " << cash.sh << "sh. " << cash.p << "p.";
	}

	return output;
}
