#include <iostream>
#include <string>

int number(std::string s) {
	if (isNumber(s)) {
		return std::stoi(s);
	}
	else {
		throw std::invalid_argument("Not numeric");
	}
}


bool isNumber(std::string s) {
	for (char let : s) {
		if (!isdigit(let)) return false;
	}
	return true;
}