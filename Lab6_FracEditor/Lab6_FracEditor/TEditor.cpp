#include "stdafx.h"
#include "TEditor.h"
#include <regex>

bool TEditor::isZero() {
	if (frac == zeroStr || frac == ('-' + zeroStr))
		return true;
	else return false;
}

string TEditor::toggleMinus() {
	if (frac[0] == '-')
		frac.erase(frac.begin());
	else
		frac = '-' + frac;
	return frac;
}

partToEdit TEditor::toggleMode() {
	if (mode == TOP)
		mode = BOT;
	else
		mode = TOP;
	return mode;
}

string TEditor::addNumber(int a) {
	if (a < 0 || a > 9)
		return frac;
	if (mode == TOP) {
		if (frac[0] == '0')
			frac[0] = '0' + a;
		else if (frac[0] == '-' && frac[1] == '0')
			frac[1] = '0' + a;
		else
			frac.insert(frac.find(separator), 1, ('0' + a));
	}
	else
		frac += '0' + a;
	return frac;
}

string TEditor::addZero() {
	return this->addNumber(0);
}

string TEditor::delSymbol() {
	if (mode == TOP) {
		if (frac[0] == '0' || (frac[0] == '-' && frac[1] == '0'))
			return frac;
		else
			frac.erase(frac.find(separator) - 1, 1);
		if (frac[0] == '/')
			frac = '0' + frac;
	}
	else
		if (frac[frac.find(separator)] == '0')
			return frac;
		else {
			frac.pop_back();
			if (frac.find(separator) + 1 == frac.size())
				frac.append("1");
		}
	return frac;
}

string TEditor::clear() {
	frac = zeroStr;
	mode = TOP;
	return frac;
}

string TEditor::readString() {
	return frac;
}

bool checkForNumbers(const string &s) {
	return !s.empty() && find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

string TEditor::writeString(string otherStr) {
	regex fracRegex("-?(0|[1-9][0-9]*)\/[1-9][0-9]*");
	if (regex_match(otherStr, fracRegex)) {
		frac = otherStr;
		return frac;
	}
	else
		return frac;
}

string TEditor::edit(commandType command) {
	switch (command) {
		case etoggleMinus:
			return this->toggleMinus();
			break;
		case eaddNumber: {
			cout << "Enter number to add:" << endl;
			int num;
			cin >> num;
			return this->addNumber(num);
			break;
		}
		case eaddZero:
			return this->addZero();
			break;
		case edelSymbol:
			return this->delSymbol();
			break;
		case eclear:
			return this->clear();
			break;
		case ewriteString: {
			cout << "Enter string to write:" << endl;
			string inp;
			cin >> inp;
			return this->writeString(inp);
			break;
		}
		default:
			return frac;
			break;
	}
	return string();
}

TEditor::TEditor() {
	frac = zeroStr;
	mode = TOP;
}
