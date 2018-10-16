#pragma once
#include <string>
using namespace std;

enum partToEdit {
	REAL, IMAG
};

enum numberPartToEdit {
	LEFT, RIGHT
};

enum commandType {
	etoggleMinus, eaddNumber, eaddZero, edelSymbol,
	eclear, ewriteString
};

class TEditor {
private:
	string pNum;
	partToEdit mode;
	numberPartToEdit numberMode;
	string zero = "0,+i*0,";
	string separatorParts = "i*";
	string separatorNumber = ",";
public:
	bool isZero();
	string toggleMinus();
	partToEdit toggleMode();
	numberPartToEdit toggleNumberMode();
	string addNumber(int a);
	string addZero();
	string delNumber();
	string clear();
	string readNumber();
	string writeNumber(string otherNumber);
	string edit(commandType command);
	TEditor();
};
