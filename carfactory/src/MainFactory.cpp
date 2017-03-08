#include <MainFactory.hpp>
#include <ConcreteWindowFactory.hpp>
#include <ConcreteDoorFactory.hpp>
#include <ConcreteTyreFactory.hpp>

IFactory *MainFactory::getInstance() {
	static MainFactory mainFactory;
	return &mainFactory;
}

void MainFactory::createFactories() {

	std::cout<<"MainFactory::MainFactory()\n";

	pWindowFactory = new ConcreteWindowFactory();
	pDoorFactory = new ConcreteDoorFactory();
	pTyreFactory = new ConcreteTyreFactory();
}

void MainFactory::deleteFactories() {
	delete pWindowFactory;
	delete pDoorFactory;
	delete pTyreFactory;
}

IBase *MainFactory::getObjHandler(std::string objName) {

	if (objName == "WindowFactory") 
		return pWindowFactory;
	else if (objName == "DoorFactory")
		return pDoorFactory;
	else if (objName == "TyreFactory")
		return pTyreFactory;
	else
		return NULL;

}
