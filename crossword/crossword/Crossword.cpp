#include "Crossword.h"


Crossword::Crossword(std::string filepath) {
	Dictionary n_solutions;
	std::vector< std::vector<int>> n_first_letters;
	std::vector<std::string> n_orientations;

	std::ifstream fileHandle;
	try {
		fileHandle.open(filepath);
	}
	catch (std::exception const& e) {
		cout << "Invalid file error: " << e.what() << endl;
	}

	std::vector <std::string> rows = parseRows(fileHandle);
	fileHandle.close();

	for (auto& row : rows) {
		std::vector <std::string> rowData = parseCSV(row);
		if (rowData.size() != 5) throw InvalidData();

		n_solutions.add_word(rowData.at(1), rowData.at(0));
		std::vector<int> pos;
		pos.push_back(number(rowData.at(2)));
		pos.push_back(number(rowData.at(3)));
		n_first_letters.push_back(pos);
		n_orientations.push_back(rowData.at(4));
	}

	init(n_solutions, n_first_letters, n_orientations);
}


std::vector <std::string> parseRows(std::ifstream& fileHandle) {
	std::vector <std::string> data;
	std::string temp;

	while (getline(fileHandle, temp)) {
		data.push_back(temp);
	}
	return data;
}


std::vector <std::string> parseCSV(std::string& data) {
	std::vector <std::string> sepData;
	std::string temp;
	std::stringstream s;
	s << data;

	while (getline(s, temp, ',')) {
		sepData.push_back(temp);
	}
	return sepData;
}


Crossword::Crossword(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations) {
	init(n_solutions, first_letters, n_orientations);
}


Crossword::Crossword(const Dictionary n_solutions) {
	solutions = n_solutions;
	choosePositionPutAnswers();
	//fillCrossword();
}

void Crossword::init(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations) {
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
	int row = 0, col = 0;
	int answerSize = answer.size();
	if (answerSize % 2 == 0) { row = 6; col = 6; }
	else { row = 6; col = 7; }
	// (row, y) = (7, 7) or (7, 8) on the board
	fillCrossword(row, col, answer, orientation);
}


void Crossword::putAnotherWord(const string answer, const int answerSize, vector<string> onBoard) {
	bool placed = false;
	pair<vector<int>, string> position;
	vector<int> coords;
	string orientation;
	int lastJ = 0;
	for (int i = 0; i < onBoard.size(); i++) { // iterate vector of words which are already on board
		string preWord = onBoard[i];
		if (placed == false) {
			lastJ = 0;
			for (int j = 0; j < answerSize; j++) { // iterate letter of current word
				lastJ++;
				if (placed == false) {
					for (int k = 0; k < preWord.size(); k++) { // iterate letter of previous word
						if (answer[j] == preWord[k]) {
							placed = foundCommonLetter(answer, preWord, j, k);
							if (placed == true) {
								break;
							}
							else {
								continue;
							}
						}
					
					}
				}
			}
		}
		if ((lastJ == answerSize) && (i == onBoard.size()-1) && (placed == false)) {
			notFoundCommonLetter(answer, preWord);
			placed = true;
			break;
		}
	}
}

vector<int> Crossword::putWordRandomly(const string curWord)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(board.getNORows() / 2, board.getNORows() * 2); // define the range
	int randRow = distr(gen);
	int randCol = distr(gen);
	std::vector <int> coordinates = { randRow, randCol };
	return coordinates;
}


bool Crossword::isNotLastAnswer(const string answer) {
	int index = getIndexAnswer(answer);
	if (index != solutions.size() - 1) {
		return true;
	}
	return false;
}


void Crossword::notFoundCommonLetter(const string answer, const string preWord) {
	bool placed = false;
	pair<vector<int>, string> position;
	vector<int> coords;
	string orientation;
	while (!placed) {
		position = chooseRandomPosition(answer, preWord);
		coords = position.first;
		orientation = position.second;
		bool isBad = board.isBadPosition(coords, answer, orientation);
		if (isBad == true) {
			continue;
		}
		else {
			int row = coords[0];
			int col = coords[1];
			fillCrossword(row, col, answer, orientation);
			placed = true;
		}
	}
}


