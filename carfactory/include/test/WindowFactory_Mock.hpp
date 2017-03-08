#pragma once

#include <IWindowFactory.hpp>
#include <IWindow.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class WindowFactory_Mock: public IWindowFactory {
public:
	WindowFactory_Mock(){}
	~WindowFactory_Mock(){}
	std::string getName() { return "WindowFactory_Mock"; }
	MOCK_METHOD2(createWindow, IWindow *(std::string, std::string));
};
