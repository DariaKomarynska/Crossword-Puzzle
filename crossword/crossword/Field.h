#pragma once
#include <iostream>

class Field {
private:
	char value;

public:
	Field() : value('#') {};		// empty - '#' field
	Field(const char c) { fill(c); }
	Field(const std::string s) { fill(s[0]); }
	void setUp() { value = '_'; }
	void fill(char c);
	void fill(const std::string s);
	void putIndex(const int num);
	void putIndex(const char num);
	void putIndex(const std::string num);
	void clear();
	char getValue() const { return value; }
};

extern bool alphaOrSpaceValidation(const char c);
extern bool isAlpha(const char c);
extern bool numberValidation(const char c);
extern bool isNumber(const char c);
extern bool isNumber(std::string s);
extern int number(std::string s);
extern char intToChar(int num);
extern char stringToChar(std::string num);