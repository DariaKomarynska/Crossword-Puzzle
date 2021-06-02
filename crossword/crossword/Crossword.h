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

	void fillCrossword(const int beginRow, const int beginCol, const string answer, const string orientation);
	void fillAnswer(const int NOQuestion, const std::string answer);
	void fillField(const int row, const int col, const char value);
	
	int countPoints();
	friend std::ostream& operator<<(std::ostream& os, Crossword& c);
	std::vector<std::string> getQuestions();

	std::vector<int> getFirstLetterCoords(const int NOQuestion);
	std::string getOrientation(const int NOQuestion);
	Board getBoard() { return board; };
	int getIndexAnswer(const string word);
	
	int getLetterRow(const string word);
	int getLetterRow(const string word, const char letter);
	int getLetterCol(const string word, const char letter);
	int getLetterCol(const string word);
	int getFirstLetterRow(const int NOQuestion);
	int getFirstLetterCol(const int NOQuestion);
	
	int letterPosition(const string word, const char letter);

	bool isCorrectAnswer(const int NOQuestion, const std::string answer);
	bool isNumberOfQuestion(const int NOQuestion);
	string correctAnswer(const int NOQuestion);
	string checkOrientation(const string word);

	void choosePositionPutAnswers();
	vector<int> putWordHorizontally(const string answer, const string preWord, const int curIndex, const int preIndex);
	vector<int> putWordVertically(const string answer, const string preWord, const int curIndex, const int preIndex);
	void putFirstWord(const string answer);
	void putAnotherWord(const string answer, const int answerSize, vector<string> onBoard);
	pair<vector<int>, string>choosePosition(const string curWord, const string prevWord, const int curIndex, const int prevIndex);
	bool isNotLastAnswer(const string answer);
};