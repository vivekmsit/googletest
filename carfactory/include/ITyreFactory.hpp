#pragma once

#include <IBase.hpp>
#include <ITyre.hpp>

class ITyreFactory: public IBase {
public:
        virtual ITyre *createTyre(std::string brandName, std::string tyreType) = 0;
};

