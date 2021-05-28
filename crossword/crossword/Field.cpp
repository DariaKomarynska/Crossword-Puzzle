#include "Field.h"
#include <string>
#include "crosswordErrors.cpp"


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


extern bool alphaOrSpaceValidation(const char c) {
	if (!isAlpha(c) && c != ' ') {
		throw NotAlphaOrSpace();
	}
	return true;
}


extern bool isAlpha(const char c) {
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}


extern bool numberValidation(const char c) {
	if (!isNumber(c)) {
		throw NotNumber();
	}
	return true;
}

extern bool numberValidation(std::string c) {
	if (!isNumber(c)) {
		throw NotNumber();
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
	numberValidation(s);
	return std::stoi(s);
}


extern int number(const char s) {
	numberValidation(s);
	std::string st;
	st.push_back(s);
	return number(st);
}


extern char intToChar(int num) {
	std::string s = std::to_string(num);
	char const* pchar = s.c_str();
	return *pchar;
}


extern char stringToChar(const std::string num) {
	char *index = new char[num.length() + 1];
	strcpy_s(index, num.length() + 1, num.c_str());
	return *index;
}
