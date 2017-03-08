#pragma once

#include <IWindowFactory.hpp>
#include <IWindow.hpp>

class ConcreteWindowFactory: public IWindowFactory {
public:
	ConcreteWindowFactory();
	virtual IWindow *createWindow(std::string brandName, std::string windowType);
	std::string getName() { return "ConcreteWindowFactory"; }
};
