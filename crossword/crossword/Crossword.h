#pragma once
#include "Board.h"
#include "Dictionary.h"


class Crossword {
private:
	Board board;
	Dictionary solutions;

public:
	Crossword();
	Crossword(std::string filePath);
	Crossword(const Board b, const Dictionary sol) : board(b), solutions(sol) {};
};