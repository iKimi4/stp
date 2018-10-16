#pragma once
#include <string>
using namespace std;
class TComplex {
private:
	double real;
	double imaginary;
public:
	TComplex();
	TComplex(double anReal, double anImaginary);
	TComplex(string number);
	TComplex(const TComplex &anClass);

	TComplex add(const TComplex &anClass);
	TComplex multiply(const TComplex &anClass);
	TComplex square();
	TComplex reverse();
	TComplex subtract(const TComplex &anClass);
	TComplex divide(const TComplex &anClass);
	TComplex operator-();
	double abs();
	double getRad();
	double getDegree();
	TComplex getPow(int n);
	TComplex getSqrt(int n, int i);

	bool operator==(const TComplex &anClass);
	bool operator!=(const TComplex &anClass);

	double getRealNumber();
	double getImaginaryNumber();
	string getRealString();
	string getImaginaryString();
	string getString();

	~TComplex();
};

