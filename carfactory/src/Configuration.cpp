#include <Configuration.hpp>

Configuration::Configuration(std::string configFilePath) {
	//std::cout<<"Configuration::Configuration()\n";
}

std::string Configuration::getWindowBrandName() {
	return "WindowBrandName";
}

std::string Configuration::getWindowType() {
	return "WindowType";
}

std::string Configuration::getDoorBrandName() {
	return "DoorBrandName";
}

std::string Configuration::getDoorType() {
	return "DoorType";
}

std::string Configuration::getTyreBrandName() {
	return "TyreBrandName";
}

std::string Configuration::getTyreType() {
	return "TyreType";
}
