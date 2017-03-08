#pragma once

#include <IBase.hpp>
#include <IWindow.hpp>

class IWindowFactory: public IBase {
public:
	virtual IWindow *createWindow(std::string brandName, std::string windowType) = 0;
};
