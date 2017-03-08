#pragma once

#include <iostream>
#include <string>

#include <IConfiguration.hpp>

class Configuration: public IConfiguration {
public:
	Configuration(std::string configFilePath);

	virtual std::string getWindowBrandName();
	virtual std::string getWindowType();

	virtual std::string getDoorBrandName();
	virtual std::string getDoorType();

	virtual std::string getTyreBrandName();
	virtual std::string getTyreType();
};
