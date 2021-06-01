#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Crossword.h"
#include "Dictionary.h"
#include <map>
#include <vector>

int main(){
	//std::vector<std::vector<int>> pair = { {1, 1}, {1, 1} };
	//std::vector<std::string> orientation = { "vertically", "horizontally" };
	
	Player jacus = Player("Jacex");
	Dictionary dict = Dictionary();
	dict.add_word("paliwko", "piwo to moje");
	dict.add_word("psz", "pszczola bez czola");
	dict.add_word("pingwin", "ptak");
	dict.add_word("zajac", "bajki o grafach");
	dict.add_word("winiary", "czerwone");
	dict.add_word("enkapsulacja", "enkapsulacja");
	dict.add_word("orzeszki", "zimne");
	dict.add_word("mleko", "napoj");
	// wino - bląd!!!
	//dict.add_word("rozzzzzzz", "costam");

	/*dict.add_word("siostra", "siostra");
	dict.add_word("brat", "brat");*/
	//Crossword crossword = Crossword(dict, pair, orientation);
	Crossword crossword = Crossword(dict);
	Game game = Game(jacus, crossword);
	game.play();

	return 0;
}