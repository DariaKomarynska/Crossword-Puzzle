#pragma once
#include "Board.h"
#include "Dictionary.h"
#include <iostream>
#include <vector>


class Crossword {
private:
	Board board = Board();
	Dictionary solutions = Dictionary();
	std::vector< std::vector<int>> firstLettersCoords;
	std::vector<std::string> orientations;

public:
	Crossword() {};
	Crossword(std::string filePath);
	Crossword(const Dictionary sol, const std::vector< std::vector<int>> fLett, const std::vector<std::string> orient);

	void fillAnswer(const int NOQuestion, const std::string answer);
	std::vector<int> getFirstLetterCoords(const int NOQuestion);
	std::string getOrientation(const int NOQuestion);
	int countPoints();
};