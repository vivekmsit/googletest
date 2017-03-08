#pragma once

#include <IDoorFactory.hpp>
#include <IDoor.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class DoorFactory_Mock: public IDoorFactory {
public:
	DoorFactory_Mock(){}
	virtual ~DoorFactory_Mock(){}
	std::string getName() { return "DoorFactory_Mock"; }
	MOCK_METHOD2(createDoor, IDoor *(std::string, std::string));
};
