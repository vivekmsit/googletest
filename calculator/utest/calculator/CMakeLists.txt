cmake_minimum_required(VERSION 2.8)

project(CalculatorUnitTest C CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("../../src/calculator")
include_directories("../../src")

add_executable(calculator_test
	UnitTest_Calculator.cpp
	../../src/calculator/Calculator.cpp 
)

target_link_libraries(calculator_test gtest_main gtest gmock pthread)



