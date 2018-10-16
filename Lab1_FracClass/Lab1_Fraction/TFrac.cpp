#include "TFrac.h"
#include "pch.h"
int TFrac::gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

TFrac::TFrac() {
	this->numerator = 0;
	this->denominator = 1;
}

TFrac::TFrac(int a, int b) {
	if (a < 0 && b < 0) {
		a *= -1;
		b *= -1;
	}
	else if (b < 0 && a > 0) {
		b *= -1;
		a *= -1;
	}
	else if (a == 0 && b == 0 || b == 0 || a == 0 && b == 1) {
		this->numerator = 0;
		this->denominator = 1;
		return;
	}
	this->numerator = a;
	this->denominator = b;
	int gcdResult = gcd(a, b);
	if (gcdResult > 1) {
		this->numerator /= gcdResult;
		this->denominator /= gcdResult;
	}
}

TFrac::TFrac(string fraction) {
	if (fraction.find('/') == string::npos || fraction.size() < 3) {
		this->numerator = 0;
		this->denominator = 1;
		return;
	}

	string strNumerator;
	string strDenominator;
	unsigned int strPointer = 0;
	while (fraction[strPointer] != '/') {
		strNumerator.push_back(fraction[strPointer]);
		strPointer++;
	}
	strPointer++;
	while (strPointer < fraction.size()) {
		strDenominator.push_back(fraction[strPointer]);
		strPointer++;
	}

	if (strDenominator.empty() || strNumerator.empty()) {
		this->numerator = 0;
		this->denominator = 1;
		return;
	}

	this->numerator = stoi(strNumerator);
	this->denominator = stoi(strDenominator);

	int gcdResult = gcd(this->numerator, this->denominator);
	if (gcdResult > 1) {
		this->numerator /= gcdResult;
		this->denominator /= gcdResult;
	}
}

TFrac::TFrac(const TFrac & anotherFrac) {
	this->numerator = anotherFrac.numerator;
	this->denominator = anotherFrac.denominator;
}

TFrac TFrac::operator-() {
	TFrac temp(-this->numerator, this->denominator);
	return temp;
}

TFrac TFrac::add(const TFrac & anotherFrac) {
	TFrac temp;
	temp.numerator = this->numerator * anotherFrac.denominator
		+ anotherFrac.numerator * this->denominator;
	temp.denominator = this->denominator * anotherFrac.denominator;
	int gcdResult = gcd(temp.numerator, temp.denominator);
	if (gcdResult > 1) {
		temp.numerator /= gcdResult;
		temp.denominator /= gcdResult;
	}
	return temp;
}

TFrac TFrac::multiply(const TFrac & anotherFrac) {
	TFrac temp;
	temp.numerator = this->numerator * anotherFrac.numerator;
	temp.denominator = this->denominator * anotherFrac.denominator;
	int gcdResult = gcd(temp.numerator, temp.denominator);
	if (gcdResult > 1) {
		temp.numerator /= gcdResult;
		temp.denominator /= gcdResult;
	}
	return temp;
}

TFrac TFrac::substract(const TFrac & anotherFrac) {
	TFrac temp;
	if (this->numerator == anotherFrac.numerator &&
		this->denominator == anotherFrac.denominator) {
		return TFrac(0, 1);
	}
	temp.numerator = this->numerator * anotherFrac.denominator
		- anotherFrac.numerator * anotherFrac.numerator;
	temp.denominator = this->denominator * anotherFrac.denominator;
	int gcdResult = gcd(temp.numerator, temp.denominator);
	if (gcdResult > 1) {
		temp.numerator /= gcdResult;
		temp.denominator /= gcdResult;
	}
	return temp;
}

TFrac TFrac::divide(const TFrac & anotherFrac) {
	if (anotherFrac.numerator == 0 && anotherFrac.denominator == 1) {
		exit(1);
	}
	TFrac temp;
	temp.numerator = this->numerator * anotherFrac.denominator;
	temp.denominator = this->denominator * anotherFrac.numerator;
	if (temp.numerator < 0 && temp.denominator < 0) {
		temp.numerator *= -1;
		temp.denominator *= -1;
	}
	int gcdResult = gcd(temp.numerator, temp.denominator);
	if (gcdResult > 1) {
		temp.numerator /= gcdResult;
		temp.denominator /= gcdResult;
	}
	return temp;
}

TFrac TFrac::square() {
	return TFrac(this->numerator * this->numerator, this->denominator * this->denominator);
}

TFrac TFrac::reverse() {
	return TFrac(this->numerator > 0 ? this->denominator : -this->denominator,
		this->numerator > 0 ? this->numerator : -this->numerator);
}

bool TFrac::operator==(const TFrac & anotherFrac) {
	if (this->numerator == anotherFrac.numerator && this->denominator == anotherFrac.denominator)
		return true;
	else
		return false;
}

bool TFrac::operator>(const TFrac & anotherFrac) {
	if (float(this->numerator) / float(this->denominator)
		> float(anotherFrac.numerator) / float(anotherFrac.denominator))
		return true;
	else
		return false;
}

TFrac::~TFrac() {}

int TFrac::getNumeratorNumber() {
	return this->numerator;
}

int TFrac::getDenominatorNumber() {
	return this->denominator;
}

string TFrac::getNumeratorString() {
	return string(to_string(this->numerator));
}

string TFrac::getDenominatorString() {
	return string(to_string(this->denominator));
}

string TFrac::getFractionString() {
	return string(to_string(this->numerator) + '/' + to_string(this->denominator));
}
