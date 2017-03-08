#include <iostream>
#include <MainFactory.hpp>
#include <CarAssembleFactory.hpp>
#include <ConcreteCar.hpp>

int main() {
	IFactory *factory = MainFactory::getInstance();
	factory->createFactories();
	ICarAssembleFactory *carAssembleFactory = new CarAssembleFactory(factory);
	ICar *car = new ConcreteCar();
	carAssembleFactory->assembleCar(car, "wbrand", "wtype", "dbrand", "dtype", "tbrand", "ttype");
	car->drive();
	factory->deleteFactories();
	return 0;
}
