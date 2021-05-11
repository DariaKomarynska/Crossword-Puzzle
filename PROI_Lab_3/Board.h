#pragma once
#include <string>
#include <iostream>

class Board
{
private:
	int column_len;
	int row_len;
	char fields[20][20];	// every fiels is represented by a single char
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
	int get_row_len();
	int get_col_len();
	void fill_field(int row, int col, char value);
	char get_field(int row, int col);
};
