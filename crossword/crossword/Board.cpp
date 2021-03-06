#include "Board.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <vector>
#include "crosswordErrors.cpp"


Board::Board() {
	std::vector < std::vector<Field> > v;
	fields = v;
}


Board::Board(const int no_row, const int no_col)
{
	// 1. create empty vector
	// 2. put direct amount of '#' fields there
	std::vector < std::vector<Field> > v;
	fields = v;
	setUpMaxSize(no_row, no_col);
}

// Add an empty row.
void Board::addRow() {
	std::vector <Field> new_row;
	for (int i = 0; i < getNOColumns(); i++) {
		Field f = Field();
		new_row.push_back(f);
	}
	fields.push_back(new_row);
}

// Add an empty column.
void Board::addColumn() {
	for (auto& row : fields) {
		Field f = Field();
		row.push_back(f);
	}
}

// Return number of columns.
int Board::getNOColumns() const
{
	if (getNORows() == 0) {
		return 0;
	}
	return fields.at(0).size();
}

// Return number of rows.
int Board::getNORows() const
{
	return fields.size();
}

// Return value of a field with given coords.
char Board::getValue(const int row, const int col) const
{
	coordsValidation(row, col);
	return fields.at(row).at(col).getValue();
}

// Set field to be empty, editable field.
void Board::setUpField(const int row, const int col) {
	coordsValidation(row, col);
	fields.at(row).at(col).setUp();
}


void Board::createAndSetUpFields(const int begin_row, const int begin_col, const int size, const std::string orientation) {
	int end_row = begin_row;
	int end_col = begin_col;
	if (orientation == "vertically") {
		end_row += size - 1;
	}
	else if (orientation == "horizontally") {
		end_col += size - 1;
	}
	setUpMaxSize(end_row + 1, end_col + 1);
	setUpFields(begin_row, begin_col, size, orientation);
}


// Set fields to be empty, editable fields.
// Starting at given coords, [size] number of fields, moving right or down.
void Board::setUpFields(const int begin_row, const int begin_col, const int size, const std::string orientation) {
	int dx = 0;
	int dy = 0;

	int x = begin_col;
	int y = begin_row;

	if (orientation == "vertically") {
		dy = 1;
	}
	else if (orientation == "horizontally") {
		dx = 1;
	}
	else {
		throw InvalidOrientation();
	}

	for (int i = 0; i < size; i++) {
		try {
			coordsValidation(y, x);
			setUpField(y, x);
		}
		// if there are errors, program uses only correct values
		catch (const std::out_of_range&) {
			break;		// if index is out of range looop breaks
		}

		x += dx;
		y += dy;
	}
}

// Verify that coords are in range.
bool Board::coordsValidation(const int row, const int col) const {
	if (!validCoords(row, col))
	{
		throw std::out_of_range("Index out of range");
	}
	return true;
}

// Verify that coords are in range.
bool Board::validCoords(const int row, const int col) const {
	return col >= 0 && col < getNOColumns() && row >= 0 && row < getNORows();
}

// Fill specified field with given value.
void Board::fillField(const int row, const int col, const char value)
{
	coordsValidation(row, col);
	fields.at(row).at(col).fill(value);
}

// Fill specified field with given value.
void Board::fillField(const int row, const int col, const std::string value) {

	coordsValidation(row, col);
	fields.at(row).at(col).fill(value);
}

// Fill specified fields with given value.
// Starting at given coords, [size] number of fields, moving right or down.
void Board::fillFields(const int begin_row, const int begin_col, const std::string answer, const std::string orientation) {
	int dx = 0;
	int dy = 0;

	int x = begin_col;
	int y = begin_row;

	if (orientation == "vertically") {
		dy = 1;
	}
	else if (orientation == "horizontally") {
		dx = 1;
	}
	else {
		throw InvalidOrientation();
	}

	for (unsigned i = 0; i < answer.size(); i++) {
		try {
			coordsValidation(y, x);
			fillField(y, x, answer.at(i));
		}
		catch (const FieldNotSettedUp&) {
			x += dx;
			y += dy;
			continue;
		}
		catch (const NotAlphaOrSpace&) {
			x += dx;
			y += dy;
			continue;
		}
		catch (const std::out_of_range&) {
			break;
		}
		x += dx;
		y += dy;
	}
}

// Fill specified field with given value.
void Board::putIndex(const int row, const int col, const int value) {
	fields.at(row).at(col).putIndex(value);
}

// Fill specified field with given value.
void Board::putIndex(const int row, const int col, const std::string value) {
	fields.at(row).at(col).putIndex(value);
}

// Fill specified field with given value.
void Board::putIndex(const int row, const int col, const char value) {
	fields.at(row).at(col).putIndex(value);
}

