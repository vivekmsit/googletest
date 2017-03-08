#include <iostream>

#include <CarAssembleFactory.hpp>
#include <IFactory.hpp>
#include <ConcreteCar.hpp>
#include <Configuration.hpp>

using namespace std;

CarAssembleFactory::CarAssembleFactory(IFactory *factoryRef): factoryReference(factoryRef) {

	//std::cout<<"CarAssembleFactory::CarFactory()\n";
	
	pWindowFactory = dynamic_cast<IWindowFactory *>(factoryReference->getObjHandler("WindowFactory"));
	pDoorFactory = dynamic_cast<IDoorFactory *>(factoryReference->getObjHandler("DoorFactory"));
	pTyreFactory = dynamic_cast<ITyreFactory *>(factoryReference->getObjHandler("TyreFactory"));
}


void CarAssembleFactory::assembleCar(ICar *car, std::string windowBrandName, std::string windowType, std::string doorBrandName, std::string doorType, std::string tyreBrandName, std::string tyreType) {
	//std::cout<<"CarAssembleFactory::assembleCar()\n";

	car->addWindow(pWindowFactory->createWindow(windowBrandName, windowType));
	car->addWindow(pWindowFactory->createWindow(windowBrandName, windowType));

	car->addDoor(pDoorFactory->createDoor(doorBrandName, doorType));
	car->addDoor(pDoorFactory->createDoor(doorBrandName, doorType));

	car->addTyre(pTyreFactory->createTyre(tyreBrandName, tyreType));
	car->addTyre(pTyreFactory->createTyre(tyreBrandName, tyreType));
	car->addTyre(pTyreFactory->createTyre(tyreBrandName, tyreType));
	car->addTyre(pTyreFactory->createTyre(tyreBrandName, tyreType));
}

void CarAssembleFactory::assembleCarUsingConfiguration(ICar *car, std::string configFilePath) {
	//std::cout<<"CarAssembleFactory::assembleCarUsingConfiguration()\n";
	Configuration config(configFilePath);
	
	car->addWindow(pWindowFactory->createWindow(config.getWindowBrandName(), config.getWindowType()));
        car->addWindow(pWindowFactory->createWindow(config.getWindowBrandName(), config.getWindowType()));

        car->addDoor(pDoorFactory->createDoor(config.getDoorBrandName(), config.getDoorType()));
        car->addDoor(pDoorFactory->createDoor(config.getDoorBrandName(), config.getDoorType()));

        car->addTyre(pTyreFactory->createTyre(config.getTyreBrandName(), config.getTyreType()));
        car->addTyre(pTyreFactory->createTyre(config.getTyreBrandName(), config.getTyreType()));
        car->addTyre(pTyreFactory->createTyre(config.getTyreBrandName(), config.getTyreType()));
        car->addTyre(pTyreFactory->createTyre(config.getTyreBrandName(), config.getTyreType()));
}
