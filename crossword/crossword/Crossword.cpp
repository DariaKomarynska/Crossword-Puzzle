#include "Crossword.h"

 
Crossword::Crossword(std::string filepath) {

}


Crossword::Crossword(const Dictionary sol, const std::vector< std::vector<int>> fLett, const std::vector<std::string> orients) {
	if (sol.size() != fLett.size() || sol.size() != orients.size()) {
		throw std::invalid_argument("Invalid data size");
	}

	for (auto& point : fLett) {
		if (point.size() != 2) {
			throw std::invalid_argument("Invalid data size");
		}
	}

	for (auto& orient : orients) {
		if (orient != "vertically" && orient != "horizontally") {
			throw std::invalid_argument("Invalid orientation");
		}
	}

	
	Board b = Board();
}


