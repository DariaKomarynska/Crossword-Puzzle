#include "Board.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <vector>


Board::Board(const int no_row, const int no_col)
{
	NOColumns = no_col;
	NORows = no_row;
	for (int i = 0; i < NORows; i++)
	{
		vector <Field> row;
		for (int j = 0; j < NOColumns; j++)
		{
			// fill every field with "#"
			Field f = Field();
			row.push_back(f);
		}
		fields.push_back(row);
	}
}


void Board::addRow() {
	NORows++;
	std::vector <Field> new_row;
	for (int i = 0; i < NOColumns; i++) {
		Field f = Field();
		new_row.push_back(f);
	}
	fields.push_back(new_row);
}


bool Board::validCoords(const int row, const int col) const {
	return col >= 0 && col < NOColumns && row >= 0 && row < NORows;
}


void Board::addColumn() {
	NOColumns++;
	for (int i = 0; i < NORows; i++) {
		Field f = Field();
		fields[i].push_back(f);
	}
}


const int Board::getNOColumns()
{
	return NOColumns;
}


const int Board::getNORows()
{
	return NORows;
}


const char Board::getValue(const int row, const int col) const
{
	if (!validCoords(row, col))
	{
		throw std::out_of_range("Index out of range");
	}
	return fields[row][col].value;
}


void Board::fillField(const int row, const int col, const char value)
{
	if (!validCoords(row, col) || fields[row][col].isExpected('#'))
	{
		throw "Index out of range";
	}
	fields[row][col].value = value;
}


void Board::clear() {
	for (int i = 0; i < NORows; i++)
	{
		for (int j = 0; j < NOColumns; j++)
		{
			fields[i][j].clear();
		}
	}
	putFirstLetters();
}


Board::Board(int NOQuest, std::string filepath) {
	/* NOQuest - amount of questions/answers
	* rows counted from 1
	* CSV file:
	* Question1,answer1,start_row1,start_column1,vertically/horizontally
	* Question2,answer2,start_row2,start_column2,vertically/horizontally
	*/
	std::vector<std::vector<Field>> new_fields;
	map<std::string, std::string> map_dict;

	int count = 0;

	std::string crossword_line;

	std::ifstream file(filepath);


	int noRows = 0;
	int noColumns = 0;

	while (getline(file, crossword_line), count< NOQuest) {

		std::string part;
		std::vector<std::string> data;
		stringstream s(crossword_line);
		while (getline(s, part, ',')) {
			data.push_back(part);
		}
		if (data.size() != 5) {
			throw std::invalid_argument("Invalid data in file!");
			break;
		}
		std::string question = data.at(0);
		std::string answer = data.at(1);
		int start_row = number(data.at(2)) - 1;
		int start_col = number(data.at(3)) - 1;
		std::string orientation = data.at(4);

		putQuestionOnBoard(start_row, start_col, orientation, answer, count);

		map_dict[answer] == question;
		
		count++;
	}
	
	file.close();

	solutions = Dictionary(map_dict);
}


void Board::putFirstLetters() {
	int count = 1;
	for (auto pair : firstLetters) {
		int row = pair[0];
		int col = pair[1];
		fields[row][col].fill(count);
		count++;
	}
}


void Board::putQuestionOnBoard(int start_row, int start_col, std::string orientation, std::string answer, int NOQuestion) {
	// adds new question and soultion
	// post initialization of fields for reading board from file purpose

	vector<int> vec;
	vec.push_back(start_row);
	vec.push_back(start_col);
	firstLetters.push_back(vec);

	if (orientation == "vertically") {
		int last_row = start_row + answer.length() - 1;

		while (NORows < last_row + 1) {
			addRow();
		}

		fields.at(start_row).at(start_col).postInit(NOQuestion, answer[0]);

		fields[start_row][start_col].fill(intToChar(NOQuestion));	// field with index

		for (int i = start_row + 1; i <= last_row; i++) {
			char letter = answer.at(i);
			if (!fields[i][start_col].isExpected('#') && !fields[i][start_col].isExpected(letter)) {
				throw std::invalid_argument("Invalid data");
			}

			fields[i][start_col].postInit(NOQuestion, letter);
		}
	}
	else if (orientation == "horizontally") {
		int last_col = start_col + answer.length() - 1;

		while (NOColumns < last_col + 1) {
			addColumn();
		}

		fields[start_row][start_col].postInit(NOQuestion, answer.at(0));

		fields[start_row][start_col].fill(intToChar(NOQuestion));	// field with index

		for (int i = start_col + 1; i <= last_col; i++) {
			char letter = answer.at(i);
			if (!fields[start_row][i].isExpected('#') && !fields[start_row][i].isExpected(letter)) {
				throw std::invalid_argument("Invalid data");
			}

			fields[start_row][i].postInit(NOQuestion, letter);
		}
	}
	else { throw std::invalid_argument("Invalid data"); }
}


