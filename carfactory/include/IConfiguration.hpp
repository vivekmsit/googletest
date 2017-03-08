#pragma once

#include <iostream>

class IConfiguration {
public:
	virtual std::string getWindowBrandName() = 0;
	virtual std::string getWindowType() = 0;

	virtual std::string getDoorBrandName() = 0;
	virtual std::string getDoorType() = 0;

	virtual std::string getTyreBrandName() = 0;
	virtual std::string getTyreType() = 0;
};
