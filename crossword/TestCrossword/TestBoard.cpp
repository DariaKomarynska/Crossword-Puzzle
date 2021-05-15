#include "CppUnitTest.h"
#include <iostream>
#include "..\crossword\Board.cpp"
#include "..\crossword\Board.h"

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
			b1.setUpField(1, 1);
			b1.fillField(1, 1, test);
			Assert::IsTrue(test == b1.getValue(1, 1));
		}

		TEST_METHOD(fill_get_00)
		{
			Board b1(3, 3);
			char test = "t"[0];
			b1.fillField(0, 0, test);
			Assert::IsTrue(test == b1.getValue(0, 0));
		}

		TEST_METHOD(fill_out_of_range)
		{
			std::string errmsg;
			std::string expected = "Index out of range";
			Board b1(3, 3);
			char test = "t"[0];
			try
			{
				b1.fillField(5, 0, "t"[0]);
			}
			catch (const char* msg)
			{
				errmsg = msg;
			}
			Assert::AreEqual(expected, errmsg);
		}


		TEST_METHOD(fillNotSettedUp)
		{
			std::string errmsg;
			std::string expected = "This field should remain empty";
			Board b1(3, 3);
			char test = "t"[0];
			try
			{
				b1.fillField(5, 0, "t"[0]);
			}
			catch (const char* msg)
			{
				errmsg = msg;
			}
			Assert::AreEqual(expected, errmsg);
		}

		TEST_METHOD(get_col_len)
		{
			Board b1(3, 3);
			Assert::IsTrue(b1.getNOColumns() == 3);
		}

		TEST_METHOD(get_row_len)
		{
			Board b1(3, 3);
			Assert::IsTrue(b1.getNORows() == 3);
		}


		TEST_METHOD(addRow)
		{
			Board board(3, 3);
			board.addRow();
			board.addRow();
			Assert::IsTrue(board.getNORows() == 5);
		}


		TEST_METHOD(addColumn)
		{
			Board board(3, 3);
			board.addColumn();
			Assert::IsTrue(board.getNOColumns() == 4);
		}


		TEST_METHOD(fillFiled)
		{
			Board b = Board(4, 4);

			b.setUpField(0, 0);
			b.setUpField(0, 1);
			b.setUpField(0, 2);
			b.setUpField(0, 3);

			b.fillField(0, 0, "A"[0]);
			b.fillField(0, 1, "B"[0]);
			b.fillField(0, 2, "I"[0]);
			b.fillField(0, 3, "D"[0]);

			Assert::AreEqual('A', b.getValue(0, 0));
			Assert::AreEqual('B', b.getValue(0, 1));
			Assert::AreEqual('I', b.getValue(0, 2));
			Assert::AreEqual('D', b.getValue(0, 3));
		}


		TEST_METHOD(clear)
		{
			Board b = Board(1, 3);

			b.setUpField(0, 0);
			b.setUpField(0, 3);

			b.fillField(0, 0, "A"[0]);
			b.putIndex(0, 2, 3);
			b.clear();

			Assert::AreEqual('_', b.getValue(0, 0));
			Assert::AreEqual('#',b.getValue(0, 1));
			Assert::AreEqual('_', b.getValue(0, 2));
		}
	};
	TEST_CLASS(OPERATOR_OVERLOAD)
	{
		TEST_METHOD(equality)
		{
			Board b(3, 3);
			Assert::IsTrue(b == b);
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
			b1.setUpField(0, 0);
			b1.setUpField(0, 1);
			b1.setUpField(0, 2);

			b1.fillField(0, 0, "a"[0]);
			b1.fillField(0, 1, "b"[0]);
			b1.fillField(0, 2, "c"[0]);
			os << b1;
			std::string out = "| a | b | c |\n| # | # | # |\n| # | # | # |\n";
			Assert::IsTrue(os.str() == out);
		}
		
	};
}
