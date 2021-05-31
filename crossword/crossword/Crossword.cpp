﻿#include "Crossword.h"

 
Crossword::Crossword(std::string filepath) {

}


Crossword::Crossword(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations) {
	unsigned size = n_solutions.size();
	if (size != first_letters.size() || size != n_orientations.size()) {
		throw std::invalid_argument("Invalid data size");
	}

	solutions = n_solutions;

	// check if first_letters coords is vector nx2
	for (auto& point : first_letters) {
		if (point.size() != 2) {
			throw std::invalid_argument("Invalid data size");
		}
	}

	firstLettersCoords = first_letters;

	// check if orientations are correct 
	for (auto& orient : n_orientations) {
		if (orient != "vertically" && orient != "horizontally") {
			throw std::invalid_argument("Invalid orientation");
		}
	}

	orientations = n_orientations;

	for (unsigned i = 0; i < size; i++) {
		std::string answer = solutions.find_word(i);
		unsigned a_size = answer.size();
		std::string orientation = orientations.at(i);
		std::vector<int> fst_letter_pos = firstLettersCoords.at(i);

		board.createAndSetUpFields(fst_letter_pos.at(0), fst_letter_pos.at(1), a_size, orientation);
	}
}


Crossword::Crossword(const Dictionary n_solutions) {
	solutions = n_solutions;
	choosePositionPutAnswers();
	//fillCrossword();
}


void Crossword::choosePositionPutAnswers() {
	vector <string> words = solutions.answers();
	std::vector<string> onBoard;
	unsigned amountOfWords = solutions.size();

	for (unsigned i = 0; i < amountOfWords; i++) {

		std::string answer = words[i];
		unsigned answerSize = answer.size();

		bool placed = false;

		if (i == 0) {
			// put first word on the board
			putFirstWord(answer);
			placed = true;
		}
		else {
			putAnotherWord(answer, answerSize, onBoard);
		}
		onBoard.push_back(answer);
	}
}


void Crossword::putFirstWord(const string answer) {
	std::vector <int> coordinates;
	string orientation = "horizontally";
	int x = 0, y = 0;
	int answerSize = answer.size();
	if (answerSize % 2 == 0) { x = 3; y = 3; }
	else { x = 4; y = 3; }
	// (x, y) = (4,4) or (5,4) on the board
	fillCrossword(y, x, answer, orientation);
}


void Crossword::putAnotherWord(const string answer, const int answerSize, vector<string> onBoard) {
	bool placed = false;
	pair<vector<int>, string> position;
	vector<int> coords;
	string orientation;
	for (int i = 0; i < onBoard.size(); i++) { // iterate vector of words which are already on board
		string preWord = onBoard[i];
		if (placed == false) {
			for (unsigned j = 0; j < answerSize; j++) { // iterate letter of current word
				if (placed == false) {
					for (int k = 0; k < preWord.size(); k++) { // iterate letter of previous word
						if (answer[j] == preWord[k]) {
							position = choosePosition(answer, preWord, j, k);
							coords = position.first;
							orientation = position.second;
							int x = coords[0];
							int y = coords[1];
							int comX = coords[2] - 1;
							int comY = coords[3] - 1;
							
							bool isBad = board.isBadPosition(x, y, answer, orientation, comX, comY);
							if (isBad == true && i != onBoard.size()-1) {
								continue;
							}
							else {
								fillCrossword(x, y, answer, orientation);
								placed = true;
								break;
							}
							
						}
					}
				}
			}
		}
	}
}


pair<vector<int>, string>Crossword::choosePosition(const string curWord, const string prevWord, const int curIndex, const int prevIndex) {
	
	int curPos = letterPosition(curWord, curWord[curIndex]);	// position of letter in current answer
	string orientation;
	vector<int> coordinates;
	if (checkOrientation(prevWord) == "horizontally") {
		coordinates = putWordVertically(curWord, prevWord, curIndex, prevIndex, curPos);
		orientation = "vertically";
	}
	else if (checkOrientation(prevWord) == "vertically") {
		coordinates = putWordHorizontally(curWord, prevWord, curIndex, prevIndex, curPos);
		orientation = "horizontally";
	}
	return (make_pair(coordinates, orientation));
}


vector<int> Crossword::putWordHorizontally(const string answer, const string preWord, const int curIndex, const int preIndex, const int curLetterPos) {
	
	int comY = getLetterY(preWord); // common y
	int comX = getLetterX(preWord, preWord[preIndex]); // common x
	int x = comX - 1;
	int y = comY - (curLetterPos - 1) - 1;
	std::vector <int> coordinates = { x, y, comX, comY };
	return coordinates;
}


