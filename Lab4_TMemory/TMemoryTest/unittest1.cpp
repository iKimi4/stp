#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab4_TMemory/TMemory.h"
#include "../../Lab1_FracClass/Lab1_Fraction/TFrac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TMemoryTest
{		
	TEST_CLASS(Test_Memory)
	{
	public:
		
		TEST_METHOD(Init_And_Ouput_1) {
			TFrac templateObj;
			TMemory<TFrac> memObj(templateObj);
			TFrac testObj(1, 2);
			testObj = memObj.getMemory();
			string answer = "0/1";
			Assert::AreEqual(answer, testObj.getFractionString());
		}
		TEST_METHOD(Init_And_Ouput_2) {
			TFrac templateObj(22, 33);
			TMemory<TFrac> memObj(templateObj);
			TFrac testObj(1, 2);
			testObj = memObj.getMemory();
			string answer = "2/3";
			Assert::AreEqual(answer, testObj.getFractionString());
		}
		TEST_METHOD(Init_And_Ouput_3) {
			TFrac templateObj(-1, 5);
			TMemory<TFrac> memObj(templateObj);
			TFrac testObj(1, 2);
			testObj = memObj.getMemory();
			string answer = "-1/5";
			Assert::AreEqual(answer, testObj.getFractionString());
		}
		TEST_METHOD(Init_And_Ouput_4) {
			int number = 3;
			TMemory<int> memObj(number);
			Assert::AreEqual(number, memObj.getMemory());
		}
		TEST_METHOD(Sum_1) {
			TFrac templateObj(-1, 5);
			TMemory<TFrac> memObj(templateObj);
			TFrac testObj(1, 2);
			memObj.sumMemory(testObj);
			string answer = "3/10";
			Assert::AreEqual(answer, memObj.getMemory().getFractionString());
		}
		TEST_METHOD(Sum_2) {
			TFrac templateObj(8, 9);
			TMemory<TFrac> memObj(templateObj);
			TFrac testObj(-16, 3);
			memObj.sumMemory(testObj);
			string answer = "-40/9";
			Assert::AreEqual(answer, memObj.getMemory().getFractionString());
		}
		TEST_METHOD(Clear) {
			TFrac templateObj(3, 4);
			TMemory<TFrac> memObj(templateObj);
			memObj.clearMemory();
			TFrac clearObj;
			Assert::AreEqual(clearObj.getFractionString(), memObj.getMemory().getFractionString());
		}
		TEST_METHOD(FState_Handle_1) {
			TFrac templateObj(3, 4);
			TMemory<TFrac> memObj(templateObj);
			memObj.clearMemory();
			int fStateExpected = OFF;
			Assert::AreEqual(fStateExpected, memObj.getNumber());
		}
		TEST_METHOD(FState_Handle_2) {
			TFrac templateObj(3, 4);
			TMemory<TFrac> memObj(templateObj);
			int fStateExpected = OFF;
			Assert::AreEqual(fStateExpected, memObj.getNumber());
		}
		TEST_METHOD(FState_Handle_3) {
			TFrac templateObj(3, 4);
			TMemory<TFrac> memObj(templateObj);
			memObj.sumMemory(TFrac(1,4));
			int fStateExpected = ON;
			Assert::AreEqual(fStateExpected, memObj.getNumber());
		}

	};
}