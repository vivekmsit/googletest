#include <ConcreteDoorFactory.hpp>
#include <ConcreteDoor.hpp>

ConcreteDoorFactory::ConcreteDoorFactory() {
	std::cout<<"ConcreteDoorFactory::ConcreteDoorFactory()\n";
}

IDoor *ConcreteDoorFactory::createDoor(std::string brandName, std::string doorType) {
	std::cout<<"ConcreteDoorFactory::createDoor()\n";
	IDoor *door = new ConcreteDoor();
	return door;
}
