#pragma once

#include <IFactory.hpp>

#include <IWindowFactory.hpp>
#include <IDoorFactory.hpp>
#include <ITyreFactory.hpp>

#include <WindowFactory_Mock.hpp>
#include <DoorFactory_Mock.hpp>
#include <TyreFactory_Mock.hpp>

#include "gmock/gmock.h"

class MainFactory_Stub: public IFactory {
public:

static IFactory *getInstance(){
	static MainFactory_Stub instance;
	return &instance;
}

void createFactories() {

	pWindowFactory = new WindowFactory_Mock();
	pDoorFactory = new DoorFactory_Mock();
	pTyreFactory = new TyreFactory_Mock();
}

void deleteFactories() {
	delete pWindowFactory;
	delete pDoorFactory;
	delete pTyreFactory;
}

IBase *getObjHandler(std::string objName) {
	if (objName == "WindowFactory")
		return pWindowFactory;
	else if (objName == "DoorFactory") 
		return pDoorFactory;
	else if (objName == "TyreFactory") 
		return pTyreFactory;
	else 
		return NULL;
}

std::string getName() { return "MainFactory_Stub"; }

private:

IWindowFactory *pWindowFactory;
IDoorFactory *pDoorFactory;
ITyreFactory *pTyreFactory;

};
