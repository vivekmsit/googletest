#pragma once

#include <iostream>

#include <IWindow.hpp>
#include <IDoor.hpp>
#include <ITyre.hpp>

class ICar {
public:
	virtual void drive() = 0;
	virtual void addWindow(IWindow *window) = 0;
	virtual void addDoor(IDoor *door) = 0;
	virtual void addTyre(ITyre *tyre) = 0;
};
