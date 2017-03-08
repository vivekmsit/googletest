#pragma once

#include <iostream>
#include <string>

#include <ICar.hpp>

class ICarAssembleFactory {
public:
	virtual void assembleCar(ICar *car, std::string windowBrandName, std::string windowType, std::string doorBrandName, std::string doorType, std::string tyreBrandName, std::string tyreType) = 0;
	virtual void assembleCarUsingConfiguration(ICar *car, std::string configFilePath) = 0;
};
