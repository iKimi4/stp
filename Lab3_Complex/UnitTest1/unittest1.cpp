#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab3_Complex/TComplex.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Init_Output_1) {
			TComplex testClass(6, 3);
			string output = "6 + i * 3";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_2) {
			TComplex testClass(0, 0);
			string output = "0 + i * 0";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_3) {
			TComplex testClass(3, -2);
			string output = "3 - i * 2";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_4) {
			TComplex testClass(4.01, 6);
			string output = "4.01 + i * 6";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_5) {
			TComplex testClass(-3.02, 7);
			string output = "-3.02 + i * 7";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_6) {
			TComplex testClass(99, -11.11);
			string output = "99 - i * 11.11";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_7) {
			TComplex testClass(0, -22.22);
			string output = "0 - i * 22.22";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Init_Output_8) {
			TComplex testClass(77.77, 0);
			string output = "77.77 + i * 0";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Add_1) {
			TComplex testClass1(3, 4);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.add(testClass2);
			string output = "7 + i * 3";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Add_2) {
			TComplex testClass1(0, -3);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.add(testClass2);
			string output = "4 - i * 4";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Multiply_1) {
			TComplex testClass1(3, 4);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.multiply(testClass2);
			string output = "16 + i * 13";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Multiply_2) {
			TComplex testClass1(0, -3);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.multiply(testClass2);
			string output = "-3 - i * 12";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Substract_1) {
			TComplex testClass1(3, 4);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.subtract(testClass2);
			string output = "-1 + i * 5";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Substract_2) {
			TComplex testClass1(0, -3);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.subtract(testClass2);
			string output = "-4 - i * 2";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Divide_1) {
			TComplex testClass1(3, 4);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.divide(testClass2);
			string output = "0.470588 + i * 1.117647";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Divide_2) {
			TComplex testClass1(0, -3);
			TComplex testClass2(4, -1);
			testClass1 = testClass1.divide(testClass2);
			string output = "0.176471 - i * 0.705882";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Square_1) {
			TComplex testClass1(3, 4);
			testClass1 = testClass1.square();
			string output = "-7 + i * 24";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Square_2) {
			TComplex testClass1(0, -3);
			testClass1 = testClass1.square();
			string output = "-9 + i * 0";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Reverse_1) {
			TComplex testClass1(0, -3);
			testClass1 = testClass1.reverse();
			string output = "0 + i * 0.333333";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Reverse_2) {
			TComplex testClass1(3, 4);
			testClass1 = testClass1.reverse();
			string output = "0.12 - i * 0.16";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Minus) {
			TComplex testClass1(0, 4);
			testClass1 = -testClass1;
			string output = "0 - i * 4";
			Assert::AreEqual(output, testClass1.getString());
		}
		TEST_METHOD(Abs_1) {
			TComplex testClass(3, 4);
			double answer = 5;
			Assert::AreEqual(answer, testClass.abs());
		}
		TEST_METHOD(Abs_2) {
			TComplex testClass(0, -3);
			double answer = 3;
			Assert::AreEqual(answer, testClass.abs());
		}
		TEST_METHOD(GetRad_1) {
			TComplex testClass(3, 4);
			double answer = 0.927295;
			Assert::AreEqual(answer, testClass.getRad(), 4);
		}
		TEST_METHOD(GetRad_2) {
			TComplex testClass(0, -3);
			double answer = -1.570796;
			Assert::AreEqual(answer, testClass.getRad(), 4);
		}
		TEST_METHOD(GetDegree_1) {
			TComplex testClass(3, 4);
			double answer = 53.1301;
			Assert::AreEqual(answer, testClass.getDegree(), 4);
		}
		TEST_METHOD(GetDegree_2) {
			TComplex testClass(0, -3);
			double answer = -90;
			Assert::AreEqual(answer, testClass.getDegree(), 4);
		}
		TEST_METHOD(Pow_1) {
			TComplex testClass(3, 4);
			testClass = testClass.getPow(5);
			string output = "-237 - i * 3116";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Pow_2) {
			TComplex testClass(0, -3);
			testClass = testClass.getPow(-4);
			string output = "0.012346 + i * 0";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Root_1) {
			TComplex testClass(3, 4);
			testClass = testClass.getSqrt(3, 4);
			string output = "2.567133 + i * 2.142468";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Root_2) {
			TComplex testClass(0, -3);
			testClass = testClass.getSqrt(0, -7);
			string output = "1 + i * 0";
			Assert::AreEqual(output, testClass.getString());
		}
		TEST_METHOD(Root_3) {
			TComplex testClass(6, 3);
			testClass = testClass.getSqrt(5, 4);
			string output = "9.032951 + i * 5.912419";
			Assert::AreEqual(output, testClass.getString());
		}
	};
}