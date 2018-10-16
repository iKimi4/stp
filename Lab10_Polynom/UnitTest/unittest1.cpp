#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab10_Polynom/TMember.h"
#include "../Lab10_Polynom/TPoly.h"
#include <vector>
#include <set>
#include <algorithm>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(TestMember) {
public:
	TEST_METHOD(Init_Output_1) {
		TMember testClass(3, 14);
		string answer = "3*x^14";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Init_Output_2) {
		TMember testClass(-15, -6);
		string answer = "-15*x^-6";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Init_Output_3) {
		TMember testClass(0, 9);
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Init_Output_4) {
		TMember testClass(0, 0);
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Equality_1) {
		TMember testClass1(1, 2);
		TMember testClass2(1, 2);
		bool expectedResult = true;
		bool result = testClass1.isEqual(testClass2);
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Equality_2) {
		TMember testClass1(1, 2);
		TMember testClass2(15, 2);
		bool expectedResult = false;
		bool result = testClass1.isEqual(testClass2);
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Differentiante_1) {
		TMember testClass(3, 6);
		testClass = testClass.differentiate();
		string answer = "18*x^5";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_2) {
		TMember testClass(3, 0);
		testClass = testClass.differentiate();
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_3) {
		TMember testClass(5, -4);
		testClass = testClass.differentiate();
		string answer = "-20*x^-5";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_4) {
		TMember testClass(0, 6);
		testClass = testClass.differentiate();
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_5) {
		TMember testClass(0, 0);
		testClass = testClass.differentiate();
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_6) {
		TMember testClass(0, -5);
		testClass = testClass.differentiate();
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_7) {
		TMember testClass(-4, 6);
		testClass = testClass.differentiate();
		string answer = "-24*x^5";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_8) {
		TMember testClass(-7, 0);
		testClass = testClass.differentiate();
		string answer = "0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_9) {
		TMember testClass(-12, -4);
		testClass = testClass.differentiate();
		string answer = "48*x^-5";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Differentiante_10) {
		TMember testClass(1, 1);
		testClass = testClass.differentiate();
		string answer = "1*x^0";
		Assert::AreEqual(answer, testClass.toString());
	}
	TEST_METHOD(Compute_1) {
		TMember testClass(4, 6);
		double x = -6.08;
		double expectedAnswer = 202060.5203;
		double answer = testClass.compute(x);
		Assert::AreEqual(expectedAnswer, answer, 0.01);
	}
	TEST_METHOD(Compute_2) {
		TMember testClass(10, -2);
		double x = 4.58;
		double expectedAnswer = 0.476;
		double answer = testClass.compute(x);
		Assert::AreEqual(expectedAnswer, answer, 0.01);
	}
	TEST_METHOD(Compute_3) {
		TMember testClass(8, 3);
		double x = 8.34;
		double expectedAnswer = 4640.7496;
		double answer = testClass.compute(x);
		Assert::AreEqual(expectedAnswer, answer, 0.01);
	}
	TEST_METHOD(Compute_4) {
		TMember testClass(-3, -5);
		double x = -0.39;
		double expectedAnswer = 332.5050;
		double answer = testClass.compute(x);
		Assert::AreEqual(expectedAnswer, answer, 0.01);
	}
	TEST_METHOD(Compute_5) {
		TMember testClass(6, 7);
		double x = 0;
		double expectedAnswer = 0;
		double answer = testClass.compute(x);
		Assert::AreEqual(expectedAnswer, answer, 0.01);
	}
	};
	TEST_CLASS(TestPolynom) {
public:
	TEST_METHOD(Add) {
		TPoly P1(1, 0);
		TPoly P2(1, 1);
		TPoly P3(2, 2);
		TPoly P4(4, 2);
		TPoly resultPoly = P1 + P2 + P3 + P4;
		set<string> setResult;
		for (int i = 0; i < 3; ++i)
			setResult.emplace(resultPoly[i].toString());
		set<string> setExpectedResult = { "1*x^0", "1*x^1", "6*x^2" };
		bool expectedResult = true;
		/*bool result = equal(vecExpectedResult.begin(), vecExpectedResult.end(), vecResult.begin(), [](const string &left, const string &right) {return equal(left.begin(), left.end(), right.begin()); });*/
		bool result = setResult == setExpectedResult;
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Multiply) {
		TPoly P1(1, 0);
		TPoly P2(1, 1);
		TPoly P3(2, 2);
		TPoly P4(4, 2);
		TPoly resultPoly = P1 + P2 + P3 + P4;
		P3 = P3 + P4;
		resultPoly = resultPoly * P3;
		set<string> setResult;
		for (int i = 0; i < 3; ++i)
			setResult.emplace(resultPoly[i].toString());
		set<string> setExpectedResult = { "6*x^2", "6*x^3", "36*x^4" };
		bool expectedResult = true;
		bool result = setResult == setExpectedResult;
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Substract) {
		TPoly P1(1, 0);
		TPoly P2(1, 1);
		TPoly P3(2, 2);
		TPoly P4(4, 2);
		TPoly resultPoly = P1 + P2 + P3 + P4;
		P3 = P3 + P4;
		resultPoly = resultPoly * P3;
		P3 = P3 * P3;
		resultPoly = resultPoly - P3;
		set<string> setResult;
		for (int i = 0; i < 3; ++i)
			setResult.emplace(resultPoly[i].toString());
		set<string> setExpectedResult = { "0", "6*x^2", "6*x^3" };
		bool expectedResult = true;
		bool result = setResult == setExpectedResult;
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Differentiate) {
		TPoly P1(1, 0);
		TPoly P2(1, 1);
		TPoly P3(2, 2);
		TPoly P4(4, 2);
		TPoly P5(-3, -3);
		TPoly P6(3, -5);
		TPoly resultPoly = P1 + P2 + P3 + P4;
		P3 = P3 + P4;
		resultPoly = resultPoly * P3;
		P3 = P3 * P3;
		resultPoly = resultPoly - P3 + P5 + P6;
		resultPoly = resultPoly.differentiate();
		set<string> setResult;
		for (int i = 0; i < 5; ++i)
			setResult.emplace(resultPoly[i].toString());
		set<string> setExpectedResult = { "0", "12*x^1", "18*x^2", "9*x^-4", "-15*x^-6" };
		bool expectedResult = true;
		bool result = setResult == setExpectedResult;
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Compute) {
		TPoly P1(1, 0);
		TPoly P2(1, 1);
		TPoly P3(2, 2);
		TPoly P4(4, 2);
		TPoly P5(-3, -3);
		TPoly P6(3, -5);
		TPoly resultPoly = P1 + P2 + P3 + P4;
		P3 = P3 + P4;
		resultPoly = resultPoly * P3;
		P3 = P3 * P3;
		resultPoly = resultPoly - P3 + P5 + P6;
		resultPoly = resultPoly.differentiate();
		double x = -13.4;
		double result = resultPoly.compute(x);
		double expectedResult = 3071.2802;
		Assert::AreEqual(expectedResult, result, 0.001);
	}
	TEST_METHOD(Minus) {
		TPoly P1(1, 0);
		TPoly P2(1, 1);
		TPoly P3(2, 2);
		TPoly P4(4, 2);
		TPoly P5(-3, -3);
		TPoly P6(3, -5);
		TPoly resultPoly = P1 + P2 + P3 + P4;
		P3 = P3 + P4;
		resultPoly = resultPoly * P3;
		P3 = P3 * P3;
		resultPoly = resultPoly - P3 + P5 + P6;
		resultPoly = resultPoly.differentiate();
		resultPoly = resultPoly.minus();
		set<string> setResult;
		for (int i = 0; i < 5; ++i)
			setResult.emplace(resultPoly[i].toString());
		set<string> setExpectedResult = { "0", "-12*x^1", "-18*x^2", "-9*x^-4", "15*x^-6" };
		bool expectedResult = true;
		bool result = setResult == setExpectedResult;
		Assert::AreEqual(expectedResult, result);
	}
	};
}