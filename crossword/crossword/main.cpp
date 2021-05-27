#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Crossword.h"
#include "Dictionary.h"
#include <map>
#include <vector>

int main(){
	std::vector<std::vector<int>> pair = { {1, 1}, {1, 1} };
	std::vector<std::string> orientation = { "vertically", "horizontally" };
	
	Player jacus = Player("Jacex");
	Dictionary dict = Dictionary();
	dict.add_word("paliwo", "piwo to moje");
	dict.add_word("psz", "pszczola bez czola");
	
	Crossword crossword = Crossword(dict, pair, orientation);

	Game game = Game(jacus, crossword);
	game.play();

	return 0;
}