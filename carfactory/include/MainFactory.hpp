#pragma once

#include <iostream>
#include <IFactory.hpp>
#include <IWindowFactory.hpp>
#include <IDoorFactory.hpp>
#include <ITyreFactory.hpp>


class MainFactory: public IFactory {

public:
static IFactory *getInstance();
void createFactories();
void deleteFactories();
IBase *getObjHandler(std::string objName);
std::string getName() { return "MainFactory"; }

private:
IWindowFactory *pWindowFactory;
IDoorFactory *pDoorFactory;
ITyreFactory *pTyreFactory;

};
