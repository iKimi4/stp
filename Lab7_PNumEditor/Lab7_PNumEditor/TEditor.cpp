#include "stdafx.h"
#include "TEditor.h"
#include <regex>
#include <iostream>

string TEditor::clear() {
	pNum = zero;
	mode = LEFT;
	return pNum;
}

string TEditor::readNumber() {
	return pNum;
}

string TEditor::writeNumber(string otherNumber) {
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*),[0-9A-F]*");
	if (regex_match(otherNumber, pNumreg))
		pNum = otherNumber;
	return pNum;
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
			return this->delNumber();
			break;
		case eclear:
			return this->clear();
			break;
		case ewriteString: {
			cout << "Enter string to write:" << endl;
			string inp;
			cin >> inp;
			return this->writeNumber(inp);
			break;
		}
		default:
			return pNum;
			break;
	}
	return string();
}

TEditor::TEditor() {
	pNum = zero;
	mode = LEFT;
}

bool TEditor::isZero() {
	if (pNum == zero || pNum == ('-' + zero))
		return true;
	else
		return false;
}

string TEditor::toggleMinus() {
	if (pNum[0] == '-')
		pNum.erase(pNum.begin());
	else
		pNum = '-' + pNum;
	return pNum;
}

partToEdit TEditor::toggleMode() {
	if (mode == LEFT)
		mode = RIGHT;
	else
		mode = LEFT;
	return mode;
}

string TEditor::addNumber(int a) {
	if (a < 0 || a > 15)
		return pNum;
	char chToAdd = a >= 0 && a < 10 ? '0' + a : ('A' + a - 10);
	int ind = pNum.find(separator);
	if (mode == LEFT) {
		if (pNum[0] == '0')
			pNum[0] = chToAdd;
		else if (pNum[0] == '-' && pNum[1] == '0')
			pNum[1] = chToAdd;
		else
			pNum.insert(ind, 1, chToAdd);
	}
	else
		pNum += chToAdd;
	return pNum;
}

string TEditor::addZero() {
	return this->addNumber(0);
}

string TEditor::delNumber() {
	if (mode == LEFT) {
		if (pNum[0] == '0' || (pNum[0] == '-' && pNum[1] == '0'))
			return pNum;
		else
			pNum.erase(pNum.find(separator) - 1, 1);
		if (pNum[0] == ',')
			pNum = '0' + pNum;
	}
	else
		if (pNum[pNum.find(separator)] == '0')
			return pNum;
		else {
			pNum.pop_back();
			if (pNum.find(separator) + 1 == pNum.size())
				pNum.append("1");
		}
	return pNum;
}
