#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab5_Processor/TProc.h"
#include "../../Lab1_FracClass/Lab1_Fraction/TFrac.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TProcTest
{		
	TEST_CLASS(TProc_Test)
	{
	public:
		
		TEST_METHOD(Init_1) {
			TFrac leftFrac;
			TFrac rightFrac;
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer;
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Init_2) {
			TFrac leftFrac(11, 3);
			TFrac rightFrac;
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer(11, 3);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Init_3) {
			TFrac leftFrac(16, 4);
			TFrac rightFrac(17, 9);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer(17, 9);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}
		TEST_METHOD(Operation_1) {
			TFrac leftFrac(1, 2);
			TFrac rightFrac(1, 2);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOprtn oper = Add;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(1, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Operation_2) {
			TFrac leftFrac(3, 4);
			TFrac rightFrac(5, 6);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOprtn oper = Sub;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(-1, 12);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Operation_3) {
			TFrac leftFrac(12, 7);
			TFrac rightFrac(5, 9);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOprtn oper = Mul;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(20, 21);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Operation_4) {
			TFrac leftFrac(56, 7);
			TFrac rightFrac(-22, 3);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOprtn oper = Div;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(-12, 11);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Function_1) {
			TFrac leftFrac(56, 7);
			TFrac rightFrac(-22, 3);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Rev;
			obj.doFunc(funcOper);
			TFrac answer(-3, 22);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}
		TEST_METHOD(Function_2) {
			TFrac leftFrac(56, 7);
			TFrac rightFrac(-22, 3);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Sqr;
			obj.doFunc(funcOper);
			TFrac answer(484, 9);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}
	};
}