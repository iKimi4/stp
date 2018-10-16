#pragma once
#include <string>
using namespace std;

class TMember {
private:
	int coeff;
	int degree;
public:
	int readDegree();
	void writeDegree(int newDegree);
	int readCoeff();
	void writeCoeff(int newCoeff);
	bool isEqual(TMember anotherClass);
	TMember differentiate();
	double compute(double x);
	string toString();
	bool operator < (const TMember &otherMember) const {
		return this->degree == otherMember.degree ? this->coeff < otherMember.coeff : this->degree < otherMember.degree;
	}
	bool operator > (const TMember &otherMember) const {
		return this->degree == otherMember.degree ? this->coeff > otherMember.coeff : this->degree > otherMember.degree;
	}
	bool operator == (const TMember &otherMember) const {
		return this->degree == otherMember.degree && this->coeff == otherMember.coeff;
	}
	TMember();
	TMember(int newCoeff, int newDegree);
	~TMember();
};

