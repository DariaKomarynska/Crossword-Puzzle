#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Crossword.h"
#include "Dictionary.h"
#include <map>
#include <vector>

int main(){
	Crossword c = Crossword("crosswordtest.txt", "tak", true);
	c.makeCSVFile();

	return 0;
}