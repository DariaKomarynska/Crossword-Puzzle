#include "CppUnitTest.h"
#include <iostream>
#include "..\PROI_Lab_3\Board.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestBoard
{
	TEST_CLASS(FUNCTIONS)
	{
	public:

		TEST_METHOD(fill_get_normal)
		{
			Board b1(3, 3);
			char test = "t"[0];
			b1.fill_field(1, 1, test);
			Assert::IsTrue(test == b1.get_field(1, 1));
		}

		TEST_METHOD(fill_get_00)
		{
			Board b1(3, 3);
			char test = "t"[0];
			b1.fill_field(0, 0, test);
			Assert::IsTrue(test == b1.get_field(0, 0));
		}

		TEST_METHOD(fill_out_of_range)
		{
			std::string exp;
			std::string expected = "Index out of range";
			Board b1(3, 3);
			char test = "t"[0];
			try
			{
				b1.fill_field(5, 0, "t"[0]);
			}
			catch (const char* msg)
			{
				exp = msg;
			}
			Assert::AreEqual(exp, expected);
		}

		TEST_METHOD(get_col_len)
		{
			Board b1(3, 3);
			Assert::IsTrue(b1.get_col_len() == 3);
		}

		TEST_METHOD(get_row_len)
		{
			Board b1(3, 3);
			Assert::IsTrue(b1.get_row_len() == 3);
		}

	};
	TEST_CLASS(OPERATOR_OVERLOAD)
	{
		TEST_METHOD(equality)
		{
			Board b(3, 3);
			Assert::IsTrue(b == b);
		}

		TEST_METHOD(preincrement)
		{
			Board b1(3, 3);
			Board b2(4, 3);
			Assert::IsTrue(++b1 == b2);
		}

		TEST_METHOD(postincrement)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3 = b1++;
			Assert::IsTrue(b2 == b3);
		}

		TEST_METHOD(predecrement)
		{
			Board b1(4, 3);
			Board b2(3, 3);
			Assert::IsTrue(--b1 == b2);
		}

		TEST_METHOD(postdecrement)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3 = b1--;
			Assert::IsTrue(b2 == b3);
		}

		TEST_METHOD(decrement_and_increment)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			b1.fill_field(2, 2, "a"[0]);
			--b1;
			++b1;
			Assert::IsTrue(b1 == b2);
		}

		TEST_METHOD(add_both_empty)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3(6, 3);
			Assert::IsTrue(b1 + b2 == b3);
		}

		TEST_METHOD(add_first_empty)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3(6, 3);
			b2.fill_field(2, 2, "a"[0]);
			b3.fill_field(5, 2, "a"[0]);
			Assert::IsTrue(b1 + b2 == b3);
		}

		TEST_METHOD(add_second_empty)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3(6, 3);
			b1.fill_field(2, 2, "a"[0]);
			b3.fill_field(2, 2, "a"[0]);
			Assert::IsTrue(b1 + b2 == b3);
		}

		TEST_METHOD(add_none_empty)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3(6, 3);
			b1.fill_field(2, 2, "a"[0]);
			b2.fill_field(2, 2, "a"[0]);
			b3.fill_field(2, 2, "a"[0]);
			b3.fill_field(5, 2, "a"[0]);
			Assert::IsTrue(b1 + b2 == b3);
		}

		TEST_METHOD(ostream_empty)
		{
			std::stringstream os;
			Board b1(3, 3);
			os << b1;
			std::string out = "Empty Board";
			Assert::IsTrue(os.str() == out);
		}

		TEST_METHOD(ostream_filled)
		{
			std::stringstream os;
			Board b1(3, 3);
			b1.fill_field(0, 0, "a"[0]);
			b1.fill_field(0, 1, "b"[0]);
			b1.fill_field(1, 0, "c"[0]);
			b1.fill_field(2, 1, "d"[0]);
			os << b1;
			std::string out = " a | b |    \n c |        \n     d |    \n";
			Assert::IsTrue(os.str() == out);
		}

		TEST_METHOD(istream)
		{
			Board b1(3, 3);
			Board b2(2, 2);
			std::stringstream is;
			std::string input = "a|b||c|d";
			is << input;
			is >> b1;
			b2.fill_field(0, 0, "a"[0]);
			b2.fill_field(0, 1, "b"[0]);
			b2.fill_field(1, 0, "c"[0]);
			b2.fill_field(1, 1, "d"[0]);
			Assert::IsTrue(b1 == b2);
		}

	};
}
