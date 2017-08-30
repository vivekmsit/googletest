cmake_minimum_required(VERSION 2.8)

project(ScientificCalculator C CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("calculator")
include_directories("scientificcalculator")
include_directories("logarithm")
include_directories("trigonometry")
include_directories("test")

add_executable(main 
	main.cpp 
	calculator/Calculator.cpp 
	scientificcalculator/ScientificCalculator.cpp
	logarithm/Logarithm.cpp
	trigonometry/Trigonometry.cpp
)

