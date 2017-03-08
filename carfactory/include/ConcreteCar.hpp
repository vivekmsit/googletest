#pragma once

#include <ICar.hpp>
#include <IWindow.hpp>
#include <IDoor.hpp>
#include <ITyre.hpp>

class ConcreteCar: public ICar {
public:
	ConcreteCar();
	virtual void drive();
	virtual void addWindow(IWindow *window);
	virtual void addDoor(IDoor *door);
	virtual void addTyre(ITyre *tyre);
};
