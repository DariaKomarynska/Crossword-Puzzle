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


void Game::filling() {
	std::string input = "0";
	std::cout << "\n1. QUESTION\n2. FIELD\n";
	std::cin >> input;
	while(input != "1" && input != "2") {
		cout << "Try again!\n";
		std::cin >> input;
	}
	if (input == "1") {
		input = numberOfQuestion();
		while (!isNumber(input) || !crossword.isNumberOfQuestion(number(input))) {
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
			try {
				crossword.fillField(nRow, nCol, input[0]);

			}
			catch (const std::out_of_range& err) {
				std::cout << err.what();

			}

			catch (const NotAlphaOrSpace& err) {
				std::cout << err.what();

			}

			catch (const FieldNotSettedUp& err) {
				std::cout << err.what();

			}

		}
		else input = "-1";
	}
}


std::string Game::numberOfQuestion() {
	std::string input = "0";
	std::cout << "Enter number of question: ";
	std::cin >> input;
	return input;
}


void Game::ending() {
	// board.clear();
	// board.putFirstLetters();
	countPoints();
	showCorrectBoard();
	std::cout << player <<'\n';
}


void Game::countPoints() {
	player.addPoints(crossword.countPoints());
}


void Game::checkForPoints(int row, int col) {
	// if (board.isCorrect(row, col));
}


void Game::showCorrectBoard() {
	crossword.getCorrectBoard();
	cout << crossword << endl; // crossword.getBoard() shows only board without questions
}


std::vector <Player> getPlayers() {
    std::vector <Player> players_vector;
    std::ifstream data_file("userData.csv");
    std::string str;
    while (std::getline(data_file, str)) {
        std::stringstream lineStream(str);
        Player p;
        lineStream >> p;
        players_vector.push_back(p);
    }
    data_file.close();
    return players_vector;
}


bool cmpPairs(const std::pair<std::string, int>& l, const std::pair<std::string, int>& r) {
	if (l.second != r.second) {
		return l.second > r.second;
	}

	return l.first > r.first;
}


Player getPlayerByName(const std::string name) {
	std::vector <Player> players = getPlayers();
	for (auto& player : players) {
		if (player.getName() == name) {
			return player;
		}
	}
	throw std::invalid_argument("Player not found");
}
