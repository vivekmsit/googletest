#include "Trigonometry.hpp"
#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159265

double Trigonometry::sinMethod(double degrees) {
	return sin(degrees*PI/180);
}

double Trigonometry::cosMethod(double degrees) {
	return cos(degrees*PI/180);
}

double Trigonometry::tanMethod(double degrees) {
	return tan(degrees*PI/180);
}

