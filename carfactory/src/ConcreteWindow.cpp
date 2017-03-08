#include <ConcreteWindow.hpp>

ConcreteWindow::ConcreteWindow() {
	std::cout<<"ConcreteWindow::ConcreteWindow()\n";
}

void ConcreteWindow::open() {
	std::cout<<"ConcreteWindow::open()\n";
}

void ConcreteWindow::close() {
	std::cout<<"ConcreteWindow::close()\n";
}
