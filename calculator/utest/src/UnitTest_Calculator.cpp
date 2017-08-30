#include "Calculator.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

class CalculatorTest: public ::testing::Test {
public:

CalculatorTest() {

}

void SetUp() {
}

void TearDown() {
}

~CalculatorTest() {

}

};


TEST_F(CalculatorTest, sum) {
	Calculator calc;
	int result = calc.sum(5,6);
	EXPECT_EQ(result, 11);
}

TEST_F(CalculatorTest, subtract) {
	Calculator calc;
	int result = calc.subtract(10,6);
	EXPECT_EQ(result, 4);
}

TEST_F(CalculatorTest, multiply) {
	Calculator calc;
	int result = calc.multiply(3,4);
	EXPECT_EQ(result, 12);
}

TEST_F(CalculatorTest, divide) {
	Calculator calc;
	int result = calc.divide(6,3);
	EXPECT_EQ(result, 2);
}

TEST_F(CalculatorTest, divideByZero) {
	Calculator calc;
	EXPECT_THROW( { calc.divide(5,0);}, std::logic_error);
}

