#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab1_Fraction/pch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace FracClassTest {
	TEST_CLASS(UnitTest1) {
public:

	TEST_METHOD(Init_String_1) {
		string fracString = "1/2";
		TFrac fracClass(fracString);
		Assert::AreEqual(fracString, fracClass.getFractionString());
	}
	TEST_METHOD(Init_String_2) {
		string fracString = "111/2";
		TFrac fracClass(fracString);
		Assert::AreEqual(fracString, fracClass.getFractionString());
	}
	TEST_METHOD(Init_String_3) {
		string fracString = "1/999";
		TFrac fracClass(fracString);
		Assert::AreEqual(fracString, fracClass.getFractionString());
	}
	TEST_METHOD(Init_String_4) {
		string fracString = "100/10";
		TFrac fracClass(fracString);
		string fracCompar = "10/1";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_String_5) {
		string fracString = "-100/60";
		TFrac fracClass(fracString);
		string fracCompar = "-5/3";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_String_6) {
		string fracString = "0000003/0004";
		TFrac fracClass(fracString);
		string fracCompar = "3/4";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Number_1) {
		TFrac fracClass(2, 4);
		string fracCompar = "1/2";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Number_2) {
		TFrac fracClass(17, 9);
		string fracCompar = "17/9";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Number_3) {
		TFrac fracClass(100, 100);
		string fracCompar = "1/1";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Number_4) {
		TFrac fracClass(-100, -99);
		string fracCompar = "100/99";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Number_5) {
		TFrac fracClass(0, 0);
		string fracCompar = "0/1";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Number_6) {
		TFrac fracClass(100, -5);
		string fracCompar = "-20/1";
		Assert::AreEqual(fracCompar, fracClass.getFractionString());
	}
	TEST_METHOD(Init_Copy_1) {
		TFrac fracClass1(1, 4);
		TFrac fracClass2(fracClass1);
		Assert::AreEqual(fracClass1.getFractionString(), fracClass2.getFractionString());
	}
	TEST_METHOD(Init_Copy_2) {
		TFrac fracClass1(-10, 1);
		TFrac fracClass2(fracClass1);
		Assert::AreEqual(fracClass1.getFractionString(), fracClass2.getFractionString());
	}
	TEST_METHOD(Add_1) {
		TFrac fracClass1(1, 2);
		TFrac fracClass2(-3, 4);
		fracClass1 = fracClass1.add(fracClass2);
		string answer = "-1/4";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Add_2) {
		TFrac fracClass1(-1, 2);
		TFrac fracClass2(-1, 2);
		fracClass1 = fracClass1.add(fracClass2);
		string answer = "-1/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Add_3) {
		TFrac fracClass1(-6, 2);
		TFrac fracClass2(6, 2);
		fracClass1 = fracClass1.add(fracClass2);
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Add_4) {
		TFrac fracClass1(50, 3);
		TFrac fracClass2(0, 1);
		fracClass1 = fracClass1.add(fracClass2);
		string answer = "50/3";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Multiply_1) {
		TFrac fracClass1(-1, 2);
		TFrac fracClass2(-1, 2);
		fracClass1 = fracClass1.multiply(fracClass2);
		string answer = "1/4";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Multiply_2) {
		TFrac fracClass1(1, 6);
		TFrac fracClass2(0, 1);
		fracClass1 = fracClass1.multiply(fracClass2);
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Multiply_3) {
		TFrac fracClass1(1, 6);
		TFrac fracClass2(1, 6);
		fracClass1 = fracClass1.multiply(fracClass2);
		string answer = "1/36";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Multiply_4) {
		TFrac fracClass1(-1, 6);
		TFrac fracClass2(12, 1);
		fracClass1 = fracClass1.multiply(fracClass2);
		string answer = "-2/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Substract_1) {
		TFrac fracClass1(0, 1);
		TFrac fracClass2(1, 1);
		fracClass1 = fracClass1.substract(fracClass2);
		string answer = "-1/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Substract_2) {
		TFrac fracClass1(5, 1);
		TFrac fracClass2(1, 1);
		fracClass1 = fracClass1.substract(fracClass2);
		string answer = "4/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Substract_3) {
		TFrac fracClass1(1, 2);
		TFrac fracClass2(1, 2);
		fracClass1 = fracClass1.substract(fracClass2);
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Substract_4) {
		TFrac fracClass1(-1, 6);
		TFrac fracClass2(-1, 6);
		fracClass1 = fracClass1.substract(fracClass2);
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Divide_1) {
		TFrac fracClass1(5, 6);
		TFrac fracClass2(1, 1);
		fracClass1 = fracClass1.divide(fracClass2);
		string answer = "5/6";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Divide_2) {
		TFrac fracClass1(1, 1);
		TFrac fracClass2(5, 6);
		fracClass1 = fracClass1.divide(fracClass2);
		string answer = "6/5";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Divide_3) {
		TFrac fracClass1(0, 1);
		TFrac fracClass2(5, 6);
		fracClass1 = fracClass1.divide(fracClass2);
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Divide_4) {
		TFrac fracClass1(2, 3);
		TFrac fracClass2(7, 4);
		fracClass1 = fracClass1.divide(fracClass2);
		string answer = "8/21";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Divide_5) {
		TFrac fracClass1(2, 3);
		TFrac fracClass2(2, 3);
		fracClass1 = fracClass1.divide(fracClass2);
		string answer = "1/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Divide_6) {
		TFrac fracClass1(-1, 3);
		TFrac fracClass2(-9, 5);
		fracClass1 = fracClass1.divide(fracClass2);
		string answer = "5/27";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Square_1) {
		TFrac fracClass1(1, 3);
		fracClass1 = fracClass1.square();
		string answer = "1/9";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Square_2) {
		TFrac fracClass1(0, 1);
		fracClass1 = fracClass1.square();
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Square_3) {
		TFrac fracClass1(-2, 3);
		fracClass1 = fracClass1.square();
		string answer = "4/9";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Reverse_1) {
		TFrac fracClass1(-2, 3);
		fracClass1 = fracClass1.reverse();
		string answer = "-3/2";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Reverse_2) {
		TFrac fracClass1(0, 1);
		fracClass1 = fracClass1.reverse();
		string answer = "0/1";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Reverse_3) {
		TFrac fracClass1(5, 6);
		fracClass1 = fracClass1.reverse();
		string answer = "6/5";
		Assert::AreEqual(answer, fracClass1.getFractionString());
	}
	TEST_METHOD(Minus_1) {
		TFrac fracClass(0, 1);
		string answer = "0/1";
		fracClass = -fracClass;
		Assert::AreEqual(answer, fracClass.getFractionString());
	}
	TEST_METHOD(Minus_2) {
		TFrac fracClass(7, 4);
		string answer = "-7/4";
		fracClass = -fracClass;
		Assert::AreEqual(answer, fracClass.getFractionString());
	}
	TEST_METHOD(Minus_3) {
		TFrac fracClass(-5, 3);
		string answer = "5/3";
		fracClass = -fracClass;
		Assert::AreEqual(answer, fracClass.getFractionString());
	}
	TEST_METHOD(Equal_1) {
		TFrac fracClass1(1, 6);
		TFrac fracClass2(1, 6);
		Assert::IsTrue(fracClass1 == fracClass2);
	}
	TEST_METHOD(Equal_2) {
		TFrac fracClass1(0, 6);
		TFrac fracClass2(1, 6);
		Assert::IsFalse(fracClass1 == fracClass2);
	}
	TEST_METHOD(Equal_3) {
		TFrac fracClass1(-1, 6);
		TFrac fracClass2(-1, 6);
		Assert::IsTrue(fracClass1 == fracClass2);
	}
	TEST_METHOD(Equal_4) {
		TFrac fracClass1(-1, 7);
		TFrac fracClass2(1, 7);
		Assert::IsFalse(fracClass1 == fracClass2);
	}
	TEST_METHOD(Equal_5) {
		TFrac fracClass1(1, 6);
		TFrac fracClass2(0, 1);
		Assert::IsFalse(fracClass1 == fracClass2);
	}
	TEST_METHOD(Greater_1) {
		TFrac fracClass1(1, 6);
		TFrac fracClass2(0, 1);
		Assert::IsTrue(fracClass1 > fracClass2);
	}
	TEST_METHOD(Greater_2) {
		TFrac fracClass1(0, 1);
		TFrac fracClass2(0, 1);
		Assert::IsFalse(fracClass1 > fracClass2);
	}
	TEST_METHOD(Greater_3) {
		TFrac fracClass1(-1, 6);
		TFrac fracClass2(0, 1);
		Assert::IsFalse(fracClass1 > fracClass2);
	}
	TEST_METHOD(Greater_4) {
		TFrac fracClass1(17, 3);
		TFrac fracClass2(16, 3);
		Assert::IsTrue(fracClass1 > fracClass2);
	}
	TEST_METHOD(Greater_5) {
		TFrac fracClass1(-2, 3);
		TFrac fracClass2(-1, 3);
		Assert::IsFalse(fracClass1 > fracClass2);
	}
	TEST_METHOD(GetNumeratorNum_1) {
		TFrac fracClass(1, 23);
		int expectedNum = 1;
		Assert::AreEqual(expectedNum, fracClass.getNumeratorNumber());
	}
	TEST_METHOD(GetNumeratorNum_2) {
		TFrac fracClass(-11, 2);
		int expectedNum = -11;
		Assert::AreEqual(expectedNum, fracClass.getNumeratorNumber());
	}
	TEST_METHOD(GetNumeratorNum_3) {
		TFrac fracClass(0, 1);
		int expectedNum = 0;
		Assert::AreEqual(expectedNum, fracClass.getNumeratorNumber());
	}
	TEST_METHOD(GetDenominatorNum_1) {
		TFrac fracClass(1, 222);
		int expectedNum = 222;
		Assert::AreEqual(expectedNum, fracClass.getDenominatorNumber());
	}
	TEST_METHOD(GetDenominatorNum_2) {
		TFrac fracClass(-1, 222);
		int expectedNum = 222;
		Assert::AreEqual(expectedNum, fracClass.getDenominatorNumber());
	}
	TEST_METHOD(GetDenominatorNum_3) {
		TFrac fracClass(0, 1);
		int expectedNum = 1;
		Assert::AreEqual(expectedNum, fracClass.getDenominatorNumber());
	}
	TEST_METHOD(GetNumeratorString_1) {
		TFrac fracClass(1, 23);
		string expectedNum = "1";
		Assert::AreEqual(expectedNum, fracClass.getNumeratorString());
	}
	TEST_METHOD(GetNumeratorString_2) {
		TFrac fracClass(-11, 2);
		string expectedNum = "-11";
		Assert::AreEqual(expectedNum, fracClass.getNumeratorString());
	}
	TEST_METHOD(GetNumeratorString_3) {
		TFrac fracClass(0, 1);
		string expectedNum = "0";
		Assert::AreEqual(expectedNum, fracClass.getNumeratorString());
	}
	TEST_METHOD(GetDenominatorString_1) {
		TFrac fracClass(1, 222);
		string expectedNum = "222";
		Assert::AreEqual(expectedNum, fracClass.getDenominatorString());
	}
	TEST_METHOD(GetDenominatorString_2) {
		TFrac fracClass(-1, 222);
		string expectedNum = "222";
		Assert::AreEqual(expectedNum, fracClass.getDenominatorString());
	}
	TEST_METHOD(GetDenominatorString_3) {
		TFrac fracClass(0, 1);
		string expectedNum = "1";
		Assert::AreEqual(expectedNum, fracClass.getDenominatorString());
	}
	TEST_METHOD(GetFractionString_1) {
		TFrac fracClass(1, 2);
		string expectedString = "1/2";
		Assert::AreEqual(expectedString, fracClass.getFractionString());
	}
	TEST_METHOD(GetFractionString_2) {
		TFrac fracClass(-1111, 9);
		string expectedString = "-1111/9";
		Assert::AreEqual(expectedString, fracClass.getFractionString());
	}
	TEST_METHOD(GetFractionString_3) {
		TFrac fracClass(0, 1);
		string expectedString = "0/1";
		Assert::AreEqual(expectedString, fracClass.getFractionString());
	}
	TEST_METHOD(GetFractionString_4) {
		TFrac fracClass(6666, 7779);
		string expectedString = "2222/2593";
		Assert::AreEqual(expectedString, fracClass.getFractionString());
	}
	};
}