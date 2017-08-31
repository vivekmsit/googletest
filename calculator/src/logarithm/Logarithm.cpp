#include "Logarithm.hpp"
#include <math.h>

double Logarithm::logMethod(double value) {
	return log(value);
}

double Logarithm::log10Method(double value) {
	return log10(value);
}

void Logarithm::log10MethodRefWithoutReturn(double value, double &result) {
	result = log10(value);
}

void Logarithm::log10MethodPointWithoutReturn(double value, double *result) {
	*result = log10(value);
}

void Logarithm::logTestFunction1(testStruct &value) {
	(void)value;
}

void Logarithm::logTestFunction2(testStruct *value) {
	(void)value;
}

void Logarithm::logTestFunction3(const testStruct *value) {
	(void)value;
}
