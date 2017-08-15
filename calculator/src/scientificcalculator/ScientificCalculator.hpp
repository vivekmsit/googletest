#pragma once

#include "Calculator.hpp"
#include "Logarithm.hpp"
#include "Trigonometry.hpp"

class ScientificCalculator: public Calculator {
public:
	ScientificCalculator(Logarithm *log, Trigonometry *trig);
	double log(double value);
	double log10(double value);

	double sin(double angle);
	double cos(double angle);
	double tan(double angle);

private:
	Logarithm *m_Log;
	Trigonometry *m_Trig;
};
