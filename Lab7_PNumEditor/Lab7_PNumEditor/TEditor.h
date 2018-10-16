#pragma once
#include <string>
using namespace std;
enum partToEdit {
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
	string zero = "0,";
	string separator = ",";
public:
	bool isZero();
	string toggleMinus();
	partToEdit toggleMode();
	string addNumber(int a);
	string addZero();
	string delNumber();
	string clear();
	string readNumber();
	string writeNumber(string otherNumber);
	string edit(commandType command);
	TEditor();
};

