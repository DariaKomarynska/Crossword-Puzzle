#include "Crossword.h"

 
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
	unsigned size = n_solutions.size();
	//Dictionary n_solutions, vector< vector<int>> first_letters, vector<string> n_orientations
	solutions = n_solutions;
	vector <string> words = solutions.answers();
	std::vector<string> onBoard;
	for (unsigned i = 0; i < size; i++) {
		std::string answer = correctAnswer(i);
		unsigned a_size = answer.size();
		std::vector<int> coords;
		//std::string orientation = getOrientation(i);
		int x = 0, y = 0;
		bool placed = false;
		if (i == 0) {
			orientations.push_back("horizontally");
			
			if (a_size % 2 == 0) { x = 4; y = 4; }
			else { x = 5; y = 4;}
			placed = true;
		}
		else if (i % 2 == 0) {
			for (int i = 0; i < onBoard.size(); i++) { // iterate vector of words which are already on board
				string preWord = onBoard[i];
				if (checkOrientation(preWord) == "horizontally") {
					continue;
				}
				if (placed == false) {
					for (int j = 0; j < a_size; j++) { // iterate letter of current word
						if (placed == false) {
							for (int k = 0; k < preWord.size(); k++) { // iterate letter of previous word
								if (answer[j] == preWord[k]) {
									
									int comX = getLetterY(preWord);
									int comY = getLetterX(preWord, preWord[k]);
									char comLetter = answer[j]; // HORIZONTAL NOW	
									int curPos = findPosition(answer, answer[j]);	// position of letter in current answer
									int prePos = findPosition(preWord, preWord[k]);
									y = comY ;
									x = comX - (curPos -1);
									orientations.push_back("horizontally");
									placed = true;
									break;
								}
							}
						}
					}
				}
			}
		}
		else {
			if (placed == false){
				for (int i = 0; i < onBoard.size(); i++) { // iterate vector of words which are already on board
					string preWord = onBoard[i];
					if (checkOrientation(preWord) == "vertically") {
						continue;
					}
					if (placed == false) {
						for (int j = 0; j < a_size; j++) { // iterate letter of current word
							if (placed == false) {
								for (int k = 0; k < preWord.size(); k++) { // iterate letter of previous word
									if (answer[j] == preWord[k]) {
										
										int comY = getLetterX(preWord);
										int comX = getLetterY(preWord, preWord[k]);
										char comLetter = answer[j]; // VERTICAL NOW	
										int curPos = findPosition(answer, answer[j]) ;	// position of letter in current answer
										int prePos = findPosition(preWord, preWord[k]);
										y = comY - (curPos - 2);
										x = comX;
										orientations.push_back("vertically");
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
		coords.push_back(y - 1);
		coords.push_back(x - 1);
		firstLettersCoords.push_back(coords);
		onBoard.push_back(answer);
	}
	fillCrossword();
}

void Crossword::fillCrossword() {
	for (int i = 0; i < solutions.size(); i++) {
		std::string answer = correctAnswer(i);
		unsigned a_size = answer.size();
		std::string orientation = getOrientation(i);

		board.createAndSetUpFields(getFirstLetterX(i), getFirstLetterY(i), a_size, orientation);
	}
}
void Crossword::fillAnswer(const int NOQuestion, const std::string answer) {
	board.fillFields(getFirstLetterX(NOQuestion), getFirstLetterY(NOQuestion), answer, getOrientation(NOQuestion));
}

string Crossword::checkOrientation(const string word) {
	int index = getIndexAnswer(word);
	return getOrientation(index);
}

string Crossword::correctAnswer(const int NOQuestion) {
	return solutions.find_word(NOQuestion);
}


bool Crossword::isCorrectAnswer(const int NOQuestion, const std::string answer) {
	return (answer == correctAnswer(NOQuestion));
}


bool Crossword::isNumberOfQuestion(const int NOQuestion) {
	return (0 < NOQuestion && NOQuestion < solutions.size() + 1);
}


void Crossword::fillField(const int row, const int col, const char value) {
	board.fillField(row, col, value);
}


std::ostream& operator<<(std::ostream& os, Crossword& c) {
	os << '\n' << c.board;

	int index = 0;
	for (auto& question : c.getQuestions()) {
		os << '\n' << index + 1 << ". " << question;
		index++;
	}
	return os;
}


std::vector<std::string> Crossword::getQuestions() {
	return solutions.questions();
}


std::string Crossword::getOrientation(const int NOQuestion) {
	return orientations[NOQuestion];
}


std::vector<int> Crossword::getFirstLetterCoords(const int NOQuestion) {
	return firstLettersCoords[NOQuestion];
}

int Crossword::getIndexAnswer(const string word) {
	return solutions.find_index(word);
}

int Crossword::findPosition(const string word, const char letter) {
	int position = 0;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == letter) {
			position = i;
			return position +1;
		}
	}
}

int Crossword::getLetterX(const string word, const char letter) {
	int NOQuestion = getIndexAnswer(word);
	int x = getFirstLetterX(NOQuestion);
	int position = findPosition(word, letter);
	x += position;
	return x;
}

int Crossword::getLetterY(const string word, const char letter) {
	int NOQuestion = getIndexAnswer(word);
	int y = getFirstLetterY(NOQuestion);
	int position = findPosition(word, letter);
	y += position;
	return y;
}

int Crossword::getLetterY(const string word) {
	int NOQuestion = getIndexAnswer(word);
	int y = getFirstLetterY(NOQuestion)+1;
	return y;
}

int Crossword::getLetterX(const string word) {
	int NOQuestion = getIndexAnswer(word);
	int x = getFirstLetterX(NOQuestion);
	return x;
}

int Crossword::getFirstLetterX(const int NOQuestion) {
	return getFirstLetterCoords(NOQuestion)[0];
}


int Crossword::getFirstLetterY(const int NOQuestion) {
	return getFirstLetterCoords(NOQuestion)[1];
}
