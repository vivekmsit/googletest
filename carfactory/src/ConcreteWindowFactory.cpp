#include <ConcreteWindowFactory.hpp>
#include <ConcreteWindow.hpp>


ConcreteWindowFactory::ConcreteWindowFactory() {
	std::cout<<"ConcreteWindowFactory::ConcreteWindowFactory()\n";
}


IWindow *ConcreteWindowFactory::createWindow(std::string brandName, std::string windowType) {
	std::cout<<"ConcreteWindowFactory::createWindow()\n";
	IWindow *window = new ConcreteWindow();
	return window;
}
