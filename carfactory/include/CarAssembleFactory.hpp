#pragma once

#include <iostream>
#include <ICarAssembleFactory.hpp>

#include <IWindowFactory.hpp>
#include <IDoorFactory.hpp>
#include <ITyreFactory.hpp>

#include <IFactory.hpp>
#include <ICar.hpp>

using namespace std;

class CarAssembleFactory : public ICarAssembleFactory {
public:
	CarAssembleFactory(IFactory *factoryRef);
	virtual void assembleCar(ICar *car, std::string windowBrandName, std::string windowType, std::string doorBrandName, std::string doorType, std::string tyreBrandName, std::string tyreType);
	virtual void assembleCarUsingConfiguration(ICar *car, std::string configFilePath);
private:
IFactory *factoryReference;

IWindowFactory *pWindowFactory;
IDoorFactory *pDoorFactory;
ITyreFactory *pTyreFactory;
};
