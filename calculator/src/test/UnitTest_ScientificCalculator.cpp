#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ScientificCalculator.hpp"
#include "Logarithm_Mock.hpp"
#include "Trigonometry_Mock.hpp"

using namespace testing;

class ScientificCalculatorTest: public ::testing::Test {
public:

ScientificCalculatorTest() {

}

void SetUp() {
}

void TearDown() {
}

~ScientificCalculatorTest() {

}

};


TEST_F(ScientificCalculatorTest, log10) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1);
	double result = calc.log10(1000);
}

TEST_F(ScientificCalculatorTest, sin) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	double result = calc.sin(30);
}

TEST_F(ScientificCalculatorTest, cos) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(tMock, cosMethod(_)).Times(1);
	double result = calc.cos(30);
}

TEST_F(ScientificCalculatorTest, tan) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(tMock, tanMethod(_)).Times(1);
	double result = calc.tan(30);
}

TEST_F(ScientificCalculatorTest, testFunction1_IF_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(3));
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction1(1000);
}

TEST_F(ScientificCalculatorTest, testFunction1_ELSE_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(7));
	EXPECT_CALL(tMock, cosMethod(_)).Times(1);
	calc.testFunction1(1000);
}



