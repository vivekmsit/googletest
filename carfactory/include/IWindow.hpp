#pragma once

#include <iostream>

class IWindow {
public:
	virtual void open() = 0;
	virtual void close() = 0;
};
