#include "CppUnitTest.h"
#include "../crossword/Field.h"
#include "../crossword/Field.cpp"
#include "../crossword/crosswordErrors.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCrossword
{
	TEST_CLASS(TestField)
	{
	public:
		TEST_METHOD(createDefaultFiled)
		{
			Field f = Field();
			Assert::AreEqual('#', f.getValue());
		}


		TEST_METHOD(createFiledChar)
		{
			Field f = Field('A');
			Assert::AreEqual('a', f.getValue());
		}


		TEST_METHOD(createFiledString)
		{
			Field f = Field("A");
			Assert::AreEqual('a', f.getValue());
		}


		TEST_METHOD(fillChar)
		{
			Field f = Field('C');
			f.fill('B');
			Assert::AreEqual('b', f.getValue());
		}


		TEST_METHOD(fillString)
		{
			Field f = Field('C');
			f.fill("B");
			Assert::AreEqual('b', f.getValue());
		}


		TEST_METHOD(fillInt)
		{
			Field f = Field('C');
			f.putIndex(44);
			char c = char('44');
			Assert::AreEqual(c, f.getValue());
		}

		TEST_METHOD(fillNotSettedUp)
		{
			const char* expected = "This field should remain empty.";
			Field f = Field();
			
			try
			{
				f.fill('V');
			}
			catch (const FieldNotSettedUp& err)
			{
				Assert::AreEqual(expected, err.what());
			}
		}


		TEST_METHOD(fillIncorrectChar)
		{
			const char* expected = "This field should store alpha or space.";
			Field f = Field();
			f.setUp();

			try {
				f.fill(',');
			}
			catch (const NotAlphaOrSpace& err) {
				Assert::AreEqual(expected, err.what());
			}
		}


		TEST_METHOD(setUp)
		{
			Field f = Field();
			f.setUp();
			f.fill('C');
			Assert::AreEqual('c', f.getValue());
		}


		TEST_METHOD(clear)
		{
			Field f = Field('C');
			f.clear();
			Assert::AreEqual('_', f.getValue());
		}


		TEST_METHOD(clearEmpty)
		{
			Field f = Field();
			f.clear();
			Assert::AreEqual('#', f.getValue());
		}


		TEST_METHOD(fillSpace)
		{
			Field f = Field();
			f.setUp();
			f.fill(' ');
			Assert::AreEqual(' ', f.getValue());
		}
	};
}
