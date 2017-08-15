#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Logarithm.hpp"

class Logarithm_Mock: public Logarithm {
public:
	Logarithm_Mock():Logarithm(){}
	virtual ~Logarithm_Mock(){}

	MOCK_METHOD1(logMethod, double(double));
	MOCK_METHOD1(log10Method, double(double));

};
