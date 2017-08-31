#pragma once

#include "types.hpp"

class Logarithm {
public:
	Logarithm(){}
	virtual ~Logarithm(){}
	virtual double logMethod(double value);
	virtual double log10Method(double value);
	virtual void log10MethodRefWithoutReturn(double value, double &result);
	virtual void log10MethodPointWithoutReturn(double value, double *result);

	virtual void logTestFunction1(testStruct &value);
	virtual void logTestFunction2(testStruct *value);
	virtual void logTestFunction3(const testStruct *value);
};
