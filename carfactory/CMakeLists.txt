cmake_minimum_required(VERSION 2.8)

project(CarFactoryUnitTest C CXX)

include_directories("include")
include_directories("include/test")

add_executable(main src/Configuration.cpp src/ConcreteCar.cpp src/CarAssembleFactory.cpp src/MainFactory.cpp src/ConcreteWindow.cpp src/ConcreteDoor.cpp src/ConcreteTyre.cpp src/ConcreteWindowFactory.cpp src/ConcreteDoorFactory.cpp src/ConcreteTyreFactory.cpp src/main.cpp )

add_executable(carassemblefactory_test src/ConcreteCar.cpp src/CarAssembleFactory.cpp src/test/UnitTest_CarFactory.cpp)

target_link_libraries(carassemblefactory_test gtest_main gmock_main gtest gmock pthread)

