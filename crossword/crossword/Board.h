#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "Field.h"

class Board
{
private:
	int NOColumns = 0;
	int NORows = 0;
	std::vector<std::vector<Field>> fields;
	vector<vector<int>> firstLetters;
	Dictionary solutions;
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	// friend std::istream& operator>>(std::istream& is, Board& b);
	friend bool operator==(const Board& b1, const Board& b2);


public:
	Board() {};
	Board(const int no_row, const int no_col);
	Board(int size, std::string filepath);

	void addRow();
	void addColumn();
	const int getNORows();
	const int getNOColumns();
	void fillField(const int row,const int col,const char value);
	const char getValue(const int row, const int col) const;
	void clear();
	void fillAnswer(int noQue, std::string answer);
	std::vector<std::string> getQuestions();
	bool validCoords(const int row, const int col) const;
	void putFirstLetters();
	bool isCorrect(const int row, const int col) { return fields[row][col].isCorrect(); };
	int getPoints();

	void putQuestionOnBoard(int start_row, int start_col, std::string orientation, std::string answer, int NOQuestion);
};


extern bool isNumber(std::string s);
extern int number(std::string s);
extern char const intToChar(int num);
