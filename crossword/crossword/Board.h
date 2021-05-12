#pragma once
#include <string>
#include <iostream>
#include "Field.h"
#include <vector>
#include "Dictionary.h"

class Board
{
private:
	int columnLen = 0;
	int rowLen = 0;
	std::vector<std::vector<Field>> fields;
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
	Board(const int row_len, const int col_len);
	const int getRowLen();
	const int getColLen();
	void fillField(const int row,const int col,const char value);
	char getValue(const int row, const int col) const;
	void clear();
};
