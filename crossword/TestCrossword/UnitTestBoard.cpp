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
			b1.fillField(2, 2, "a"[0]);
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
			b2.fillField(2, 2, "a"[0]);
			b3.fillField(5, 2, "a"[0]);
			Assert::IsTrue(b1 + b2 == b3);
		}

		TEST_METHOD(add_second_empty)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3(6, 3);
			b1.fillField(2, 2, "a"[0]);
			b3.fillField(2, 2, "a"[0]);
			Assert::IsTrue(b1 + b2 == b3);
		}

		TEST_METHOD(add_none_empty)
		{
			Board b1(3, 3);
			Board b2(3, 3);
			Board b3(6, 3);
			b1.fillField(2, 2, "a"[0]);
			b2.fillField(2, 2, "a"[0]);
			b3.fillField(2, 2, "a"[0]);
			b3.fillField(5, 2, "a"[0]);
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
			b1.fillField(0, 0, "a"[0]);
			b1.fillField(0, 1, "b"[0]);
			b1.fillField(1, 0, "c"[0]);
			b1.fillField(2, 1, "d"[0]);
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
			b2.fillField(0, 0, "a"[0]);
			b2.fillField(0, 1, "b"[0]);
			b2.fillField(1, 0, "c"[0]);
			b2.fillField(1, 1, "d"[0]);
			Assert::IsTrue(b1 == b2);
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

		TEST_METHOD(clear)
		{

		}

		TEST_METHOD(putQuestionOnBoard)
		{
			Board b = Board();
			b.putQuestionOnBoard(0, 0, "vertically", "DZIK", 4);

			Assert::AreEqual(1, b.getNOColumns());
			Assert::AreEqual(4, b.getNORows());

			Assert::AreEqual('_', b.getValue(0, 0));
			Assert::AreEqual('_', b.getValue(0, 1));
			Assert::AreEqual('_', b.getValue(0, 2));
			Assert::AreEqual('_', b.getValue(0, 3));

			Assert::AreEqual('_', b.getValue(0, 0));
			Assert::AreEqual('_', b.getValue(0, 1));
			Assert::AreEqual('_', b.getValue(0, 2));
			Assert::AreEqual('_', b.getValue(0, 3));

		}

		TEST_METHOD(initWithCSVFile)
		{
			/*std::string filename = "test_data1.csv";
			Board b1(9, filename);
			Assert::IsTrue('U' == b1.getValue(1, 1));*/
		}

		TEST_METHOD(getQuestions)
		{
			/*std::string filename = "test_data1.csv";
			Board b1(9, filename);
			std::vector<std::string> correct_ques;
			correct_ques = { "Zderzak pociągu", "Złączka rur", "Gospodarstwo hodowlane",
				"Szata liturgiczna", "Działo", "Aktywowiec o l. a. 100", "Prawy dopływ Sekwany", "Kapral na statku",
				"Co dzień inna w kalendarzu" };
			Assert::IsTrue(b1.getQuestions() == correct_ques);*/
		}

		TEST_METHOD(fillAnswer)
		{
			Board b = Board();

		}
		
	};
}
