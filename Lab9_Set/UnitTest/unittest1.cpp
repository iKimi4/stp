#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab9_Set/TSet.h"
#include "../../Lab1_FracClass/Lab1_Fraction/TFrac.h"
#include <random>
#include <ctime>
#include <iterator>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest {
	TEST_CLASS(SetContainer) {
public:

	TEST_METHOD(Init_Test) {
		srand(time(NULL));
		TSet< TFrac > testClass;
		set< TFrac > testSet;
		for (int i = 0; i < 10; ++i) {
			TFrac frac(rand() % 10, rand() % 10);
			testClass.add(frac);
			testSet.insert(frac);
		}
		bool expectedResult = true;
		for (int i = 0; i < 10; ++i)
			testSet.erase(testClass.elem(i));
		bool result = testSet.size() == 0 ? true : false;
		Assert::AreEqual(expectedResult, result);
	}
	TEST_METHOD(Concatenation_Test) {
		srand(time(NULL));
		TSet<TFrac> testClass1;
		TSet<TFrac> testClass2;
		TSet<TFrac> testClassResult;
		set<TFrac> testSet1;
		set<TFrac> testSet2;
		set<TFrac> testSetResult;
		int numberOfElems = 10;
		for (int i = 0; i < numberOfElems; ++i) {
			TFrac frac(rand() % 100, rand() % 100);
			testClass1.add(frac);
			testSet1.insert(frac);
		}
		for (int i = 0; i < numberOfElems; ++i) {
			TFrac frac(rand() % 100, rand() % 100);
			testClass2.add(frac);
			testSet2.insert(frac);
		}
		testClassResult = testClass1.ñoncatenation(testClass2);
		set_union(testSet1.begin(), testSet1.end(),
			testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
		bool expectedResult = true;
		for (int i = 0; i < numberOfElems * 2; ++i)
			testSetResult.erase(testClassResult.elem(i));
		bool result = testSetResult.size() == 0 ? true : false;
		Assert::AreEqual(expectedResult, result);
	}

	TEST_METHOD(Complement_Test) {
		srand(time(NULL));
		TSet<TFrac> testClass1;
		TSet<TFrac> testClass2;
		TSet<TFrac> testClassResult;
		set<TFrac> testSet1;
		set<TFrac> testSet2;
		set<TFrac> testSetResult;
		int numberOfElems = 15;
		for (int i = 0; i < numberOfElems; ++i) {
			TFrac frac(rand() % 10, rand() % 10);
			testClass1.add(frac);
			testSet1.insert(frac);
		}
		for (int i = 0; i < numberOfElems; ++i) {
			TFrac frac(rand() % 10, rand() % 10);
			testClass2.add(frac);
			testSet2.insert(frac);
		}
		testClassResult = testClass1.complement(testClass2);
		set_difference(testSet1.begin(), testSet1.end(),
			testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
		bool expectedResult = true;
		for (int i = 0; i < numberOfElems; ++i)
			testSetResult.erase(testClassResult.elem(i));
		bool result = testSetResult.size() == 0 ? true : false;
		Assert::AreEqual(expectedResult, result);
	}

	TEST_METHOD(Multiply_Test) {
		srand(time(NULL));
		TSet<TFrac> testClass1;
		TSet<TFrac> testClass2;
		TSet<TFrac> testClassResult;
		set<TFrac> testSet1;
		set<TFrac> testSet2;
		set<TFrac> testSetResult;
		int numberOfElems = 10;
		for (int i = 0; i < numberOfElems; ++i) {
			TFrac frac(rand() % 100, rand() % 100);
			testClass1.add(frac);
			testSet1.insert(frac);
		}
		for (int i = 0; i < numberOfElems; ++i) {
			TFrac frac(rand() % 100, rand() % 100);
			testClass2.add(frac);
			testSet2.insert(frac);
		}
		testClassResult = testClass1.multiply(testClass2);
		set_intersection(testSet1.begin(), testSet1.end(),
			testSet2.begin(), testSet2.end(), inserter(testSetResult, testSetResult.begin()));
		bool expectedResult = true;
		for (int i = 0; i < numberOfElems * 2; ++i)
			testSetResult.erase(testClassResult.elem(i));
		bool result = testSetResult.size() == 0 ? true : false;
		Assert::AreEqual(expectedResult, result);
	}

	};
}