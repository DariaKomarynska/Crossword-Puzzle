#pragma once
#include "Player.h"
#include "Board.h"
#include "Dictionary.h"


class Game {
private:
	Player player;
	Board board;
public:
	Game(Player nPlayer, Board nBoard);
	void play();
	void filling();
	void ending();
	void checkForPoints(int row, int col);
	void countPoints();
};