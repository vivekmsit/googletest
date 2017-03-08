#pragma once

#include <IBase.hpp>
#include <IDoor.hpp>

class IDoorFactory: public IBase {
public:
        virtual IDoor *createDoor(std::string brandName, std::string doorType) = 0;
};

