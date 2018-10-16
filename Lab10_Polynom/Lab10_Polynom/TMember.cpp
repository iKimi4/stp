#include "stdafx.h"
#include "TMember.h"

TMember::TMember() {
}

TMember::TMember(int newCoeff, int newDegree) {
	this->coeff = newCoeff;
	this->degree = newDegree;
}

TMember::~TMember() {

}

int TMember::readDegree() {
	return this->degree;
}

void TMember::writeDegree(int newDegree) {
	this->degree = newDegree;
}

int TMember::readCoeff() {
	return this->coeff;
}

void TMember::writeCoeff(int newCoeff) {
	this->coeff = newCoeff;
}

bool TMember::isEqual(TMember anotherClass) {
	return (this->coeff == anotherClass.coeff && this->degree == anotherClass.degree);
}

TMember TMember::differentiate() {
	return TMember(this->degree == 0 ?
		0 : this->coeff * this->degree,
		this->degree == 0 ? 0 : this->degree - 1);
}

double TMember::compute(double x) {
	return (this->coeff * pow(x, this->degree));
}

string TMember::toString() {
	if (this->coeff == 0)
		return string("0");
	else
		return string(to_string(this->coeff)
			+ "*x^" + to_string(this->degree));
}
