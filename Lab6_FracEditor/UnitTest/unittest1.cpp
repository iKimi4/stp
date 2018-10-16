#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab6_FracEditor/TEditor.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(TestTEditor)
	{
	public:
		
		TEST_METHOD(Init_And_Output_1) {
			TEditor testClass;
			string output = "3/4";
			testClass.writeString(output);
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_2) {
			TEditor testClass;
			string output = "-16/3";
			testClass.writeString(output);
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_3) {
			TEditor testClass;
			string output = "0/8";
			testClass.writeString(output);
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_4) {
			TEditor testClass;
			string output = "-17/4";
			testClass.writeString(output);
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_5) {
			TEditor testClass;
			string output = "0/1";
			testClass.writeString(output);
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_6) {
			TEditor testClass;
			string output = "666/6666";
			testClass.writeString(output);
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_7) {
			TEditor testClass;
			testClass.writeString("aaaaa");
			string output = "0/1";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_8) {
			TEditor testClass;
			testClass.writeString("-01/-03");
			string output = "0/1";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_9) {
			TEditor testClass;
			testClass.writeString("00000/4");
			string output = "0/1";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Init_And_Output_10) {
			TEditor testClass;
			testClass.writeString("16/000000");
			string output = "0/1";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(IsZero_1) {
			TEditor testClass;
			testClass.writeString("14/3");
			Assert::AreEqual(false, testClass.isZero());
		}
		TEST_METHOD(IsZero_2) {
			TEditor testClass;
			testClass.writeString("16/000000");
			Assert::AreEqual(true, testClass.isZero());
		}
		TEST_METHOD(ToggleMinus_1) {
			TEditor testClass;
			testClass.writeString("3/4");
			testClass.toggleMinus();
			string output = "-3/4";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(ToggleMinus_2) {
			TEditor testClass;
			testClass.writeString("-3/4");
			testClass.toggleMinus();
			string output = "3/4";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(AddNumber_1) {
			TEditor testClass;
			testClass.writeString("-3/4");
			testClass.addNumber(4);
			string output = "-34/4";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(AddNumber_2) {
			TEditor testClass;
			testClass.writeString("0/1");
			testClass.addNumber(4);
			string output = "4/1";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(AddNumber_3) {
			TEditor testClass;
			testClass.writeString("42/3");
			testClass.toggleMode();
			testClass.addNumber(4);
			string output = "42/34";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(AddNumber_4) {
			TEditor testClass;
			testClass.writeString("42/3");
			testClass.toggleMode();
			testClass.addNumber(0);
			string output = "42/30";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(DelNumber_1) {
			TEditor testClass;
			testClass.writeString("42/3");
			testClass.delSymbol();
			string output = "4/3";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(DelNumber_2) {
			TEditor testClass;
			testClass.writeString("0/3");
			testClass.delSymbol();
			string output = "0/3";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(DelNumber_3) {
			TEditor testClass;
			testClass.writeString("2/3");
			testClass.delSymbol();
			string output = "0/3";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(DelNumber_4) {
			TEditor testClass;
			testClass.writeString("42/3");
			testClass.toggleMode();
			testClass.delSymbol();
			string output = "42/1";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(DelNumber_5) {
			TEditor testClass;
			testClass.writeString("42/33");
			testClass.toggleMode();
			testClass.delSymbol();
			string output = "42/3";
			Assert::AreEqual(output, testClass.readString());
		}
		TEST_METHOD(Clear) {
			TEditor testClass;
			testClass.writeString("42/33");
			testClass.clear();
			string output = "0/1";
			Assert::AreEqual(output, testClass.readString());
		}

	};
}