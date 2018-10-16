#include "stdafx.h"
#include "TPoly.h"
#include <utility>
#include <numeric>
TPoly::TPoly() {
}

TPoly::TPoly(int coeff, int degree) {
	polynom.emplace(degree, TMember(coeff, degree));
}

int TPoly::maxDegree() {
	return polynom.rbegin()->first;
}

int TPoly::coeff(int Degree) {
	if (!polynom.count(Degree))
		return 0;
	else
		return polynom.at(Degree).readCoeff();
}

void TPoly::clear() {
	polynom.clear();
}

TPoly TPoly::add(TPoly otherPoly) {
	TPoly result = *this;
	for (auto &pairElem : otherPoly.polynom)
		if (result.polynom.count(pairElem.first))
			result.polynom.at(pairElem.first) =
			TMember(result.polynom.at(pairElem.first).readCoeff() + pairElem.second.readCoeff(), pairElem.first);
		else
			result.polynom.emplace(pairElem);
	return result;
}

TPoly TPoly::multiply(TPoly otherPoly) {
	TPoly newPoly;
	for (auto &it1 : this->polynom)
		for (auto &it2 : otherPoly.polynom) {
			TMember newMember(it1.first * it2.first, it1.second.readDegree() + it2.second.readDegree());
			if (newPoly.polynom.count(newMember.readDegree()))
				newPoly.polynom.emplace(newMember.readDegree(), TMember(newMember.readCoeff() + newPoly.polynom.at(newMember.readDegree()).readCoeff(), newMember.readDegree()));
			else
				newPoly.polynom.emplace(newMember.readDegree(), newMember);
		}
	return newPoly;
}

TPoly TPoly::subtract(TPoly otherPoly) {
	TPoly result = *this;
	for (auto &pairElem : otherPoly.polynom)
		if (result.polynom.count(pairElem.first))
			result.polynom.at(pairElem.first) =
			TMember(result.polynom.at(pairElem.first).readCoeff() - pairElem.second.readCoeff(), pairElem.first);
		else
			result.polynom.emplace(-pairElem.first, TMember(-pairElem.first, pairElem.second.readDegree()));
	return result;
}

TPoly TPoly::minus() {
	TPoly newPoly;
	for (auto &it : polynom)
		newPoly.polynom.emplace(-it.first, TMember(-it.second.readCoeff(), it.second.readDegree()));
	return newPoly;
}

TPoly TPoly::operator-() {
	return TPoly();
}

bool TPoly::isEqual(TPoly otherPoly) {
	return this->polynom == otherPoly.polynom;
}


TPoly TPoly::differentiate() {
	TPoly newPoly;
	for (auto &it : polynom)
		newPoly.polynom.emplace(it.first == 0 ? 0 : it.first - 1, it.second.differentiate());
	return newPoly;
}

double TPoly::compute(double x) {
	if (x == 0)
		return 0;
	double sum = 0.0;
	for (auto &it : polynom)
		sum += it.second.compute(x);
	return sum;
}

TMember TPoly::elem(int pos) {
	if (pos < 0 || pos >(int)polynom.size())
		return TMember();
	else {
		int cntr = 0;
		for (auto &it : polynom)
			if (cntr == pos)
				return it.second;
	}
	return TMember();
}

TMember TPoly::operator[](int pos) {
	if (pos < 0 || pos >(int)polynom.size())
		return TMember();
	else {
		int cntr = 0;
		for (auto &it : polynom)
			if (cntr++ == pos)
				return it.second;
	}
	return TMember();
}

TPoly::~TPoly() {

}

TPoly operator+(TPoly & ourPoly, TPoly & otherPoly) {
	TPoly result = ourPoly;
	for (auto &pairElem : otherPoly.polynom)
		if (result.polynom.count(pairElem.first))
			result.polynom.at(pairElem.first) =
			TMember(result.polynom.at(pairElem.first).readCoeff() + pairElem.second.readCoeff(), pairElem.first);
		else
			result.polynom.emplace(pairElem);
	return result;
}

TPoly operator-(TPoly & ourPoly, TPoly & otherPoly) {
	TPoly result = ourPoly;
	for (auto &pairElem : otherPoly.polynom)
		if (result.polynom.count(pairElem.first))
			result.polynom.at(pairElem.first) =
			TMember(result.polynom.at(pairElem.first).readCoeff() - pairElem.second.readCoeff(), pairElem.first);
		else
			result.polynom.emplace(-pairElem.first, TMember(-pairElem.first, pairElem.second.readDegree()));
	return result;
}

TPoly operator*(TPoly & ourPoly, TPoly & otherPoly) {
	TPoly newPoly;
	for (auto &it1 : ourPoly.polynom)
		for (auto &it2 : otherPoly.polynom) {
			TMember newMember(it1.second.readCoeff() * it2.second.readCoeff(), it1.second.readDegree() + it2.second.readDegree());
			if (newPoly.polynom.count(newMember.readDegree()))
				newPoly.polynom.emplace(newMember.readDegree(), TMember(newMember.readCoeff() + newPoly.polynom.at(newMember.readDegree()).readCoeff(), newMember.readDegree()));
			else
				newPoly.polynom.emplace(newMember.readDegree(), newMember);
		}
	return newPoly;
}
