#pragma once
#include "Board.h"
#include "Dictionary.h"
#include "crosswordErrors.cpp"
#include <iostream>
#include <random>
#include <vector>
#include <sstream>
#include <fstream>


class Crossword {
private:
	Dictionary solutions = Dictionary();
	std::vector<std::string> answerList;
	std::vector< std::vector<int>> firstLettersCoords;
	std::vector<std::string> orientations;
	std::string name = "";

public:
	Board board = Board();
	std::vector <int> guessed;

	Crossword() {};
	Crossword(std::string filePath, std::string crosswordName="", bool is_list_of_words=false);
	Crossword(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations);
	Crossword(const Dictionary n_solutions);

	void init(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector < std::string > n_orientations);
	void init(const Dictionary n_solutions);
	void setName(const std::string newName) { name = newName; };

	void fillCrossword(const int beginRow, const int beginCol, const string answer, const string orientation);
	void fillAnswer(const int NOQuestion, const std::string answer);
	void fillField(const int row, const int col, const char value);
	void getCorrectBoard();
	std::string getName() { return name; }
	bool notGuessed(int index);

	string answerOnBoard(const int NOQuestion);
	int countPoints();
	int maxPoints();
	friend std::ostream& operator<<(std::ostream& os, Crossword& c);
	std::vector<std::string> getQuestions();
	int getNOQuestions() { return solutions.size(); }
	std::vector <std::vector<int>> getAllFirstLetterCoords() { return firstLettersCoords; }
	std::vector <std::vector<int>> getFieldsOfQuestion(const int index);
	void makeCSVFile();

	std::vector<int> getFirstLetterCoords(const int NOQuestion);
	std::string getOrientation(const int NOQuestion);
	Board getBoard() { return board; };
	int getIndexAnswer(const string word);
	int getIndexAnswerList(const string word);
	std::vector<std::string> getRandomQuestions();
	vector <string> getRandomAnswers();
	int sizeListAnswers();
	int getLetterRow(const string word);
	int getLetterRow(const string word, const char letter);
	int getLetterCol(const string word, const char letter);
	int getLetterCol(const string word);
	int getFirstLetterRow(const int NOQuestion);
	int getFirstLetterCol(const int NOQuestion);
	int sizeWord(const int NOQuestion);

	int letterPosition(const string word, const char letter);

	bool isCorrectAnswer(const int NOQuestion, const std::string answer);
	bool isNumberOfQuestion(const int NOQuestion);
	string correctAnswer(const int NOQuestion);
	string checkOrientation(const string word);
	bool isNotLastAnswer(const string answer);
	bool isCorrectAnswer(const int question_index);

	void notFoundCommonLetter(const string answer, const string preWord);
	bool foundCommonLetter(const string answer, const string preWord, const int ansIndex, const int prevIndex);
	void choosePositionPutAnswers();
	pair<vector<int>, string>choosePosition(const string curWord, const string prevWord, const int curIndex, const int prevIndex);
	pair<vector<int>, string>chooseRandomPosition(const string curWord, const string preWord);
	void putFirstWord(const string answer);
	void putAnotherWord(const string answer, const int answerSize, const vector<string> onBoard);
	vector<int> putWordRandomly(const string curWord);
	vector<int> putWordHorizontally(const string answer, const string preWord, const int curIndex, const int preIndex);
	vector<int> putWordVertically(const string answer, const string preWord, const int curIndex, const int preIndex);

	bool isBadPosition(vector<int> coordinates, const std::string answer, const std::string orientation);
	bool isCorrectField(const int row, const int col, const char letter);
	bool isSameLetter(const int row, const int col, const char letter);
	bool AreSameLetters(const char letter1, const char letter2);
	char checkLetter(const int index, const int nextRow, const int nextCol);
	char getLetterByColumn(const int NOQuestion, const int col);
	char getLetterByRow(const int NOQuestion, const int row);
	bool checkCoordinate(const int index, const int row, const int col);
	bool isInRange(const int index, const int begin, const int coord);
	bool notContinueAnswer(const int row, const int col, const string lastOrientation, const char letter);
	//std::vector< std::vector<int>> getDoubleCoords();
};

extern std::vector <std::string> parseRows(std::ifstream& fileHandle);
extern std::vector <std::string> parseCSV(std::string& data);
extern std::vector <Crossword> getCrosswords();
//bool isInVector(std::vector< std::vector<int>> v, std::vector<int> ob);
//bool twoTimesInVector(std::vector< std::vector<int>> v, const int index);
