#include "ScientificCalculator.hpp"
#include <iostream>

using namespace std;

ScientificCalculator::ScientificCalculator(Logarithm *log, Trigonometry *trig):
	m_Log(log), m_Trig(trig) {

}

double ScientificCalculator::log(double value) {
	return m_Log->logMethod(value);
}

double ScientificCalculator::log10(double value) {
	return m_Log->log10Method(value);
}

double ScientificCalculator::sin(double degrees) {
	return m_Trig->sinMethod(degrees);
}

double ScientificCalculator::cos(double degrees) {
	return m_Trig->cosMethod(degrees);
}

double ScientificCalculator::tan(double degrees) {
	return m_Trig->tanMethod(degrees);
}

void ScientificCalculator::testFunction1(double value) {
	double result = m_Log->log10Method(value);
	if (result < 5 ) {
		m_Trig->sinMethod(30);
	} else {
		m_Trig->cosMethod(90);
	}
}

