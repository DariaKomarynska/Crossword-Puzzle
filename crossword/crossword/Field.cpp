#include "Field.h"
#include <string>
#include <cstring>
#include "crosswordErrors.cpp"

// Fill with given letter or space.
void Field::fill(const char c) {
	alphaOrSpaceValidation(c);
	if (value == '#') throw FieldNotSettedUp();

	if (c != '_') {
		value = tolower(c);
	}
	else {
		value = c;
	}
}

// Fill with first char of given string.
void Field::fill(const std::string s) {
	fill(s[0]);
}

// Fill with given number.
void Field::putIndex(const int num) {
	value = intToChar(num);
}

// Fill with given number.
void Field::putIndex(const char num) {
	numberValidation(num);
	value = num;
}

// Fill with given number.
void Field::putIndex(const std::string num) {
	char c = stringToChar(num);
	numberValidation(c);
	value = c;
}

// Set value to '#'.
void Field::clear() {
	if(value != '#') value = '_';
}

// Verify that argument is letter or space.
extern bool alphaOrSpaceValidation(const char c) {
	if (!isAlpha(c) && c != ' ') {
		throw NotAlphaOrSpace();
	}
	return true;
}

// Verify that argument is a letter.
extern bool isAlpha(const char c) {
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

// Verify that argument is a number.
extern bool numberValidation(const char c) {
	if (!isNumber(c)) {
		throw NotNumber();
	}
	return true;
}

// Verify that argument is a number.
extern bool numberValidation(std::string c) {
	if (!isNumber(c)) {
		throw NotNumber();
	}
	return true;
}

// Verify that argument is a number.
extern bool isNumber(const char c) {
	return c >= 48 && c <= 57;
}

// Verify that argument is a number.
extern bool isNumber(std::string s) {
	for (char let : s) {
		if (!isdigit(let)) return false;
	}
	return true;
}

// Convert string into int.
extern int number(std::string s) {
	numberValidation(s);
	return std::stoi(s);
}

// Convert char into int.
extern int number(const char s) {
	numberValidation(s);
	std::string st;
	st.push_back(s);
	return number(st);
}

// Convert int into char.
extern char intToChar(int num) {
	std::string s = std::to_string(num);
	char const* pchar = s.c_str();
	return *pchar;
}

// Return first char of a string.
extern char stringToChar(const std::string num) {
	char *index = new char[num.length() + 1];
	strcpy_s(index, num.length() + 1, num.c_str());
	return *index;
}
