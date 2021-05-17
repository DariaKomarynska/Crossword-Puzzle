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
	Crossword(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations);

	void fillAnswer(const int NOQuestion, const std::string answer);
	std::vector<int> getFirstLetterCoords(const int NOQuestion);
	std::string getOrientation(const int NOQuestion);
	int countPoints();
};