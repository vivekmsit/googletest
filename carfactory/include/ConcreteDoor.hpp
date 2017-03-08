#pragma once

#include <IDoor.hpp>

class ConcreteDoor: public IDoor {
public:
	ConcreteDoor();
	virtual void open();
	virtual void close();
};
