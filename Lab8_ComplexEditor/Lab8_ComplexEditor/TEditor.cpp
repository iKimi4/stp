#include "stdafx.h"
#include "TEditor.h"
#include <regex>
#include <iostream>

string TEditor::clear() {
	pNum = zero;
	mode = REAL;
	numberMode = LEFT;
	return pNum;
}

string TEditor::readNumber() {
	return pNum;
}

string TEditor::writeNumber(string otherNumber) {
	regex pNumreg("");
	string pattern("-?(0|[1-9][0-9]*),([0-9]*)(\\+|-)i\\*(0|[1-9][0-9]*),([0-9]*)");
	try {
		pNumreg.assign(pattern);
	}
	catch (regex_error& e) {
		cout << e.code();
	}
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
	mode = REAL;
	numberMode = LEFT;
}

bool TEditor::isZero() {
	string tmp = pNum;
	if (tmp.at(0) == '-')
		tmp.erase(tmp.begin());
	replace(tmp.begin(), tmp.end(), '-', '+');
	if (tmp == zero)
		return true;
	else
		return false;
}

string TEditor::toggleMinus() {
	if (mode == REAL) {
		if (pNum[0] == '-')
			pNum.erase(pNum.begin());
		else
			pNum = '-' + pNum;
	}
	else {
		int ind = pNum.find_last_of('-');
		if (ind == 0 || ind == -1)
			pNum[pNum.find(separatorParts) - 1] = '-';
		else
			pNum[ind] = '+';
	}
	return pNum;
}

partToEdit TEditor::toggleMode() {
	if (mode == REAL)
		mode = IMAG;
	else
		mode = REAL;
	return mode;
}

numberPartToEdit TEditor::toggleNumberMode() {
	if (numberMode == LEFT)
		numberMode = RIGHT;
	else
		numberMode = LEFT;
	return numberMode;
}

string TEditor::addNumber(int a) {
	if (a < 0 || a > 9)
		return pNum;
	int ind = pNum.find(separatorParts);
	if (mode == REAL) {
		if (numberMode == LEFT) {
			if (pNum[0] == '0')
				pNum[0] = '0' + a;
			else if (pNum[0] == '-' && pNum[1] == '0')
				pNum[1] = '0' + a;
			else {
				int frstNumbSep = pNum.find_first_of(separatorNumber);
				pNum.insert(frstNumbSep, 1, ('0' + a));
			}
		}
		else
			pNum.insert(ind - 1, 1, ('0' + a));
	}
	else {
		if (numberMode == LEFT) {
			ind += 2;
			if (pNum[ind] == '0')
				pNum[ind] = '0' + a;
			else {
				int lastNumbSep = pNum.find_last_of(',');
				pNum.insert(lastNumbSep, 1, ('0' + a));
			}
		}
		else
			pNum += '0' + a;
	}
	return pNum;
}

string TEditor::addZero() {
	return this->addNumber(0);
}

string TEditor::delNumber() {
	int ind = pNum.find(separatorParts);
	if (mode == REAL) {
		if (numberMode == LEFT) {
			if (pNum[0] == '0')
				return pNum;
			else if (pNum[0] == '-' && pNum[1] == '0')
				return pNum;
			else {
				int frstNumbSep = pNum.find_first_of(separatorNumber);
				pNum.erase(frstNumbSep - 1, 1);
				if (pNum[0] == ',')
					pNum = '0' + pNum;
			}
		}
		else {
			if (!isdigit(pNum[ind - 2]))
				return pNum;
			pNum.erase(ind - 2, 1);
		}
	}
	else {
		if (numberMode == LEFT) {
			ind += 2;
			if (pNum[ind] == '0')
				return 0;
			else {
				int lastNumbSep = pNum.find_last_of(',');
				if (pNum[lastNumbSep - 2] == '*')
					pNum[lastNumbSep - 1] = '0';
				else
					pNum.erase(lastNumbSep - 1, 1);
			}
		}
		else {
			if (pNum[pNum.size() - 1] == ',')
				return pNum;
			else
				pNum.erase(pNum.size() - 1);
		}
	}
	return pNum;
}
