#pragma once
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
enum partToEdit {
	TOP, BOT
};

enum commandType {
	etoggleMinus, eaddNumber, eaddZero, edelSymbol,
	eclear, ewriteString
};

class TEditor {
private:
	const string separator = "/";
	const string zeroStr = "0/1";
	string frac;
	partToEdit mode;
public:
	bool isZero();
	string toggleMinus();
	partToEdit toggleMode();
	string addNumber(int a);
	string addZero();
	string delSymbol();
	string clear();
	string readString();
	string writeString(string otherStr);
	string edit(commandType command);
	TEditor();
};

