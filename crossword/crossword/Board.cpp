#include "Board.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>

Board::Board(const int r_len, const int c_len)
{
	columnLen = c_len;
	rowLen = r_len;
	for (int i = 0; i < columnLen; i++)
	{
		for (int j = 0; j < rowLen; j++)
		{
			// fill every field with "#"
			fields[i][j] = Field();
		}
	}
}


const int Board::getColLen()
{
	return columnLen;
}


const int Board::getRowLen()
{
	return rowLen;
}


char Board::getValue(const int row, const int col) const
{
	if (0 > col || col >= columnLen || 0 > row || row >= rowLen)
	{
		throw std::out_of_range("Index out of range");
	}
	return fields[row][col].value;
}

void Board::fillField(const int row, const int col, const char value)
{
	if (0 > col || col >= columnLen || 0 > row || row >= rowLen)
	{
		throw "Index out of range";
	}
	if (value == 0)
	{
		fields[row][col] = '_';
	}
}

void Board::clear() {
	for (int i = 0; i < rowLen; i++)
	{
		for (int j = 0; j < columnLen; j++)
		{
			if (fields[i][j].value != '#') {
				fields[i][j].value = '_';
			}
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Board& b)
{
	// example: | v | a | l | u | e |
	//			| _ | _ | _ | # | # |
	Board test(b.rowLen, b.columnLen);
	if (test == b)
	{
		os << "Empty Board";
		return os;
	}
	for (int i = 0; i < b.rowLen; i++)
	{
		os << "|";
		for (int j = 0; j < b.columnLen; j++)
		{
			os << " " << b.getValue(i, j)  << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Board& b)
{
	// creates new Board that replaces Board b
	// expected input ex.: a|b||c|d
	// a, b, c, d represent values of fields
	// | represent start of a new field
	// || represent start of a new row of fields
	Board b_new(1, 1);
	bool endl = 0;	// tells if line has ended	
	int col = 0;
	int row = 0;
	int max_col = 0;	// new column_len
	char value = 0;	// value to fill field with
	std::string input;
	is >> input;
	for (char elem : input)
	{
		// takes a value to fill field
		if (elem != char(124))
		{
			value = elem;
			endl = 0;
		}
		// starts new field or new row of fields
		else
		{	
			// starts new row
			if (endl || col >= 20)
			{
				max_col = std::max(col, max_col);
				endl = 0;
				col = 0;
				row += 1;
				value = 0;
			}
			// starts new field
			else
			{
				b_new.fields[row][col] = value;
				endl = 1;
				col += 1;
				value = 0;
			}
		}
	}
	// fills last field
	if (value != 0 || endl)
	{
		b_new.fields[row][col] = value;
		b_new.rowLen = row + 1;
	}
	b_new.columnLen = max_col;
	b = b_new;
	return is;
}

Board operator+(const Board& b1, const Board& b2)
{
	if (b1.rowLen + b2.rowLen >= 20)
	{
		throw std::out_of_range("Boards are too big");
	}

	Board out = b1;	// set output as first Board
	out.rowLen = b1.rowLen + b2.rowLen;
	int col = std::max(b1.columnLen, b2.columnLen);
	
	// fill rest of an output with second Board
	for (int i = 0; i < b2.rowLen; i++)
	{
		for (int j = 0; j < col; j++)
		{
			char val = b2.fields[i][j].value;
			out.fillField(i + b1.rowLen, j, val);
		}
	}
	return out;
}

Board& operator++(Board& b)
{
	if (b.rowLen >= 20)
	{
		throw "Board is at maximal size";
	}
	// add a new row with empty fields
	b.rowLen = b.rowLen + 1;
	for (int i = 0; i < b.columnLen; i++)
	{
		b.fillField(b.rowLen - 1, i, 32);
	}
	return b;
}


Board& operator++(Board& b, int)
{
	Board temp = b;
	++b;
	return temp;
}

Board& operator--(Board& b)
{
	if (b.rowLen <= 1)
	{
		throw "Board is at minimal size";
	}
	// reset values of last row
	for (int i = 0; i < b.columnLen; i++)
	{
		b.fillField(b.rowLen - 1, i, 32);
	}
	b.rowLen = b.rowLen - 1;
	return b;
}

Board& operator--(Board& b, int)
{
	Board temp = b;
	--b;
	return temp;
}

bool operator==(const Board& b1, const Board& b2)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{	
			// assert every pair of matching fields have equal values
			if (b1.fields[i][j].value != b2.fields[i][j].value)
			{
				return 0;
			}
		}
	}
	// assert Board's size is the same
	return (b1.columnLen == b2.columnLen && b1.rowLen == b2.rowLen);
}

