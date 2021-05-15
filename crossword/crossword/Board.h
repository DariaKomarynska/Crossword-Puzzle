#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Dictionary.h"
#include "Field.h"

class Board
{
private:
	std::vector<std::vector<Field>> fields;
	vector<vector<int>> firstLetters;
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	friend std::istream& operator>>(std::istream& is, Board& b);
	friend bool operator==(const Board& b1, const Board& b2);

public:
	Board() {};
	Board(const int no_row, const int no_col);

	void addRow();
	void addColumn();
	int getNORows() const;
	int getNOColumns() const;
	void fillField(const int row, const int col, const char value);
	void fillField(const int row, const int col, const std::string value);
	void putIndex(const int row, const int col, const int value);
	void putIndex(const int row, const int col, const std::string value);
	void putIndex(const int row, const int col, const char value);
	const char getValue(const int row, const int col) const;
	void setUpField(const int row, const int col);
	void clear();
	bool validCoords(const int row, const int col) const;
	bool coordsValidation(const int row, const int col) const;
	bool isMutable(const int row, const int col) const;
	void setUpMaxSize(const unsigned NORows, const unsigned NOCol);
};
