#include <ConcreteTyreFactory.hpp>
#include <ConcreteTyre.hpp>

ConcreteTyreFactory::ConcreteTyreFactory() {
	std::cout<<"ConcreteTyreFactory::ConcreteTyreFactory()\n";
}

ITyre *ConcreteTyreFactory::createTyre(std::string brandName, std::string tyreType) {
	std::cout<<"ConcreteTyreFactory::createTyre()\n";
	ITyre *tyre = new ConcreteTyre();
	return tyre;
}
