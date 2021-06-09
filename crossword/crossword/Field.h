#pragma once
#include <iostream>

// Represents a single field.
class Field {
private:
	char value;

public:
	int index = 0;
	Field() : value('#') {};		// empty - '#' field
	Field(const char c) { fill(c); }
	Field(const std::string s) { fill(s[0]); }
	// Set value to '_'.
	void setUp() { value = '_'; }
	void fill(char c);
	void fill(const std::string s);
	void putIndex(const int num);
	void putIndex(const char num);
	void putIndex(const std::string num);
	void clear();
	// Return value.
	char getValue() const { return value; }
	bool isSettedUp() { return (value != '#'); }

};

extern bool alphaOrSpaceValidation(const char c);
extern bool isAlpha(const char c);
extern bool numberValidation(const char c);
extern bool numberValidation(std::string c);
extern bool isNumber(const char c);
extern bool isNumber(std::string s);
extern int number(std::string s);
extern int number(const char s);
extern char intToChar(int num);
extern char stringToChar(std::string num);