#include "Board.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <vector>


Board::Board(const int no_row, const int no_col)
{
	// init every field with "#"
	for (int i = 0; i < no_row; i++)
	{
		vector <Field> row;
		for (int j = 0; j < no_col; j++)
		{
			Field f = Field();
			row.push_back(f);
		}
		fields.push_back(row);
	}
}


void Board::addRow() {
	std::vector <Field> new_row;
	for (int i = 0; i < getNOColumns(); i++) {
		Field f = Field();
		new_row.push_back(f);
	}
	fields.push_back(new_row);
}


void Board::addColumn() {
	for (auto & row : fields) {
		Field f = Field();
		row.push_back(f);
	}
}


bool Board::isMutable(const int row, const int col) const {
	// checks range and if it is not '#'
	return col >= 0 && col < getNOColumns() && row >= 0 && row < getNORows() && fields.at(row).at(col).getValue() != '#';
}


int Board::getNOColumns() const
{
	return fields.at(0).size();
}


int Board::getNORows() const
{
	return fields.size();
}


const char Board::getValue(const int row, const int col) const
{
	coordsValidation(row, col);
	return fields.at(row).at(col).getValue();
}


void Board::setUpField(const int row, const int col) {
	coordsValidation(row, col);
	fields.at(row).at(col).setUp();
}


bool Board::coordsValidation(const int row, const int col) const {
	if (!validCoords(row, col))
	{
		throw std::out_of_range("Index out of range");
	}
	return true;
}


bool Board::validCoords(const int row, const int col) const {
	return col >= 0 && col < getNOColumns()&& row >= 0 && row < getNORows();
}


void Board::fillField(const int row, const int col, const char value)
{
	if (!isMutable(row, col))
	{
		throw std::invalid_argument("Index out of range");
	}
	fields.at(row).at(col).fill(value);
}


void Board::fillField(const int row, const int col, const std::string value) {
	fields.at(row).at(col).fill(value);
}


void Board::putIndex(const int row, const int col, const int value) {
	fields.at(row).at(col).putIndex(value);
}


void Board::putIndex(const int row, const int col, const std::string value) {
	fields.at(row).at(col).putIndex(value);
}


void Board::putIndex(const int row, const int col, const char value) {
	fields.at(row).at(col).putIndex(value);
}


void Board::clear() {
	for (auto& row : fields) {
		for (auto& field : row) {
			field.clear();
		}
	}
}


std::ostream& operator<<(std::ostream& os, const Board& b)
{
	// example: | v | a | l | u | e |
	//			| _ | _ | _ | # | # |
	for (auto row : b.fields) {
		os << "|";
		for (auto field : row) {
			os << " " << field.getValue() << " |";
		}
		os << std::endl;
	}
	return os;
}


bool operator==(const Board& b1, const Board& b2)
{
	// assert Board's size is the same
	if (b1.getNORows() != b2.getNORows() || b1.getNOColumns() != b2.getNOColumns()) {
		return false;
	}
	for (unsigned i = 0; i < b1.getNORows(); i++)
	{
		for (unsigned j = 0; j < b1.getNOColumns(); j++)
		{	
			// assert every pair of matching fields have equal values
			if (b1.fields.at(i).at(j).getValue() != b2.fields.at(i).at(j).getValue()) {
				return false;
			}
		}
	}
	return true;
}
