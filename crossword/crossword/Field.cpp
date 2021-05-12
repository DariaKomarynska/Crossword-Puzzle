#include "Field.h"


void Field::postInit(const int NOQue, const char exVal) {
	NOQuestion = NOQue;
	value = '_';
	expectedValue = exVal;
}


void Field::clear() {
	if(expectedValue != '#') value = '_';
}