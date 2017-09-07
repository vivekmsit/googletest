#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Logarithm.hpp"

class Trigonometry_Mock: public Trigonometry {
public:
	Trigonometry_Mock():Trigonometry(){}
	virtual ~Trigonometry_Mock(){}

	MOCK_METHOD1(sinMethod, double(double));
	MOCK_METHOD1(cosMethod, double(double));
	MOCK_METHOD1(tanMethod, double(double));
};