std::vector<std::string> Board::getQuestions() {
	std::vector<std::string> ques = solutions.questions();
	return ques;
}


void Board::fillAnswer(int noQue, std::string answer) {
	int letterCount = 0;
	for (int i = 0; i < NORows && letterCount < answer.length(); i++) {
		for (int j = 0; j < NOColumns && letterCount < answer.length(); j++) {
			if (fields[i][j].NOQuestion == noQue) {
				fields[i][j].fill(answer[letterCount]);
				letterCount++;
			}
		}
	}
}

int Board::countPoints() {
	int points = 0;
	for (int i = 0; i < NORows; i++) {
		for (int j = 0; j < NOColumns; j++) {
			if (fields[i][j].value != '#' && fields[i][j].isCorrect()) points++;
		}
	}
	return points;
}


std::ostream& operator<<(std::ostream& os, const Board& b)
{
	// example: | v | a | l | u | e |
	//			| _ | _ | _ | # | # |
	Board test(b.NOColumns, b.NORows);
	if (test == b)
	{
		os << "Empty Board";
		return os;
	}
	for (int i = 0; i < b.NORows; i++)
	{
		os << "|";
		for (int j = 0; j < b.NOColumns; j++)
		{
			os << " " << b.getValue(i, j)  << " |";
		}
		os << std::endl;
	}
	os << b.solutions;
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
				b_new.fields[row][col].value = value;
				endl = 1;
				col += 1;
				value = 0;
			}
		}
	}
	// fills last field
	if (value != 0 || endl)
	{
		b_new.fields[row][col].value = value;
		b_new.NOColumns = row + 1;
	}
	b_new.NORows = max_col;
	b = b_new;
	return is;
}

Board operator+(const Board& b1, const Board& b2)
{
	if (b1.NOColumns + b2.NORows >= 20)
	{
		throw std::out_of_range("Boards are too big");
	}

	Board out = b1;	// set output as first Board
	out.NOColumns = b1.NOColumns + b2.NOColumns;
	int col = std::max(b1.NORows, b2.NORows);
	
	// fill rest of an output with second Board
	for (int i = 0; i < b2.NOColumns; i++)
	{
		for (int j = 0; j < col; j++)
		{
			char val = b2.fields[i][j].value;
			out.fillField(i + b1.NOColumns, j, val);
		}
	}
	return out;
}

Board& operator++(Board& b)
{
	if (b.NOColumns >= 20)
	{
		throw "Board is at maximal size";
	}
	// add a new row with empty fields
	b.NOColumns = b.NOColumns + 1;
	for (int i = 0; i < b.NORows; i++)
	{
		b.fillField(b.NOColumns - 1, i, 32);
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
	if (b.NOColumns <= 1)
	{
		throw "Board is at minimal size";
	}
	// reset values of last row
	for (int i = 0; i < b.NORows; i++)
	{
		b.fillField(b.NOColumns - 1, i, 32);
	}
	b.NOColumns = b.NOColumns - 1;
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
	// assert Board's size is the same
	if (b1.NORows != b2.NORows || b1.NOColumns != b2.NOColumns) {
		return false;
	}
	for (int i = 0; i < NORows; i++)
	{
		for (int j = 0; j < NOColumns; j++)
		{	
			// assert every pair of matching fields have equal values
			if (b1.fields[i][j].value != b2.fields[i][j].value) {
				return false;
			}
		}
	}
	return true;
}


extern bool isNumber(std::string s) {
	for (char let : s) {
		if (!isdigit(let)) return false;
	}
	return true;
}


extern int number(std::string s) {
	if (isNumber(s)) {
		return std::stoi(s);
	}
	else {
		throw std::invalid_argument("Not numeric");
	}
}


extern char const intToChar(int num) {
	std::string s = std::to_string(num);
	char const* pchar = s.c_str();
	return *pchar;
}
