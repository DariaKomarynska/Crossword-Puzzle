#include <iostream>
#include "Game.h"
#include "aid.cpp"


Game::Game(Player nPlayer, Board nBoard) : player(nPlayer), board(nBoard) {
	board.clear();
}


void Game::play() {
	std::cout << "Welcome! Good luck! Have fun!\n";

	bool end = false;
	while (!end) {
		std::cout << board;

		std::string input="0";

		while (input != "1" && input != "2" && input != "3") {
			std::cout << "\n1. FILL\n2. CHECK\n3. END\n";
			std::cin >> input;

			if (input == "1") {
				std::cout << "\n1. QUESTION\n2. FIELD\n";
				std::cin >> input;
				if (input == "1") {
					std::cout << "Enter number of question: ";
					std::cin >> input;

					std::string answer;
					std::cout << "Enter answer: ";
					std::cin >> answer;

					board.fillAnswer(input, answer);
				}
				else if (input == "2") {
					std::string row;
					std::string col;

					std::cout << "ROW: ";
					std::cin >> row;
					std::cout << "COLUMN: ";
					std::cin >> col;
					if (isNumber(row) && isNumber(col)) {
						int nRow = number(row);
						int nCol = number(col);
						if (board.validCoords(row, col)) {
							std::cout << "Enter letter: \n";
							std::cin >> input;
							board.fillField(nRow, nCol, input[0]);
						}
					}
					else input = -1;
				}
				else input = -1;
			}
			else if(input == "2") {

			}
			else if(input == "3") {

			}
			else {
				std::cout << "Try again!\n";
			}
		}
	}
}