#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Logarithm.hpp"

using namespace testing;

class Logarithm_Mock: public Logarithm {
public:
	Logarithm_Mock():Logarithm(){}
	virtual ~Logarithm_Mock(){}

	MOCK_METHOD1(logMethod, double(double));
	MOCK_METHOD1(log10Method, double(double));

	MOCK_METHOD2(log10MethodRefWithoutReturn, void(double, double &));
	MOCK_METHOD2(log10MethodPointWithoutReturn, void(double, double *));

	MOCK_METHOD1(logTestFunction1, void (testStruct &));
	MOCK_METHOD1(logTestFunction2, void (testStruct *));
	MOCK_METHOD1(logTestFunction3, void (const testStruct *));

	// change default behaviour
	void setDefaultBehaviour() {
		ON_CALL(*this, logMethod(_)).WillByDefault(Return(5));
		ON_CALL(*this, log10Method(_)).WillByDefault(Return(5));
	}
};
