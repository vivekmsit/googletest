#pragma once

#include <iostream>

class IDoor{
public:
	virtual void open() = 0;
	virtual void close() = 0;
};
