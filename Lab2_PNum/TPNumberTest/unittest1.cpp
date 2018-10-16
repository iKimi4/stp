#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab2_PNum/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPNumberTest
{		
	TEST_CLASS(TPNumberTest)
	{
	public:
		TEST_METHOD(InitAndOutput_1)
		{
			TPNumber testClass(10, 10, 3);
			string answer = "10";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_2) {
			TPNumber testClass(10.01, 10, 3);
			string answer = "10.010";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_3) {
			TPNumber testClass(16, 16, 3);
			string answer = "10";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_4) {
			TPNumber testClass(255, 2, 3);
			string answer = "11111111";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_5) {
			TPNumber testClass(14.471, 7, 5);
			string answer = "20.32036";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_6) {
			TPNumber testClass(14.471, 7, 5);
			string answer = "20.32036";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_7) {
			TPNumber testClass(145.1742, 15, 8);
			string answer = "9A.292DD1D2";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_8) {
			TPNumber testClass(36.09, 16, 2);
			string answer = "24.17";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_9) {
			TPNumber testClass(14.471, 7, 5);
			string answer = "20.32036";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_10) {
			TPNumber testClass(88.88, 8, 19);
			string answer = "130.7024365606075340000";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_11) {
			TPNumber testClass(256.256, 2, 5);
			string answer = "100000000.01000";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_12) {
			TPNumber testClass(115, 10, 5);
			string answer = "115";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_13) {
			TPNumber testClass(356.22, 10, 5);
			string answer = "356.22000";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_14) {
			TPNumber testClass(-356.22, 10, 5);
			string answer = "-356.22000";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_15) {
			TPNumber testClass(0, 2, 1);
			string answer = "0";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(InitAndOutput_16) {
			TPNumber testClass(0.01, 10, 2);
			string answer = "0.01";
			Assert::AreEqual(answer, testClass.getPString());
		}
		TEST_METHOD(Add_1) {
			TPNumber testClass1(15, 7, 5);
			TPNumber testClass2(66.66, 7, 5);
			testClass1 = testClass1.add(testClass2);
			double answer = 81.66;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Add_2) {
			TPNumber testClass1(12, 16, 11);
			TPNumber testClass2(-13, 3, 6);
			testClass1 = testClass1.add(testClass2);
			double answer = -1;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Multiply_1) {
			TPNumber testClass1(12.23, 7, 5);
			TPNumber testClass2(-6.66, 7, 5);
			testClass1 = testClass1.multiply(testClass2);
			double answer = -81.4518;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Multiply_2) {
			TPNumber testClass1(15.6, 16, 11);
			TPNumber testClass2(0, 3, 6);
			testClass1 = testClass1.multiply(testClass2);
			double answer = 0;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Substract_1) {
			TPNumber testClass1(12.23, 7, 5);
			TPNumber testClass2(6.66, 7, 5);
			testClass1 = testClass1.subtract(testClass2);
			double answer = 5.57;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Substract_2) {
			TPNumber testClass1(12.22, 16, 11);
			TPNumber testClass2(-6.66, 3, 6);
			testClass1 = testClass1.subtract(testClass2);
			double answer = 18.88;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Divide_1) {
			TPNumber testClass1(3, 7, 5);
			TPNumber testClass2(8, 7, 5);
			testClass1 = testClass1.divide(testClass2);
			double answer = 0.375;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Divide_2) {
			TPNumber testClass1(666, 16, 11);
			TPNumber testClass2(-333, 3, 6);
			testClass1 = testClass1.divide(testClass2);
			double answer = -2;
			Assert::AreEqual(answer, testClass1.getPNumber());
		}
		TEST_METHOD(Square) {
			TPNumber testClass(-1.57, 16, 11);
			testClass = testClass.square();
			double answer = 2.4649;
			Assert::AreEqual(answer, testClass.getPNumber());
		}
	};
}