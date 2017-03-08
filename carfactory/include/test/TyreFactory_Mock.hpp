#pragma once

#include <ITyreFactory.hpp>
#include <ITyre.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class TyreFactory_Mock: public ITyreFactory {
public:
	TyreFactory_Mock(){}
	virtual ~TyreFactory_Mock(){}
	std::string getName() { return "TyreFactory_Mock"; }
	MOCK_METHOD2(createTyre, ITyre *(std::string, std::string));
};
