#include "Calculator.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <tuple>

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


// Parameterized Tests for sum function (Separate class is required for each set of parameterized tests)

class ParamCalculatorTest: public ::testing::TestWithParam<std::tuple<int, int, int>> {
public:

ParamCalculatorTest() {

}

void SetUp() {
}

void TearDown() {
}

~ParamCalculatorTest() {

}

};

std::array<std::tuple<int, int, int>, 3 > sumTestValues { 
	std::make_tuple(1,1,2), 
	std::make_tuple(2,3,5), 
	std::make_tuple(5, 6, 11) 
};

TEST_P(ParamCalculatorTest, sum_param) {
	Calculator calc;
	int var1 = std::get<0>(GetParam());
	int var2 = std::get<1>(GetParam());
	int expectedResult = std::get<2>(GetParam());
	int result = calc.sum(var1,var2);
	EXPECT_EQ(result, expectedResult);
}

INSTANTIATE_TEST_CASE_P(sum_param, ParamCalculatorTest, ::testing::ValuesIn(sumTestValues));


