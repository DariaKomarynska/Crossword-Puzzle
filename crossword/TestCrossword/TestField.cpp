#include "CppUnitTest.h"
#include "../crossword/Field.h"
#include "../crossword/Field.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCrossword
{
	TEST_CLASS(TestField)
	{
	public:

		TEST_METHOD(createDefaultFiled)
		{
			Field f = Field();
			Assert::IsTrue(f.isExpected('#'));
			Assert::AreEqual('#', f.value);
			Assert::AreEqual(-1, f.NOQuestion);
		}


		TEST_METHOD(createCustomFiled)
		{
			Field f = Field(3, 'A');
			Assert::IsTrue(f.isExpected('A'));
			Assert::AreEqual('_', f.value);
			Assert::AreEqual(3, f.NOQuestion);
		}


		TEST_METHOD(postInit)
		{
			Field f = Field();
			f.postInit(2, 'B');
			Assert::IsTrue(f.isExpected('B'));
			Assert::AreEqual('_', f.value);
			Assert::AreEqual(2, f.NOQuestion);
		}


		TEST_METHOD(fill)
		{
			Field f = Field(0, 'C');
			f.fill('B');
			Assert::AreEqual('B', f.value);
		}


		TEST_METHOD(isCorrect)
		{
			Field f = Field(0, 'C');
			f.fill('C');
			Assert::IsTrue(f.isCorrect());
		}


		TEST_METHOD(clear)
		{
			Field f = Field(0, 'C');
			f.fill('C');
			Assert::AreEqual('C', f.value);
			f.clear();
			Assert::AreEqual('_', f.value);
			Assert::AreEqual(0, f.NOQuestion);
			Assert::IsTrue(f.isExpected('C'));
		}
	};
}
