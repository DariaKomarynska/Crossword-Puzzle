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

		TEST_METHOD(TestCrosswordCoordinateX)
		{
			vector<vector<int>> pair = { {1, 1}, {1, 1} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int x_coord = 1;
			Assert::AreEqual(x_coord, crossword.getFirstLetterX(1));
		}

		TEST_METHOD(TestCrosswordCoordinateY)
		{
			vector<vector<int>> pair = { {1,2}, {1, 0} };
			vector<std::string> orientations = { "vertically", "horizontally" };

			Dictionary dict = Dictionary();
			dict.add_word("paliwo", "piwo to moje");
			dict.add_word("psz", "pszczola bez czola");

			Crossword crossword = Crossword(dict, pair, orientations);
			int y_coord = 0;
			Assert::AreEqual(y_coord, crossword.getFirstLetterY(1));
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
			Assert::AreEqual("_"[0], crossword.getBoard().getValue(1, 1));
			Assert::AreEqual("_"[0], crossword.getBoard().getValue(1, 2));
			Assert::AreEqual("_"[0], crossword.getBoard().getValue(1, 3));
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
	};
}
