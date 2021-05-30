#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Crossword.h"
#include "Dictionary.h"
#include <map>
#include <vector>

int main(){
	std::vector<std::vector<int>> pair = { {10, 10}, {2, 1} };
	std::vector<std::string> orientation = { "vertically", "horizontally" };
	
	Player jacus = Player("Jacex");
	Dictionary dict = Dictionary();
	dict.add_word("paliwko", "piwo to moje");
	dict.add_word("psz", "pszczola bez czola");
	dict.add_word("masza", "i niedzwiedz");
	dict.add_word("zajac", "bajki o grafach");
	
	//Crossword crossword = Crossword(dict, pair, orientation);
	Crossword crossword = Crossword(dict);
	Game game = Game(jacus, crossword);
	game.play();

	return 0;
}