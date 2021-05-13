#include "Field.h"


void Field::postInit(const int NOQue, const char exVal, const char val) {
	NOQuestion = NOQue;
	value = val;
	expectedValue = exVal;
}


void Field::clear() {
	if(expectedValue != '#') value = '_';
}