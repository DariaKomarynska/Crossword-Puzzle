#include <iostream>
#include "Game.h"


void Game::play() {
	std::cout << "Welcome! Good luck! Have fun!\n";

	bool end = false;
	while (!end) {
		std::cout << crossword << std::endl;

		std::string input="0";

		while (input != "1" && input != "2") {
			std::cout << "\n1. FILL\n2. END\n";
			std::cin >> input;

			if (input == "1") {
				filling();
			}
			else if(input == "2") {
				ending();
				end = true;
			}
			else {
				std::cout << "Try again!\n";
			}
		}
	}
}


std::string Game::numberOfQuestion() {
	std::string input = "0";
	std::cout << "Enter number of question: ";
	std::cin >> input;
	return input;
}

void Game::filling() {
	std::string input = "0";
	std::cout << "\n1. QUESTION\n2. FIELD\n";
	std::cin >> input;
	if (input != "1" && input != "2") {
		cout << "Try again!\n";
		filling();
	}
	if (input == "1") {
		input = numberOfQuestion();
		while (!crossword.isNumberOfQuestion(number(input))) {
			cout << "Try again!\n";
			input = numberOfQuestion();
		}
		std::string answer;
		std::cout << "Enter answer: ";
		std::cin >> answer;

		int qIndex = number(input) - 1;
		crossword.fillAnswer(qIndex, answer);
	}
	else if (input == "2") {
		std::string row;
		std::string col;

		std::cout << "ROW: ";
		std::cin >> row;
		std::cout << "COLUMN: ";
		std::cin >> col;
		std::cout << "Enter letter: \n";
		std::cin >> input;
		if (isNumber(row) && isNumber(col)) {
			int nRow = number(row) - 1;
			int nCol = number(col) - 1;
			crossword.fillField(nRow, nCol, input[0]);

		}
		else input = "-1";
	}
	else input = "-1";
	if (input == "-1") {
		throw std::invalid_argument("Invalid input");
	}
}


void Game::ending() {
	// board.clear();
	// board.putFirstLetters();
	countPoints();
	std::cout << player <<'\n';
}


void Game::countPoints() {
	// player.addPoints(board.getPoints());
}


void Game::checkForPoints(int row, int col) {
	// if (board.isCorrect(row, col));
}