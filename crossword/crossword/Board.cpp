#include "Board.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>

Board::Board(const int r_len, const int c_len)
{
	column_len = c_len;
	row_len = r_len;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			// fill every field with " "
			fields[i][j] = 32;
		}
	}
}

int Board::get_col_len()
{
	return column_len;
}

int Board::get_row_len()
{
	return row_len;
}

char Board::get_field(int row, int col)
{
	if (0 > col || col >= column_len || 0 > row || row >= row_len)
	{
		throw std::out_of_range("Index out of range");
	}
	return fields[row][col];
}

void Board::fill_field(int row, int col, char value)
{
	if (0 > col || col >= column_len || 0 > row || row >= row_len)
	{
		throw "Index out of range";
	}
	if (value == 0)
	{
		value = 32;  // 32 == " "
	}
	fields[row][col] = value;
}

std::ostream& operator<<(std::ostream& os, const Board& b)
{
	Board test(b.row_len, b.column_len);
	if (test == b)
	{
		os << "Empty Board";
		return os;
	}
	for (int i = 0; i < b.row_len; i++)
	{
		for (int j = 0; j < b.column_len; j++)
		{
			if (b.fields[i][j] != 32)  // 32 == " "
			{
				os << " " << b.fields[i][j] << " |";
			}
			else
			{
				os << "    ";
			}
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
		b_new.row_len = row + 1;
	}
	b_new.column_len = max_col;
	b = b_new;
	return is;
}

Board operator+(const Board& b1, const Board& b2)
{
	if (b1.row_len + b2.row_len >= 20)
	{
		throw std::out_of_range("Boards are too big");
	}

	Board out = b1;	// set output as first Board
	out.row_len = b1.row_len + b2.row_len;
	int col = std::max(b1.column_len, b2.column_len);
	
	// fill rest of an output with second Board
	for (int i = 0; i < b2.row_len; i++)
	{
		for (int j = 0; j < col; j++)
		{
			char fl = b2.fields[i][j];
			out.fill_field(i + b1.row_len, j, fl);
		}
	}
	return out;
}

Board& operator++(Board& b)
{
	if (b.row_len >= 20)
	{
		throw "Board is at maximal size";
	}
	// add a new row with empty fields
	b.row_len = b.row_len + 1;
	for (int i = 0; i < b.column_len; i++)
	{
		b.fill_field(b.row_len - 1, i, 32);
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
	if (b.row_len <= 1)
	{
		throw "Board is at minimal size";
	}
	// reset values of last row
	for (int i = 0; i < b.column_len; i++)
	{
		b.fill_field(b.row_len - 1, i, 32);
	}
	b.row_len = b.row_len - 1;
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
			// assert every pair of matchong fields have equal values
			if (b1.fields[i][j] != b2.fields[i][j])
			{
				return 0;
			}
		}
	}
	// assert Board's size is the same
	return (b1.column_len == b2.column_len && b1.row_len == b2.row_len);
}

