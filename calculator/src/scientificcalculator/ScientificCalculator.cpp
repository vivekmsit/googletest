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

// Example function for testing Return(x)
void ScientificCalculator::testFunction1(double value) {
	double result = m_Log->log10Method(value);
	if (result < 5 ) {
		m_Trig->sinMethod(30);
	} else {
		m_Trig->cosMethod(90);
	}
}

// Example function for testing SetArgReferee()
void ScientificCalculator::testFunction2() {
	testStruct st;
	m_Log->logTestFunction1(st);
	if (st.a < 5 ) {
		m_Trig->sinMethod(30);
	} else {
		m_Trig->cosMethod(90);
	}
}

// Example function for testing SetArgPointee()
void ScientificCalculator::testFunction3() {
	testStruct st;
	m_Log->logTestFunction2(&st);
	if (st.a < 5 ) {
		m_Trig->sinMethod(30);
	} else {
		m_Trig->cosMethod(90);
	}
}

// Example function for testing SaveArgPointee()
void ScientificCalculator::testFunction4() {
	testStruct st;
	st.a = 6;
	st.flag = true;
	m_Log->logTestFunction3(&st);
}



// Example function for testing RetiresOnSaturation()
void ScientificCalculator::testFunction5(double value) {
	double result1 = m_Log->log10Method(value);
	double result2 = m_Log->log10Method(2*value);
	if (result1 != result2) {
		m_Trig->sinMethod(30);
	} else {
		m_Trig->cosMethod(90);
	}
}

