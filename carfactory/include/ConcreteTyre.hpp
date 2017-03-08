#pragma once

#include <ITyre.hpp>

class ConcreteTyre: public ITyre {
public:
	ConcreteTyre();
	virtual void run();
};
