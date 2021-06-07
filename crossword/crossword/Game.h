#pragma once
#include <sstream>
#include "Player.h"
#include "Board.h"
#include "Dictionary.h"
#include "Crossword.h"
#include "crosswordErrors.cpp"


class Game {
private:
public:
	Game(Player &nPlayer, Crossword &nCrossword) : player(nPlayer), crossword(nCrossword) {}
	Player &player;
	Crossword &crossword;
	void play();
	void filling();
	void ending();
	void checkForPoints(int row, int col);
	void countPoints();
	void showCorrectBoard();
	std::string numberOfQuestion();
};


extern std::vector <Player> getPlayers();
extern bool cmpPairs(const std::pair<std::string, int>& l, const std::pair<std::string, int>& r);
extern Player getPlayerByName(const std::string name);
extern void saveUserData(std::vector <Player> player);
