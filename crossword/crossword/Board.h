#pragma once
#include <string>
#include <iostream>
#include "Field.h"
#include <vector>
#include "Dictionary.h"

class Board
{
private:
	int NOColumns = 0;
	int NORows = 0;
	std::vector<std::vector<Field>> fields;
	vector<vector<int>> firstLetters;
	Dictionary solutions;
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	friend std::istream& operator>>(std::istream& is, Board& b);
	friend Board operator+(const Board& b1, const Board& b2);
	friend Board& operator++(Board&);
	friend Board& operator++(Board& , int);
	friend Board& operator--(Board&);
	friend Board& operator--(Board&, int);
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
	int countPoints();

	void setFields(int start_row, int start_col, std::string orientation, std::string answer, int NOQuestion);
};


extern bool isNumber(std::string s);
extern int number(std::string s);
extern char const intToChar(int num);