pair<vector<int>, string>Crossword::chooseRandomPosition(const string curWord, const string prevWord) {
	string orientation;
	vector<int> coordinates;
	if (checkOrientation(prevWord) == "horizontally") {
		orientation = "vertically";
	}
	else if (checkOrientation(prevWord) == "vertically") {
		orientation = "horizontally";
	}
	coordinates = putWordRandomly(curWord);
	return (make_pair(coordinates, orientation));
}


bool Crossword::foundCommonLetter(const string answer, const string preWord, const int ansIndex, const int prevIndex) {
	bool yes = false;
	pair<vector<int>, string> position;
	vector<int> coords;
	string orientation;
	position = choosePosition(answer, preWord, ansIndex, prevIndex);
	coords = position.first;
	orientation = position.second;
	int row = coords[0];
	int col = coords[1];
	bool isBad = board.isBadPosition(coords, answer, orientation);

	if (isBad == true) {
		return yes; // false
	}
	else {
		fillCrossword(row, col, answer, orientation);
		yes = true;
		return yes;
	}
}

pair<vector<int>, string>Crossword::choosePosition(const string curWord, const string prevWord, const int curIndex, const int prevIndex) {

	// int curPos = letterPosition(curWord, curWord[curIndex]);	// position of letter in current answer
	string orientation;
	vector<int> coordinates;
	if (checkOrientation(prevWord) == "horizontally") {
		coordinates = putWordVertically(curWord, prevWord, curIndex, prevIndex);
		orientation = "vertically";
	}
	else if (checkOrientation(prevWord) == "vertically") {
		coordinates = putWordHorizontally(curWord, prevWord, curIndex, prevIndex);
		orientation = "horizontally";
	}
	return (make_pair(coordinates, orientation));
}

vector<int> Crossword::putWordHorizontally(const string answer, const string preWord, const int curIndex, const int preIndex) {
	int comCol = getLetterCol(preWord);
	int comRow = getLetterRow(preWord, preWord[preIndex]);
	int col = comCol - (curIndex);
	int row = comRow;
	std::vector <int> coordinates = { row, col, comRow, comCol };
	return coordinates;
}


vector<int> Crossword::putWordVertically(const string answer, const string preWord, const int curIndex, const int preIndex) {

	int comCol = getLetterCol(preWord, preWord[preIndex]);
	int comRow = getLetterRow(preWord);
	int col = comCol;
	int row = comRow - (curIndex);
	std::vector <int> coordinates = { row, col, comRow, comCol };
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
	board.fillFields(getFirstLetterRow(NOQuestion), getFirstLetterCol(NOQuestion), answer, getOrientation(NOQuestion));
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
		os << '\t' << "(" << c.getFirstLetterRow(index) + 1 << ", " << c.getFirstLetterCol(index) + 1 << ")";
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
			position = i;
			return position;
		}
	}
	throw std::out_of_range("No letter");
}

int Crossword::getLetterRow(const string word, const char letter) {
	// return X position of word`s letter on the board
	int NOQuestion = getIndexAnswer(word);
	string orientation = getOrientation(NOQuestion);
	int row = getFirstLetterRow(NOQuestion);
	int position = letterPosition(word, letter);
	if (orientation == "vertically") {
		row += position;
	}
	return row;
}

int Crossword::getLetterCol(const string word, const char letter) {
	// return Y position of word`s letter on the board
	int NOQuestion = getIndexAnswer(word);
	string orientation = getOrientation(NOQuestion);
	int col = getFirstLetterCol(NOQuestion);
	int position = letterPosition(word, letter);
	if (orientation == "horizontally") {
		col += position;
	}
	return col;
}


int Crossword::getLetterRow(const string word) {
	// return X position of first word`s letter  
	int NOQuestion = getIndexAnswer(word);
	int row = getFirstLetterRow(NOQuestion);
	return row;
}


int Crossword::getLetterCol(const string word) {
	// return Y position of first word`s letter 
	int NOQuestion = getIndexAnswer(word);
	int col = getFirstLetterCol(NOQuestion);
	return col;
}


int Crossword::getFirstLetterRow(const int NOQuestion) {
	// return X position of first word`s letter by index
	return getFirstLetterCoords(NOQuestion)[0];
}


int Crossword::getFirstLetterCol(const int NOQuestion) {
	// return Y position of first word`s letter by index
	return getFirstLetterCoords(NOQuestion)[1];
}
