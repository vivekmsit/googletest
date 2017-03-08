#include <Configuration.hpp>
#include <ConfigurationMockDelegatee.hpp>

Configuration::Configuration(std::string configFilePath) {
	//std::cout<<"Configuration::Configuration()\n";
}

std::string Configuration::getWindowBrandName() {
	return ConfigurationMockDelegatee::getInstance()->getWindowBrandName();
}

std::string Configuration::getWindowType() {
	return ConfigurationMockDelegatee::getInstance()->getWindowType();
}

std::string Configuration::getDoorBrandName() {
	return ConfigurationMockDelegatee::getInstance()->getDoorBrandName();
}

std::string Configuration::getDoorType() {
	return ConfigurationMockDelegatee::getInstance()->getDoorType();
}

std::string Configuration::getTyreBrandName() {
	return ConfigurationMockDelegatee::getInstance()->getTyreBrandName();
}

std::string Configuration::getTyreType() {
	return ConfigurationMockDelegatee::getInstance()->getTyreType();
}
