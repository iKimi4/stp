#pragma once
#include <string>
#include <cstdio>
using namespace std;

class TPNumber {
private:
	double number;
	int notation;
	int precision;
public:
	TPNumber();
	TPNumber(double a, int b, int c);
	TPNumber(string a, string b, string c);
	TPNumber(const TPNumber &anotherPNumber);
	
	TPNumber add(const TPNumber &anotherPNumber);
	TPNumber multiply(const TPNumber &anotherPNumber);
	TPNumber subtract(const TPNumber &anotherPNumber);
	TPNumber divide(const TPNumber &anotherPNumber);
	TPNumber reverse();
	TPNumber square();

	double getPNumber();
	string getPString(); // work
	int getNotationNumber();
	string getNotationString();
	int getprecisionNumber();
	string getprecisionString();
	int setNotationNumber(int anotherNotation);
	int setNotaionString(string anotherNotation);
	int setprecisionNumber(int anotherprecision);
	int setprecisionString(string anotherprecision);

	TPNumber operator+ (const TPNumber &anotherPNumber);
	TPNumber operator* (const TPNumber &anotherPNumber);
	TPNumber operator- (const TPNumber &anotherPNumber);
	friend TPNumber operator/ (const TPNumber &thisNumber, const TPNumber &anotherPNumber);

	~TPNumber();
};

