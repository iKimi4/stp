#pragma once
#include <string>
#include <algorithm>
using namespace std;

class TFrac {
private:
	int numerator;
	int denominator;
	int gcd(int a, int b);
public:
	TFrac();
	TFrac(int a, int b);
	TFrac(string fraction);
	TFrac(const TFrac &anotherFrac);
	TFrac operator-();

	TFrac add(const TFrac &anotherFrac);
	TFrac multiply(const TFrac &anotherFrac);
	TFrac substract(const TFrac &anotherFrac);
	TFrac divide(const TFrac &anotherFrac);
	TFrac square();
	TFrac reverse();

	bool operator==(const TFrac &anotherFrac);
	bool operator>(const TFrac &anotherFrac);
	TFrac operator=(const TFrac &anotherFrac) const {
		if (&anotherFrac == this)
			return *this;
		return TFrac(anotherFrac.numerator, anotherFrac.denominator);
	}

	bool operator< (const TFrac & anotherFrac) const {
		if (float(this->numerator) / float(this->denominator)
			< float(anotherFrac.numerator) / float(anotherFrac.denominator))
			return true;
		else
			return false;
	}

	int getNumeratorNumber();
	int getDenominatorNumber();
	string getNumeratorString();
	string getDenominatorString();
	string getFractionString();
	~TFrac();
};
