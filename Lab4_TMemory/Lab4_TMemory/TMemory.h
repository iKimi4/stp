#pragma once
#include <string>
using namespace std;
enum numStates {
	OFF, ON
};
template <class T = int>
class TMemory {
private:
	T fNumber;
	int fState;
public:
	TMemory(T someNumber);
	void writeMemory(T someNumber);
	T getMemory();
	void sumMemory(T someNumber);
	void clearMemory();
	string getMemoryState();
	int getNumber();
	~TMemory();
};

template<class T>
TMemory<T>::TMemory(T someNumber) {
	this->fNumber = someNumber;
	fState = OFF;
}

template<class T>
void TMemory<T>::writeMemory(T someNumber) {
	this->fNumber = someNumber;
	fState = ON;
}

template<class T>
T TMemory<T>::getMemory() {
	fState = ON;
	return T(this->fNumber);
}

template<class T>
void TMemory<T>::sumMemory(T someNumber) {
	fNumber = fNumber + someNumber;
	fState = ON;
}

template<class T>
void TMemory<T>::clearMemory() {
	T newObj;
	this->fNumber = newObj;
	fState = OFF;
}

template<class T>
string TMemory<T>::getMemoryState() {
	return string(to_string(fState));
}

template<class T>
int TMemory<T>::getNumber() {
	return fState;
}

template<class T>
TMemory<T>::~TMemory() {
}
