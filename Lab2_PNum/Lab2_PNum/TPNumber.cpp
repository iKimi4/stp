#include "stdafx.h"
#include "TPNumber.h"
#include <cmath>
#include <cfenv>
#include <sstream>
using namespace std;

TPNumber::TPNumber() {
}

TPNumber::TPNumber(double a, int b, int c) {
	if (b < 2 || b > 16 || c < 0) {
		this->number = 1;
		this->notation = 10;
		this->precision = 1;
	}
	else {
		this->number = a;
		this->notation = b;
		this->precision = c;
	}
}

TPNumber::TPNumber(string a, string b, string c) {
	double numA = (double)stoi(a);
	int numB = stoi(b);
	int numC = stoi(c);
	if (numA < 2 || numB > 16 || numC < 0) {
		this->number = 1;
		this->notation = 10;
		this->precision = 1;
	}
	else {
		this->number = numA;
		this->notation = numB;
		this->precision = numC;
	}
}

TPNumber::TPNumber(const TPNumber & anotherPNumber) {
	this->number = anotherPNumber.number;
	this->notation = anotherPNumber.notation;
	this->precision = anotherPNumber.precision;
}

TPNumber TPNumber::add(const TPNumber & anotherPNumber) {
	return TPNumber(this->number + anotherPNumber.number, this->notation, this->precision);
}

TPNumber TPNumber::multiply(const TPNumber & anotherPNumber) {
	return TPNumber(this->number * anotherPNumber.number, this->notation, this->precision);
}

TPNumber TPNumber::subtract(const TPNumber & anotherPNumber) {
	return TPNumber(this->number - anotherPNumber.number, this->notation, this->precision);
}

TPNumber TPNumber::divide(const TPNumber & anotherPNumber) {
	return TPNumber(this->number / anotherPNumber.number, this->notation, this->precision);
}

TPNumber TPNumber::reverse() {
	return TPNumber(1 / this->number, this->notation, this->precision);
}

TPNumber TPNumber::square() {
	return TPNumber(this->number * this->number, this->notation, this->precision);
}

double TPNumber::getPNumber() {
	return this->number;
}

string TPNumber::getPString() {
	if (this->number == 0)
		return "0";
	fesetround(FE_UPWARD);
	int leftSide = (int)this->number;
	if (leftSide < 0)
		leftSide *= -1;
	float tempRightSide = 0.0f;
	if (this->number >= 0)
		tempRightSide = this->number - static_cast<int>(leftSide);
	if (this->number < 0)
		tempRightSide = -this->number - static_cast<int>(leftSide);
	string strLeftSide;
	string strRightSide;
	if (leftSide != 0)
		while (leftSide > 0) {
			char symb;
			switch (leftSide % notation) {
				case 0:
					symb = '0';
					break;
				case 1:
					symb = '1';
					break;
				case 2:
					symb = '2';
					break;
				case 3:
					symb = '3';
					break;
				case 4:
					symb = '4';
					break;
				case 5:
					symb = '5';
					break;
				case 6:
					symb = '6';
					break;
				case 7:
					symb = '7';
					break;
				case 8:
					symb = '8';
					break;
				case 9:
					symb = '9';
					break;
				case 10:
					symb = 'A';
					break;
				case 11:
					symb = 'B';
					break;
				case 12:
					symb = 'C';
					break;
				case 13:
					symb = 'D';
					break;
				case 14:
					symb = 'E';
					break;
				case 15:
					symb = 'F';
					break;
			}
			strLeftSide = symb + strLeftSide;
			leftSide /= notation;
		}
	else
		strLeftSide = "0";
	
	if (tempRightSide)
		for (int i = 0; i < precision; ++i) {
			if (tempRightSide == 0) {
				strRightSide.push_back('0');
				continue;
			}
			char symb;
			switch ((int)(tempRightSide * this->notation)) {
				case 0:
					symb = '0';
					break;
				case 1:
					symb = '1';
					break;
				case 2:
					symb = '2';
					break;
				case 3:
					symb = '3';
					break;
				case 4:
					symb = '4';
					break;
				case 5:
					symb = '5';
					break;
				case 6:
					symb = '6';
					break;
				case 7:
					symb = '7';
					break;
				case 8:
					symb = '8';
					break;
				case 9:
					symb = '9';
					break;
				case 10:
					symb = 'A';
					break;
				case 11:
					symb = 'B';
					break;
				case 12:
					symb = 'C';
					break;
				case 13:
					symb = 'D';
					break;
				case 14:
					symb = 'E';
					break;
				case 15:
					symb = 'F';
					break;
			}
			strRightSide.push_back(symb);
			tempRightSide = tempRightSide * notation - (int)(tempRightSide * notation);
		}
	if (!strRightSide.empty())
		strLeftSide.push_back('.');
	if (this->number < 0)
		strLeftSide = "-" + strLeftSide;
	return strLeftSide + strRightSide;
}

int TPNumber::getNotationNumber() {
	return this->notation;
}

string TPNumber::getNotationString() {
	return string(to_string(this->notation));
}

int TPNumber::getprecisionNumber() {
	return this->precision;
}

string TPNumber::getprecisionString() {
	return string(to_string(this->precision));
}

int TPNumber::setNotationNumber(int anotherNotation) {
	if (notation < 2 || notation > 16)
		return 1;
	this->notation = notation;
	return 0;
}

int TPNumber::setNotaionString(string anotherNotation) {
	int anotherNotationNumber = stoi(anotherNotation);
	if (anotherNotationNumber < 2 || anotherNotationNumber > 16)
		return 1;
	this->notation = anotherNotationNumber;
	return 0;
}

int TPNumber::setprecisionNumber(int anotherprecision) {
	if (anotherprecision < 0)
		return 1;
	this->precision = anotherprecision;
	return 0;
}

int TPNumber::setprecisionString(string anotherprecision) {
	int anotherprecisionNumber = stoi(anotherprecision);
	if (anotherprecisionNumber < 0)
		return 1;
	this->precision = anotherprecisionNumber;
	return 0;
}

TPNumber::~TPNumber() {
}

TPNumber TPNumber::operator+(const TPNumber & anotherPNumber) {
	return TPNumber(this->number + anotherPNumber.number, this->notation, this->precision);
}

TPNumber TPNumber::operator*(const TPNumber & anotherPNumber) {
	return TPNumber(this->number * anotherPNumber.number, this->notation, this->precision);
}

TPNumber TPNumber::operator-(const TPNumber & anotherPNumber) {
	return TPNumber(this->number - anotherPNumber.number, this->notation, this->precision);
}

TPNumber operator/(const TPNumber & thisNumber, const TPNumber & anotherPNumber) {
	return TPNumber(thisNumber.number + anotherPNumber.number, thisNumber.notation, thisNumber.precision);
}
