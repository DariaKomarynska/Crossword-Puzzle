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


		TEST_METHOD(TestPlayerPointsNegative)
		{
			Player byk = Player("byczeq");
			byk.substractPoints(1);
			Assert::AreEqual(0, byk.getPoints());
		}


		TEST_METHOD(TestPlayerEndGame)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			Assert::AreEqual(byk.getPoints(), 30);
			
			byk.endGame();
			Assert::AreEqual(byk.getPoints(), 0);
			std::vector< int > st{ 30 };
			Assert::AreEqual(byk.getPointList().size(), st.size());
			Assert::AreEqual(byk.getPointList().at(0), st.at(0));
		}


		TEST_METHOD(TestPlayerPointStatistics)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			byk.endGame();
			byk.addPoints(20);
			byk.endGame();
			byk.addPoints(10);
			byk.endGame();

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
			byk.endGame();
			byk.addPoints(20);
			byk.endGame();
			byk.addPoints(10);
			byk.endGame();

			int av = 20;
			Assert::AreEqual(byk.getAveragePoints(), av);
		}


		TEST_METHOD(TestPlayerGetStatistics)
		{
			Player byk = Player("byczeq");
			byk.addPoints(30);
			byk.endGame();
			byk.addPoints(20);
			byk.endGame();
			byk.addPoints(10);
			byk.endGame();

			std::string st = "Game\tPoints\n1\t30\n2\t20\n3\t10\n";
			Assert::AreEqual(byk.getStatistisc(), st);
		}


		TEST_METHOD(TestPlayergetStatisticsEmpyt)
		{
			Player byk = Player("byczeq");

			std::string st = "No statistics to show\n";
			Assert::AreEqual(byk.getStatistisc(), st);
		}


	};
}
