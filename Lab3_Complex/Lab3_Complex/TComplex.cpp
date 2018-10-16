#include "stdafx.h"
#include "TComplex.h"
#include <cmath>
#include <string>
const double PI = 3.14159265359;

TComplex::TComplex() {
}

TComplex::TComplex(double anReal, double anImaginary) {
	this->real = anReal;
	this->imaginary = anImaginary;
}

TComplex::TComplex(string number) {
}

TComplex::TComplex(const TComplex & anClass) {
	this->real = anClass.real;
	this->imaginary = anClass.imaginary;
}

TComplex TComplex::add(const TComplex & anClass) {
	return TComplex(this->real + anClass.real, this->imaginary + anClass.imaginary);
}

TComplex TComplex::multiply(const TComplex & anClass) {
	return TComplex(this->real * anClass.real - this->imaginary * anClass.imaginary, 
		this->real * anClass.imaginary + this->imaginary * anClass.real);
}

TComplex TComplex::square() {
	return TComplex(this->real * this->real - this->imaginary * this->imaginary, 
		this->real * this->imaginary + this->real * this->imaginary);
}

TComplex TComplex::reverse() {
	return TComplex(this->real / (this->real * this->real + this->imaginary * this->imaginary), -this->imaginary / (this->real * this->real + this->imaginary * this->imaginary));
}

TComplex TComplex::subtract(const TComplex & anClass) {
	return TComplex(this->real - anClass.real, this->imaginary - anClass.imaginary);
}

TComplex TComplex::divide(const TComplex & anClass) {
	return TComplex((this->real * anClass.real + this->imaginary * anClass.imaginary)/(anClass.real * anClass.real + anClass.imaginary * anClass.imaginary),
		(anClass.real * this->imaginary - this->real * anClass.imaginary) / (anClass.real * anClass.real + anClass.imaginary * anClass.imaginary));
}

TComplex TComplex::operator-() {
	return TComplex(this->real != 0 ? -this->real : 0, this->imaginary != 0 ? -this->imaginary : 0);
}
double TComplex::abs() {
	return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}
double TComplex::getRad() {
	if (real > 0)
		return atan(imaginary / real);
	if (real == 0 && imaginary > 0)
		return(PI / 2);
	if (real < 0)
		return(atan(imaginary / real) + PI);
	if (real == 0 && imaginary < 0)
		return(-PI / 2);
	return 0;
}

double TComplex::getDegree() {
	return getRad() * 180 / PI;
}

TComplex TComplex::getPow(int n) {
	return TComplex(pow(abs(), n) * cos(n * getRad()), pow(abs(), n) * sin(n * getRad()));
}

TComplex TComplex::getSqrt(int powN, int rootI) {
	if (powN == 0)
		return TComplex(1, 0);
	if (rootI == 0)
		exit(1);
	TComplex new1 = getPow(powN);
	return TComplex(pow(new1.abs(), 1 / (double)rootI) * cos((new1.getRad() + 2 * PI * rootI) / rootI), pow(new1.abs(), 1 / (double)rootI) * sin((new1.getRad() + 2 * PI * rootI) / rootI));
}

bool TComplex::operator==(const TComplex & anClass) {
	return (this->real == anClass.real && this->imaginary == anClass.imaginary);
}

bool TComplex::operator!=(const TComplex & anClass) {
	return (this->real != anClass.real || this->imaginary != anClass.imaginary);
}

double TComplex::getRealNumber() {
	return this->real;
}

double TComplex::getImaginaryNumber() {
	return this->imaginary;
}

string TComplex::getRealString() {
	return to_string(this->real);
}

string TComplex::getImaginaryString() {
	return to_string(this->imaginary);
}

string TComplex::getString() {
	string realPart = to_string(this->real);
	realPart.erase(realPart.find_last_not_of('0') + 1, std::string::npos); 
	realPart.erase(realPart.find_last_not_of('.') + 1, std::string::npos);
	string imaginaryPart = to_string(fabs(this->imaginary));
	imaginaryPart.erase(imaginaryPart.find_last_not_of('0') + 1, std::string::npos); 
	imaginaryPart.erase(imaginaryPart.find_last_not_of('.') + 1, std::string::npos);
	return string(realPart + ' ' + (this->imaginary >= 0 ? '+' : '-') + " i * " + imaginaryPart);
}

TComplex::~TComplex() {
}