// Clear all fields.
void Board::clear() {
	for (auto& row : fields) {
		for (auto& field : row) {
			field.clear();
		}
	}
}

//  Enlarge board.
void Board::setUpMaxSize(const int NORows, const int NOCol) {

	if (NORows <= 0 || NOCol <= 0) {
		return;
	}
	int diff = NORows - getNORows();
	if (diff > 0) {
		for (int i = 0; i < diff; i++) {
			addRow();
		}
	}

	diff = NOCol - getNOColumns();
	if (diff > 0) {
		for (int i = 0; i < diff; i++) {
			addColumn();
		}
	}
}


std::ostream& operator<<(std::ostream& os, const Board& b)
{
	// example: 
	//	   1   2   3   4   5	
	// 1 | v | a | l | u | e |
	// 2 | _ | _ | _ | # | # |
	if (b.getNOColumns() == 0 || b.getNORows() == 0) return os;
	os << "  ";

	int maxColIdLen = getLenOfNumber(b.getNOColumns());
	int maxRowIdLen = getLenOfNumber(b.getNORows());
	for (int i = 0; i < b.getNOColumns(); i++) {
		int index = i + 1;
		os << "   " << index;
		if (getLenOfNumber(index) < maxColIdLen) {
			os << getSpaces(maxColIdLen - getLenOfNumber(index));
		}
	}
	os << std::endl;
	int index = 1;
	for (auto row : b.fields) {
		os << ' ' << index << ' ';
		if (getLenOfNumber(index) < maxRowIdLen) {
			os << getSpaces(maxRowIdLen - getLenOfNumber(index));
		}
		os << "|";
		index++;
		int colid = 1;
		for (auto field : row) {
			os << " " << field.getValue();
			os << getSpaces(maxColIdLen - getLenOfNumber(colid));
			os << "|";
			colid++;
		}
		os << std::endl;
	}
	return os;
}


int getLenOfNumber(const int number) {
	std::string smindex = std::to_string(number);
	return smindex.length();
}

//  Return string of spaces that has the same length as a given number.
std::string getSpaces(const int index) {
	int NOSpaces = getLenOfNumber(index);
	std::string spaces = "";
	for (int i = 0; i < NOSpaces; i++) {
		spaces.append(" ");
	}
	return spaces;
}

// Create vector of characters, exclude ' ' and '|'.
std::vector <char> separateRow(std::string rowData) {
	std::vector<char> rowSep;
	for (char elem : rowData) {
		if (elem != '|' && elem != ' ') {
			rowSep.push_back(elem);
		}
	}
	return rowSep;
}


std::istream& operator>>(std::istream& is, Board& b) {
	// creates new Board that replaces Board b
	// expected input ex.:"     1  2\n 1 | a | b |\n 2 | c | d |
	// a, b, c, d, # represent values of fields
	// | represents start of a new field
	// /n represents new row

    int NORows = 0;
	std::vector<std::vector<char>> values;
	std::vector<char> row;
	values.push_back(row);
	std::string rowData;
	while (getline(is, rowData, '\n')) {
		if (NORows == 0) {
			NORows++;
			continue;
		}

		int rowIndex = NORows - 1;
		std::vector <char> rowSep = separateRow(rowData);

		// making sure if first (0) character is a number (index) and if value is correct
		if (!isNumber(rowSep.at(0)) || number(rowSep.at(0)) != NORows) throw InvalidData();

		int temp = 0;

		for (auto& elem : rowSep) {
			if (temp > 0) {
				values.at(rowIndex).push_back(elem);
			}
			temp++;
		}

		NORows++;
		row = std::vector<char>();
		values.push_back(row);
	}

	NORows--;
	if (NORows == 0) {
		throw BoardSizeException();
	}
    int NOCols = values.at(0).size();

	b.setUpMaxSize(NORows, NOCols);

    for (int Nrow = 0; Nrow < NORows; Nrow++) {
        for (int Ncol = 0; Ncol < NOCols; Ncol++) {
			char v = values.at(Nrow).at(Ncol);
			if (v != '#') {
				b.setUpField(Nrow, Ncol);
				if (v != '_') b.fillField(Nrow, Ncol, v);
			}
		}
	}

	return is;
}


bool operator==(const Board& b1, const Board& b2)
{
	// assert Board's size is the same
	if (b1.getNORows() != b2.getNORows() || b1.getNOColumns() != b2.getNOColumns()) {
		return false;
	}
	for (int i = 0; i < b1.getNORows(); i++)
	{
		for (int j = 0; j < b1.getNOColumns(); j++)
		{
			// assert every pair of matching fields have equal values
			if (b1.fields.at(i).at(j).getValue() != b2.fields.at(i).at(j).getValue()) {
				return false;
			}
		}
	}
	return true;
}