vector<int> Crossword::putWordVertically(const string answer, const string preWord, const int curIndex, const int preIndex, const int curLetterPos) {
	
	int comX = getLetterX(preWord);	// common x
	int comY = getLetterY(preWord, preWord[preIndex]); // common y
	int x = comX - (curLetterPos - 2) - 1;
	int y = comY - 1;
	std::vector <int> coordinates = { x, y, comX, comY };
	return coordinates;
}


void Crossword::fillCrossword(const int beginRow, const int beginCol, const string answer, const string orientation) {
	
	orientations.push_back(orientation);
	vector<int> coordinates = { beginRow , beginCol };
	firstLettersCoords.push_back(coordinates);
	unsigned aSize = answer.size();
	board.createAndSetUpFields(beginRow, beginCol, aSize, orientation);
}


void Crossword::fillAnswer(const int NOQuestion, const std::string answer) {
	board.fillFields(getFirstLetterX(NOQuestion), getFirstLetterY(NOQuestion), answer, getOrientation(NOQuestion));
}


string Crossword::checkOrientation(const string word) {
	// return what orientation has word on the board 
	int index = getIndexAnswer(word);
	return getOrientation(index);
}


string Crossword::correctAnswer(const int NOQuestion) {
	// answer by number of position in dictionary
	return solutions.find_word(NOQuestion);
}


bool Crossword::isCorrectAnswer(const int NOQuestion, const std::string answer) {
	// check: is answer correct or no
	return (answer == correctAnswer(NOQuestion));
}


bool Crossword::isNumberOfQuestion(const int NOQuestion) {
	// check whather input number is one of number of question
	return (0 < NOQuestion && NOQuestion < solutions.size() + 1);
}


void Crossword::fillField(const int row, const int col, const char value) {
	// fill one field on the board with input value
	board.fillField(row, col, value);
}


std::ostream& operator<<(std::ostream& os, Crossword& c) {
	os << '\n' << c.board;

	int index = 0;
	for (auto& question : c.getQuestions()) {
		os << '\n' << index + 1 << ". " << question;
		if (question.size() < 15) {		// distance should be changed
			os << '\t';
		}
		os << '\t' << "(" << c.getFirstLetterY(index) + 1 << ", " << c.getFirstLetterX(index) + 1 << ")";
		index++;
	}
	return os;
}


std::vector<std::string> Crossword::getQuestions() {
	// return vector of questions
	return solutions.questions();
}


std::string Crossword::getOrientation(const int NOQuestion) {
	// return orientation of word by index
	return orientations[NOQuestion];
}


std::vector<int> Crossword::getFirstLetterCoords(const int NOQuestion) {
	// return vector of x,y position of first letter of the word
	return firstLettersCoords[NOQuestion];
}


int Crossword::getIndexAnswer(const string word) {
	// return index of answer in dictionary 
	return solutions.find_index(word);
}


int Crossword::letterPosition(const string word, const char letter) {
	// return position of letter in the word
	int position = 0;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == letter) {
			position = i + 1;
			return position;
		}
	}
}

int Crossword::getLetterX(const string word, const char letter) {
	// return X position of word`s letter on the board
	int NOQuestion = getIndexAnswer(word);
	int x = getFirstLetterX(NOQuestion);
	int position = letterPosition(word, letter);
	x += position;
	return x;
}

int Crossword::getLetterY(const string word, const char letter) {
	// return Y position of word`s letter on the board
	int NOQuestion = getIndexAnswer(word);
	int y = getFirstLetterY(NOQuestion);
	int position = letterPosition(word, letter);
	y += position;
	return y;
}


int Crossword::getLetterX(const string word) {
	// return X position of first word`s letter  
	int NOQuestion = getIndexAnswer(word);
	int x = getFirstLetterX(NOQuestion);
	return x;
}


int Crossword::getLetterY(const string word) {
	// return Y position of first word`s letter 
	int NOQuestion = getIndexAnswer(word);
	int y = getFirstLetterY(NOQuestion)+1;
	return y;
}


int Crossword::getFirstLetterX(const int NOQuestion) {
	// return X position of first word`s letter by index
	return getFirstLetterCoords(NOQuestion)[0];
}


int Crossword::getFirstLetterY(const int NOQuestion) {
	// return Y position of first word`s letter by index
	return getFirstLetterCoords(NOQuestion)[1];
}
