cmake_minimum_required(VERSION 2.8)

project(SampleUnitTest C CXX)

include_directories("include")
include_directories("include/test")

add_executable(carfactory_main src/Configuration.cpp src/ConcreteCar.cpp src/CarAssembleFactory.cpp src/MainFactory.cpp src/ConcreteWindow.cpp src/ConcreteDoor.cpp src/ConcreteTyre.cpp src/ConcreteWindowFactory.cpp src/ConcreteDoorFactory.cpp src/ConcreteTyreFactory.cpp src/main.cpp )

add_executable(carfactory_test src/ConcreteCar.cpp src/CarAssembleFactory.cpp src/test/UnitTest_CarFactory.cpp)

add_executable(sample_test src/sample.cpp src/test/unit_test_sample.cpp)

target_link_libraries(carfactory_test gtest_main gmock_main gtest gmock pthread)

target_link_libraries(sample_test gtest_main gmock_main gtest gmock pthread)
