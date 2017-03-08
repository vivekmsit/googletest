#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class ConfigurationMockDelegatee {
private:

	ConfigurationMockDelegatee(){}
public:
	static ConfigurationMockDelegatee *getInstance() {
		static ConfigurationMockDelegatee delegatee;
		return &delegatee;
	}
	
	MOCK_METHOD0(getWindowBrandName, std::string ());
	MOCK_METHOD0(getWindowType, std::string ());
	MOCK_METHOD0(getDoorBrandName, std::string ());
	MOCK_METHOD0(getDoorType, std::string ());
	MOCK_METHOD0(getTyreBrandName, std::string ());
	MOCK_METHOD0(getTyreType, std::string ());
};
