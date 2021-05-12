#pragma once

class Field {
private:
	char expectedValue = '#';

public:
	int NOQuestion = -1;
	char value = '#';

	Field() {};		// use this for empty - | # | field
	Field(const int NOQue, const char exVal = '_', const char val = '_') : NOQuestion(NOQue), expectedValue(exVal), value(val) {};
	bool isCorrect() { return expectedValue == value; }
};
