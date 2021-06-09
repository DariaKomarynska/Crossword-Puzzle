#include <vector>
#include "CppUnitTest.h"
#include "../crossword/Crossword.h"
#include "../crossword/Crossword.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCrossword
{
	TEST_CLASS(TestCrossword)
	{
	public:

		/*TEST_METHOD(CreateFromFile) {
			Crossword cross = Crossword("../crossword/test_data1.txt");
			Assert::AreEqual(9, cross.getNOQuestions());
			Board b = Board();
			std::stringstream s;
			s << "     1   2   3   4   5   6\n 1 | # | _ | # | _ | # | # |\n 2 | _ | _ | _ | _ | # | _ |\n 3 | # | _ | _ | _ | _ | _ |\n 4 | # | _ | _ | _ | _ | _ |\n 5 | _ | _ | _ | _ | _ | _ |\n";
			s >> b;

			Assert::AreEqual((string)"armata", cross.correctAnswer(0));
			Assert::AreEqual((string)"bufor", cross.correctAnswer(1));
			Assert::AreEqual((string)"data", cross.correctAnswer(2));
			Assert::AreEqual((string)"ferm", cross.correctAnswer(3));
			Assert::AreEqual((string)"ferma", cross.correctAnswer(4));
			Assert::AreEqual((string)"marna", cross.correctAnswer(5));
			Assert::AreEqual((string)"mat", cross.correctAnswer(6));
			Assert::AreEqual((string)"mufa", cross.correctAnswer(7));
			Assert::AreEqual((string)"ornat", cross.correctAnswer(8));

			Assert::IsTrue(b == cross.getBoard());
		}*/


		TEST_METHOD(TestCrosswordQuestions)
		{
			vector<vector<int>> pair = { {1, 1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			vector<std::string> questions = { "piwo to moje", "pszczola bez czola" };
			Assert::IsTrue(questions == crossword.getQuestions());
		}

		TEST_METHOD(TestCrosswordOrientation)
		{
			vector<vector<int>> pair = { {1, 1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			std::string orientation = "horizontally";
			Assert::AreEqual(orientation, crossword.getOrientation(1));
		}

		TEST_METHOD(TestCrosswordCoordinates)
		{
			vector<vector<int>> pair = { {1, 1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			vector<int> coordinates = { 1, 1 };
			Assert::IsTrue(coordinates == crossword.getFirstLetterCoords(1));
		}

		TEST_METHOD(TestCrosswordCoordinateRow)
		{
			vector<vector<int>> pair = { {1, 1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int row_coord = 1;
			Assert::AreEqual(row_coord, crossword.getFirstLetterRow(1));
		}

		TEST_METHOD(TestCrosswordCoordinateCol)
		{
			vector<vector<int>> pair = { {1,2}, {1, 0} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int col_coord = 0;
			Assert::AreEqual(col_coord, crossword.getFirstLetterCol(1));
		}

		TEST_METHOD(TestCrosswordCorrectAnswer)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			crossword.fillAnswer(1, "psz");
			Assert::AreEqual("p"[0], crossword.getBoard().getValue(1, 1));
			Assert::AreEqual("s"[0], crossword.getBoard().getValue(1, 2));
			Assert::AreEqual("z"[0], crossword.getBoard().getValue(1, 3));
		}

		TEST_METHOD(TestCrosswordIncorrectAnswer)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			Assert::IsFalse(crossword.isCorrectAnswer(1, "peppa"));
		}

		TEST_METHOD(TestCrosswordIncorrectSizeNotFill)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			crossword.fillAnswer(1, "niepsz");
			Assert::AreEqual("n"[0], crossword.getBoard().getValue(1, 1));
			Assert::AreEqual("i"[0], crossword.getBoard().getValue(1, 2));
			Assert::AreEqual("e"[0], crossword.getBoard().getValue(1, 3));
		}

		TEST_METHOD(TestCrosswordIncorrectAnswerFill)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			crossword.fillAnswer(1, "poo");
			Assert::AreEqual("p"[0], crossword.getBoard().getValue(1, 1));
			Assert::AreEqual("o"[0], crossword.getBoard().getValue(1, 2));
			Assert::AreEqual("o"[0], crossword.getBoard().getValue(1, 3));
		}
		TEST_METHOD(TestCrosswordCorrectNumberQuestion)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			Assert::IsTrue(crossword.isNumberOfQuestion(1));
		}

		TEST_METHOD(TestCrosswordIncorrectNumberQuestion)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			Assert::IsFalse(crossword.isNumberOfQuestion(5));
		}

		TEST_METHOD(TestCrosswordIndexAnswer)
		{
			vector<vector<int>> pair = { {1,1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int correctIndex = 1;
			Assert::AreEqual(correctIndex, crossword.getIndexAnswer("psz"));
		}

		TEST_METHOD(TestCrosswordFirstRowWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int row = 3; // board starts in (0,0)
			Assert::AreEqual(row, crossword.getLetterRow("psz"));
		}

		TEST_METHOD(TestCrosswordFirstYWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int col = 5; // board starts in (0,0)
			Assert::AreEqual(col, crossword.getLetterCol("psz"));
		}

		TEST_METHOD(TestCrosswordLetterPositionInHorWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int pos = 1; // board starts in (0,0)
			Assert::AreEqual(pos, crossword.letterPosition("psz", 's'));
		}

		TEST_METHOD(TestCrosswordLetterPositionInVerWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int pos = 4; // board starts in (0,0)
			Assert::AreEqual(pos, crossword.letterPosition("paliwo", 'w'));
		}

		TEST_METHOD(TestCrosswordRowCoordLetterInHorWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int row = 3; // board starts in (0,0)
			Assert::AreEqual(row, crossword.getLetterRow("psz", 's'));
		}

		TEST_METHOD(TestCrosswordColCoordLetterInHorWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int Col = 6; // board starts in (0,0)
			Assert::AreEqual(Col, crossword.getLetterCol("psz", 's'));
		}

		TEST_METHOD(TestCrosswordRowCoordLetterInVerWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int Row = 5; // board starts in (0,0)
			Assert::AreEqual(Row, crossword.getLetterRow("paliwo", 'w'));
		}

		TEST_METHOD(TestCrosswordColCoordLetterInVerWord)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int Col = 1; // board starts in (0,0)
			Assert::AreEqual(Col, crossword.getLetterCol("paliwo", 'w'));
		}

		TEST_METHOD(TestCrosswordLastWordInDictionary)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");
			Crossword crossword = Crossword(dict, pair, orientations);

			Assert::IsFalse(crossword.isNotLastAnswer("psz"));
		}

		TEST_METHOD(TestCrosswordNotLastWordInDictionary)
		{
			vector<vector<int>> pair = { {1,1}, {3,5} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");
			Crossword crossword = Crossword(dict, pair, orientations);

			Assert::IsTrue(crossword.isNotLastAnswer("paliwo"));
		}
	};
}
