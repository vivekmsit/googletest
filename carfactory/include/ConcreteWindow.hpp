#pragma once

#include <IWindow.hpp>

class ConcreteWindow: public IWindow {
public:
	ConcreteWindow();
	virtual void open();
	virtual void close();
};
