#pragma once

#include <iostream>
#include <ITyreFactory.hpp>

class ConcreteTyreFactory: public ITyreFactory {
public:
	ConcreteTyreFactory();
	virtual ITyre *createTyre(std::string brandName, std::string tyreType);
	std::string getName() { return "ConcreTyreFactory"; }
};
