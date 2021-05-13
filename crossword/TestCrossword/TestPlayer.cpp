#include <vector>
#include "CppUnitTest.h"
#include "../crossword/Player.h"
#include "../crossword/Player.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testPlayer
{
	TEST_CLASS(testPlayer)
	{
	public:

		TEST_METHOD(TestPlayerSimple)
		{
			Player byk = Player("byczeq");
			std::string name = "byczeq";
			Assert::AreEqual(name, byk.getName());
			Assert::AreEqual(0, byk.getPoints());
		}


		TEST_METHOD(TestPlayerInitEmpty)
		{
			Player byk = Player();
			std::string name = "";
			Assert::AreEqual(name, byk.getName());
			Assert::AreEqual(0, byk.getPoints());
		}


		TEST_METHOD(TestPlayerPoints)
		{
			Player byk = Player("byczeq");

			byk.addPoints(4);
			Assert::AreEqual(4, byk.getPoints());

			byk.substractPoints(1);
			Assert::AreEqual(3, byk.getPoints());
		}

		TEST_METHOD(TestPlayerNewName)
		{
			Player byk = Player("byczeq");
			byk.setName("byq");
			std::string name = "byq";
			Assert::AreEqual(name, byk.getName());
			Assert::AreEqual(0, byk.getPoints());
		}

		TEST_METHOD(TestPlayerEmptyInitNewName)
		{
			Player byk = Player();
			byk.setName("byq");
			std::string name = "byq";
			Assert::AreEqual(name, byk.getName());
			Assert::AreEqual(0, byk.getPoints());
		}

		TEST_METHOD(TestPlayerPointsNegative)
		{
			Player byk = Player("byczeq");
			byk.substractPoints(1);
			Assert::AreEqual(0, byk.getPoints());
		}

		TEST_METHOD(TestPlayerResetPoints)
		{
			Player byk = Player("byczeq");

			byk.addPoints(4);
			Assert::AreEqual(4, byk.getPoints());

			byk.resetPoints();
			Assert::AreEqual(0, byk.getPoints());
		}

		TEST_METHOD(TestPlayerNewGame)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			Assert::AreEqual(byk.getPoints(), 30);

			byk.newGame();
			Assert::AreEqual(byk.getPoints(), 0);
			std::vector< int > st{ 30 };
			Assert::AreEqual(byk.getPointList().size(), st.size());
			Assert::AreEqual(byk.getPointList().at(0), st.at(0));
		}


		TEST_METHOD(TestPlayerPointStatistics)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			byk.newGame();
			byk.addPoints(20);
			byk.newGame();
			byk.addPoints(10);
			byk.newGame();

			std::vector< int > st{ 30, 20, 10 };
			Assert::AreEqual(byk.getPointList().size(), st.size());

			if (byk.getPointList().size() == st.size()) {
				for (std::size_t i = 0; i < st.size(); ++i)
					Assert::AreEqual(byk.getPointList().at(i), st.at(i));
			}
		}


		TEST_METHOD(TestPlayergetAveragePoints)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			byk.newGame();
			byk.addPoints(20);
			byk.newGame();
			byk.addPoints(10);
			byk.newGame();

			int av = 20;
			Assert::AreEqual(byk.getAveragePoints(), av);
		}


		TEST_METHOD(TestPlayerGetStatistics)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			byk.newGame();
			byk.addPoints(20);
			byk.newGame();
			byk.addPoints(10);
			byk.newGame();

			std::string st = "Game\tPoints\n1\t30\n2\t20\n3\t10\n";
			Assert::AreEqual(byk.getStatistisc(), st);
		}


		TEST_METHOD(TestPlayergetStatisticsEmpyt)
		{
			Player byk = Player("byczeq");

			std::string st = "No statistics to show\n";
			Assert::AreEqual(st, byk.getStatistisc());
		}


		TEST_METHOD(TestPlayerIostream)
		{
			std::stringstream ss;

			Player byk = Player("byczeq");
			byk.addPoints(30);
			byk.newGame();
			byk.addPoints(20);
			byk.newGame();
			byk.addPoints(10);

			ss << byk;

			Player byk2 = Player();

			ss >> byk2;

			std::string name = "byczeq";
			Assert::AreEqual(name, byk2.getName());
			Assert::AreEqual(10, byk2.getPoints());

			std::vector< int > st{ 30, 20 };
			if (byk.getPointList().size() == st.size()) {
				for (std::size_t i = 0; i < st.size(); ++i)
					Assert::AreEqual(st.at(i), byk.getPointList().at(i));
			}
		}


		TEST_METHOD(TestPlayerPlusOp)
		{
			Player byk1 = Player("byczeq");
			byk1.addPoints(30);
			byk1.newGame();
			byk1.addPoints(20);
			byk1.newGame();
			byk1.addPoints(10);

			Player byk2 = Player("mordunia");
			byk2.addPoints(12);
			byk2.newGame();
			byk2.addPoints(7);
			byk2.newGame();
			byk2.addPoints(9);

			Player byk3 = byk1 + byk2;

			std::string name = "byczeq";
			Assert::AreEqual(name, byk3.getName());
			Assert::AreEqual(19, byk3.getPoints());

			std::vector< int > st{ 30, 20, 12, 7 };
			if (byk3.getPointList().size() == st.size()) {
				for (std::size_t i = 0; i < st.size(); ++i)
					Assert::AreEqual(st.at(i), byk3.getPointList().at(i));
			}
		}

		TEST_METHOD(TestPlayerPlusEqOp)
		{
			Player byk = Player();
			byk.addPoints(10);

			byk += 2;
			Assert::AreEqual(12, byk.getPoints());
		}


		TEST_METHOD(TestPlayerMinusEqOp)
		{
			Player byk = Player();
			byk.addPoints(10);

			byk -= 2;
			Assert::AreEqual(8, byk.getPoints());
		}


		TEST_METHOD(TestPlayerIncrementOp)
		{
			Player byk = Player();
			byk++;
			Assert::AreEqual(1, byk.getPoints());
		}


		TEST_METHOD(TestPlayerDecrementOp)
		{
			Player byk = Player();
			byk.addPoints(10);
			byk--;
			Assert::AreEqual(9, byk.getPoints());
		}
	};
}
