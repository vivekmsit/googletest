cmake_minimum_required(VERSION 2.8)

project(CalculatorUnitTest C CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("../src/calculator")
include_directories("../src/scientificcalculator")
include_directories("../src/logarithm")
include_directories("../src/trigonometry")
include_directories("mocks")


add_executable(calculator_test
	src/UnitTest_Calculator.cpp
	../src/calculator/Calculator.cpp 
)

target_link_libraries(calculator_test gtest_main gmock_main gtest gmock pthread)


add_executable(scientificCalculator_test
	src/UnitTest_ScientificCalculator.cpp
	../src/calculator/Calculator.cpp
	../src/scientificcalculator/ScientificCalculator.cpp 
	../src/logarithm/Logarithm.cpp
	../src/trigonometry/Trigonometry.cpp
)

target_link_libraries(scientificCalculator_test gtest_main gmock_main gtest gmock pthread)
