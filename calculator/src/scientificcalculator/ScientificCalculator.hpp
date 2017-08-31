#pragma once

#include "Calculator.hpp"
#include "Logarithm.hpp"
#include "Trigonometry.hpp"
#include "types.hpp"

class ScientificCalculator: public Calculator {
public:
	ScientificCalculator(Logarithm *log, Trigonometry *trig);
	double log(double value);
	double log10(double value);

	double sin(double angle);
	double cos(double angle);
	double tan(double angle);

	void testFunction1(double value);
	void testFunction2();
	void testFunction3();
	void testFunction4();
	void testFunction5(double value);

private:
	Logarithm *m_Log;
	Trigonometry *m_Trig;
};
