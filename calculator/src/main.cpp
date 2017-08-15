#include <iostream>

#include "Logarithm.hpp"
#include "Trigonometry.hpp"
#include "ScientificCalculator.hpp"

using namespace std;

int main() {
	Logarithm log;
	Trigonometry trig;
	ScientificCalculator calc(&log, &trig);
	std::cout<<"sin of 30 degree is: " << calc.sin(30) << std::endl;
	std::cout<<"log of 1000 (base 10) is: " << calc.log10(1000) << std::endl;
	return 0;
}
