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
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	friend std::istream& operator>>(std::istream& is, Board& b);
	friend bool operator==(const Board& b1, const Board& b2);

public:
	Board();
	Board(const int no_row, const int no_col);

	void addRow();
	void addColumn();
	int getNORows() const;
	int getNOColumns() const;
	void fillField(const int row, const int col, const char value);
	void fillField(const int row, const int col, const std::string value);
	void fillFields(const int begin_row, const int begin_col, const std::string answer, const std::string orientation);
	void putIndex(const int row, const int col, const int value);
	void putIndex(const int row, const int col, const std::string value);
	void putIndex(const int row, const int col, const char value);
	const char getValue(const int row, const int col) const;
	void setUpField(const int row, const int col);
	void createAndSetUpFields(const int begin_row, const int begin_col, const int size, const std::string orientation);
	void setUpFields(const int begin_row, const int begin_col, const int size, const std::string orientation);
	void clear();
	bool validCoords(const int row, const int col) const;
	bool coordsValidation(const int row, const int col) const;
	void setUpMaxSize(const int NORows, const int NOCol);
	bool isBadPosition(vector<int> coordinates, const std::string answer, const std::string orientation);
};

extern int getLenOfNumber(const int number);
extern std::string getSpaces(const int index);