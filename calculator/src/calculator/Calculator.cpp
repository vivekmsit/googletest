#include "Calculator.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int Calculator::sum(int a, int b) {
	return a + b;
}

int Calculator::subtract(int a, int b) {
	return a - b;
}

int Calculator::multiply(int a, int b) {
	return a * b;
}

float Calculator::divide(int a, int b) {
	if (b != 0) {
		return a/b;
	} else {
		throw std::logic_error("Divide by zero");
	}
}
