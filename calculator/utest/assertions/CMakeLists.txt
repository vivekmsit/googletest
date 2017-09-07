cmake_minimum_required(VERSION 2.8)

project(CalculatorUnitTest C CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(assertions_test
	UnitTest_Assertions.cpp
)

target_link_libraries(assertions_test gtest pthread)


