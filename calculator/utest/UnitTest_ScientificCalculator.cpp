#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>

#include "ScientificCalculator.hpp"
#include "Logarithm_Mock.hpp"
#include "Trigonometry_Mock.hpp"

using namespace testing;
using namespace std;

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
	//std::cout<<"value of result is: " << result << std::endl;
}

// Change default behaviour inside Test Case
TEST_F(ScientificCalculatorTest, log10_DefaultBehaviour_InsideTest) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ON_CALL(lMock, log10Method(_)).WillByDefault(Return(6));
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(2);
	double result1 = calc.log10(1000);
	double result2 = calc.log10(2000);
	EXPECT_EQ(result1, 6);
	EXPECT_EQ(result2, 6);
}

// Change default behaviour inside Mock class
TEST_F(ScientificCalculatorTest, log10_DefaultBehaviour_InsideClass) {
	Logarithm_Mock lMock;
	lMock.setDefaultBehaviour();
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(2);
	double result1 = calc.log10(1000);
	double result2 = calc.log10(2000);
	EXPECT_EQ(result1, 5);
	EXPECT_EQ(result2, 5);
}

// Example test for Return() without setting default behaviour
TEST_F(ScientificCalculatorTest, testFunction1_IF_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(3));
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction1(1000);
}

// Example test for Return()
TEST_F(ScientificCalculatorTest, testFunction1_ELSE_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(7));
	EXPECT_CALL(tMock, cosMethod(_)).Times(1);
	calc.testFunction1(1000);
}

// Checking order using Sequence (Reverse the order to check for failure)
TEST_F(ScientificCalculatorTest, testFunction1_ELSE_CASE_Check_Order) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	Sequence s1;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).InSequence(s1).WillOnce(Return(7));
	EXPECT_CALL(tMock, cosMethod(_)).Times(1).InSequence(s1);
	calc.testFunction1(1000);
}

// Example test for SetArgReferee
TEST_F(ScientificCalculatorTest, testFunction2_IF_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	double expectedResult = 3;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10MethodRefWithoutReturn(_, _)).Times(1).WillOnce(SetArgReferee<1>( expectedResult ));
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction2(1000);
}

// Example test for SetArgPointee()
TEST_F(ScientificCalculatorTest, testFunction3_IF_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	double expectedResult = 3;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10MethodPointWithoutReturn(_, _)).Times(1).WillOnce(SetArgPointee<1>( expectedResult ));
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction3(1000);
}

// Example test for RetiresOnSaturation()
TEST_F(ScientificCalculatorTest, testFunction4_IF_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(1));
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(2)).RetiresOnSaturation();
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction4(1000);
}



