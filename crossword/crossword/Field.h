#pragma once

class Field {
private:
	char expectedValue = '#';
	char value = '#';
	int NOQuestion = -1;

public:
	

	Field() {};		// use this for empty - | # | field
	Field(const int NOQue, const char exVal = '_', const char val = '_') : NOQuestion(NOQue), expectedValue(exVal), value(val) {};
	bool isCorrect() { return expectedValue == value; }
	void postInit(const int NOQue, const char exVal) {
		NOQuestion = NOQue;
		value = '_';
		expectedValue = exVal;
	}
	bool isExpected(char my_char) { return my_char == expectedValue; }
	void setExpected(char c) { expectedValue = c; }
	void fill(char c) { value = c; }
};
