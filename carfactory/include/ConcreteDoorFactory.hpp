#pragma once

#include <IDoorFactory.hpp>

class ConcreteDoorFactory: public IDoorFactory {
public:
	ConcreteDoorFactory();
	virtual IDoor *createDoor(std::string brandName, std::string doorType);
	std::string getName() { return "ConcreteDoorFactory"; }
};
