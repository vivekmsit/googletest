#pragma once

#include <iostream>
#include <IBase.hpp>

using namespace std;


class IFactory: public IBase {
public: 

virtual void createFactories() = 0;
virtual void deleteFactories() = 0;
virtual IBase *getObjHandler(std::string objName) = 0;

};
