#include "Field.h"
#include <string>


void Field::fill(const char c) {
	alphaValidation(c);
	if (value != '#') {
		value = tolower(c);
	}
	else {
		throw std::invalid_argument("This field should remain empty");
	}
}


void Field::fill(const std::string s) {
	fill(s[0]);
}


void Field::putIndex(const int num) {
	value = intToChar(num);
}


void Field::putIndex(const char num) {
	numberValidation(num);
	value = num;
}


void Field::putIndex(const std::string num) {
	char c = stringToChar(num);
	numberValidation(c);
	value = c;
}


void Field::clear() {
	if(value != '#') value = '_';
}


extern bool alphaValidation(const char c) {
	if (!isAlpha(c)) {
		throw std::invalid_argument("You can fill this field only with letter");
	}
	return true;
}


extern bool isAlpha(const char c) {
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}


extern bool numberValidation(const char c) {
	if (!isNumber(c)) {
		throw std::invalid_argument("This is not a number");
	}
	return true;
}


extern bool isNumber(const char c) {
	return c >= 48 && c <= 57;
}


extern bool isNumber(std::string s) {
	for (char let : s) {
		if (!isdigit(let)) return false;
	}
	return true;
}


extern int number(std::string s) {
	if (isNumber(s)) {
		return std::stoi(s);
	}
	else {
		throw std::invalid_argument("Not numeric");
	}
}


extern char intToChar(int num) {
	std::string s = std::to_string(num);
	char const* pchar = s.c_str();
	return *pchar;
}


extern char stringToChar(std::string num) {
	char *index = new char[num.length() + 1];
	strcpy(index, num.c_str());
	return *index;
}
