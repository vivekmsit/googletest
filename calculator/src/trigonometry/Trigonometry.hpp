#pragma once

class Trigonometry {
public:
	Trigonometry(){}
	virtual ~Trigonometry(){}

	virtual double sinMethod(double degrees);
	virtual double cosMethod(double degrees);
	virtual double tanMethod(double degrees);
};
