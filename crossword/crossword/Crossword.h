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
	Crossword(const Dictionary n_solutions);

	void fillCrossword();
	void fillAnswer(const int NOQuestion, const std::string answer);
	void fillField(const int row, const int col, const char value);
	std::vector<int> getFirstLetterCoords(const int NOQuestion);
	std::string getOrientation(const int NOQuestion);
	int countPoints();
	friend std::ostream& operator<<(std::ostream& os, Crossword& c);
	std::vector<std::string> getQuestions();
	int getFirstLetterX(const int NOQuestion);
	int getFirstLetterY(const int NOQuestion);
	Board getBoard() { return board; };
	bool isCorrectAnswer(const int NOQuestion, const std::string answer);
	bool isNumberOfQuestion(const int NOQuestion);
	string correctAnswer(const int NOQuestion);
	int getLetterX(const string word, const char letter);
	int getLetterY(const string word, const char letter);
	int getIndexAnswer(const string word);
	int findPosition(const string word, const char letter);
};