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


void Crossword::fillAnswer(const int NOQuestion, const std::string answer) {
	board.fillFields(getFirstLetterX(NOQuestion), getFirstLetterY(NOQuestion), answer, getOrientation(NOQuestion));
}


string Crossword::correctAnswer(const int NOQuestion) {
	return solutions.find_word(NOQuestion);
}


bool Crossword::isCorrectAnswer(const int NOQuestion, const std::string answer) {
	return (answer == correctAnswer(NOQuestion));
}


bool Crossword::isNumberOfQuestion(const int NOQuestion) {
	return (0 < NOQuestion && NOQuestion < solutions.size() + 1);						// zmienic, kiedy pytania będą zaczynać się od 1
}


void Crossword::fillField(const int row, const int col, const char value) {
	board.fillField(row, col, value);
}


std::ostream& operator<<(std::ostream& os, Crossword& c) {
	os << c.board;

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
};


std::vector<int> Crossword::getFirstLetterCoords(const int NOQuestion){
	return firstLettersCoords[NOQuestion];
}


int Crossword::getFirstLetterX(const int NOQuestion){
	return getFirstLetterCoords(NOQuestion)[0];
}


int Crossword::getFirstLetterY(const int NOQuestion) {
	return getFirstLetterCoords(NOQuestion)[1];
}
