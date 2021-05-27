#pragma once
#include <sstream>
#include "Player.h"
#include "Board.h"
#include "Dictionary.h"
#include "Crossword.h"


class Game {
private:
	Player player;
	Crossword crossword;
	std::stringstream questionString;
public:
	Game(Player nPlayer, Crossword nCrossword);
	void play();
	void filling();
	void ending();
	void checkForPoints(int row, int col);
	void countPoints();
	std::string numberOfQuestion();
};