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
			f.fill(44);
			char c = '44';
			Assert::AreEqual(c, f.getValue());
		}

		TEST_METHOD(fillNotSettedUp)
		{
			std::string errmsg;
			std::string expected = "This field should remain empty";
			Field f = Field();
			
			try
			{
				f.fill('V');
			}
			catch (const char* msg)
			{
				errmsg = msg;
			}
			Assert::AreEqual(expected, errmsg);
		}


		TEST_METHOD(fillIncorrectChar)
		{
			std::string errmsg;
			std::string expected = "You can fill this field only with letter or number";
			Field f = Field();
			f.setUp();

			try
			{
				f.fill(',');
			}
			catch (const char* msg)
			{
				errmsg = msg;
			}
			Assert::AreEqual(expected, errmsg);
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
	};
}
