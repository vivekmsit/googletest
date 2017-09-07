#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <iostream>

#include "ScientificCalculator.hpp"
#include "Logarithm_Mock.hpp"
#include "Trigonometry_Mock.hpp"
#include "types.hpp"

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

// Example test for Return() without setting default behaviour
TEST_F(ScientificCalculatorTest, testFunction1_ELSE_CASE) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(7));
	EXPECT_CALL(tMock, cosMethod(_)).Times(1);
	calc.testFunction1(1000);
}

// Checking order using Sequence (Reverse the order to check for failure)
TEST_F(ScientificCalculatorTest, testFunction1_ELSE_CASE_Using_InSequence) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	Sequence s1;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).InSequence(s1).WillOnce(Return(7));
	EXPECT_CALL(tMock, cosMethod(_)).Times(1).InSequence(s1);
	calc.testFunction1(1000);
}

// Example test for SetArgReferee
TEST_F(ScientificCalculatorTest, testFunction2_IF_CASE_SetArgReferee) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	testStruct myStruct;
	myStruct.a = 3;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, logTestFunction1(_)).Times(1).WillOnce(SetArgReferee<0>( myStruct ));
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction2();
}

// Example test for SetArgPointee()
TEST_F(ScientificCalculatorTest, testFunction3_IF_CASE_SetArgPointee) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	testStruct myStruct;
	myStruct.a = 3;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, logTestFunction2(_)).Times(1).WillOnce(SetArgPointee<0>( myStruct ));
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction3();
}

// Example test for SaveArgPointee()
TEST_F(ScientificCalculatorTest, testFunction4_SaveArgPointee) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	testStruct myStruct;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, logTestFunction3(_)).Times(1).WillOnce(SaveArgPointee<0>( &myStruct ));
	calc.testFunction4();
	EXPECT_EQ(myStruct.a, 6);
	EXPECT_EQ(myStruct.flag, true);
}

// Example test for RetiresOnSaturation()
TEST_F(ScientificCalculatorTest, testFunction5_IF_CASE_RetiresOnSaturation) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(1));
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(2)).RetiresOnSaturation();
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction5(1000);
}

// Example test for testing how expect calls are checked (bottom to top order during mock method call)
TEST_F(ScientificCalculatorTest, testFunction5_order_of_expect_calls) {
	Logarithm_Mock lMock;
	Trigonometry_Mock tMock;
	ScientificCalculator calc(&lMock, &tMock);

	//std::cout<<"test1"<<std::endl;
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(1));
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(2)).RetiresOnSaturation();
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	//std::cout<<"test2"<<std::endl;
	calc.testFunction5(1000);

	//std::cout<<"test3"<<std::endl;
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(1));
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(2)).RetiresOnSaturation();
	EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	//std::cout<<"test4"<<std::endl;
	calc.testFunction5(1000);

	//std::cout<<"test5"<<std::endl;
}

// Example test for NiceMock<> (No warning for Uninteresting mock function calls)
TEST_F(ScientificCalculatorTest, testFunction_NiceMock) {
	Logarithm_Mock lMock;
	NiceMock<Trigonometry_Mock> tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(1));
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(2)).RetiresOnSaturation();
	//EXPECT_CALL(tMock, sinMethod(_)).Times(1);
	calc.testFunction5(1000);
}

// Example test for StrictMock<> (Test Failure for Uninteresting mock function calls)
TEST_F(ScientificCalculatorTest, testFunction_StrictMock) {
	Logarithm_Mock lMock;
	StrictMock<Trigonometry_Mock> tMock;
	ScientificCalculator calc(&lMock, &tMock);
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(1));
	EXPECT_CALL(lMock, log10Method(_)).Times(1).WillOnce(Return(2)).RetiresOnSaturation();
	EXPECT_CALL(tMock, sinMethod(_)).Times(1); // Comment this line to get failure for uninteresting calls as Mock is of type StrictMock.
	calc.testFunction5(1000);
}


