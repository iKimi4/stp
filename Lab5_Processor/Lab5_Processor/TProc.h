#pragma once
enum TOprtn {
	None, Add, Sub, Mul, Div
};
enum TFunc {
	Rev, Sqr
};

template <typename T = int>
class TProc {
private:
	T Lop_Res;
	T Rop;
	TOprtn operation;
public:
	TProc(const T &leftObj, const T &rightObj);
	void resetProc();
	void resetOper();
	void doOper();
	void doFunc(TFunc func);
	T readLeft();
	T readRight();
	void writeLeft(const T &someObj);
	void writeRight(const T &someObj);
	void writeOper(TOprtn someOper);
	TOprtn readOper();
	~TProc();
};

template<typename T>
inline TProc<T>::TProc(const T &leftObj, const T &rightObj) {
	operation = None;
	this->Lop_Res = leftObj;
	this->Rop = rightObj;
}

template<typename T>
inline void TProc<T>::resetProc() {
	operation = None;
	T clearObj;
	this->Lop_Res = this->Rop = clearObj;
}

template<typename T>
inline void TProc<T>::resetOper() {
	operation = None;
}

template<typename T>
inline void TProc<T>::doOper() {
	switch (operation) {
		case Add:
			Lop_Res = Lop_Res + Rop;
			break;
		case Sub:
			Lop_Res = Lop_Res - Rop;
			break;
		case Mul:
			Lop_Res = Lop_Res * Rop;
			break;
		case Div:
			Lop_Res = Lop_Res / Rop;
			break;
		default:
			break;
	}
}

template<typename T>
inline void TProc<T>::doFunc(TFunc func) {
	switch (func) {
		case Rev:
			Rop = Rop.reverse();
			break;
		case Sqr:
			Rop = Rop * Rop;
			break;
		default:
			break;
	}
}

template<typename T>
inline T TProc<T>::readLeft() {
	return T(this->Lop_Res);
}

template<typename T>
inline T TProc<T>::readRight() {
	return T(this->Rop);
}

template<typename T>
inline void TProc<T>::writeLeft(const T &someObj) {
	this->Lop_Res = someObj;
}

template<typename T>
inline void TProc<T>::writeRight(const T &someObj) {
	this->Rop = someObj;
}

template<typename T>
inline void TProc<T>::writeOper(TOprtn someOper) {
	this->operation = someOper;
}

template<typename T>
inline TOprtn TProc<T>::readOper() {
	return operation;
}

template<typename T>
inline TProc<T>::~TProc() {
}
