#pragma once
#include "TMember.h"
#include <map>
class TPoly {
private:
	map<int, TMember > polynom;
public:
	TPoly();
	TPoly(int coeff, int degree);
	int maxDegree();
	int coeff(int Degree);
	void clear();
	TPoly add(TPoly otherPoly);
	TPoly multiply(TPoly otherPoly);
	TPoly subtract(TPoly otherPoly);
	friend TPoly operator+ (TPoly & ourPoly, TPoly& otherPoly);
	friend TPoly operator- (TPoly & ourPoly, TPoly& otherPoly);
	friend TPoly operator* (TPoly & ourPoly, TPoly& otherPoly);
	TPoly minus();
	TPoly operator- ();
	bool isEqual(TPoly otherPoly);
	bool operator < (const TPoly &otherPoly) const {
		return this->polynom < otherPoly.polynom;
	}
	bool operator > (const TPoly &otherPoly) const {
		return this->polynom > otherPoly.polynom;
	}
	bool operator == (const TPoly &otherPoly) const {
		return this->polynom == otherPoly.polynom;
	}
	TPoly differentiate();
	double compute(double x);
	TMember elem(int pos);
	TMember operator[] (int pos);
	~TPoly();
};

