#pragma once

#include <ICar.hpp>
#include <IWindow.hpp>
#include <IDoor.hpp>
#include <ITyre.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class Car_Mock: public ICar {
public:
	Car_Mock(){}
	virtual ~Car_Mock(){}

	MOCK_METHOD0(drive, void());
	MOCK_METHOD1(addWindow, void(IWindow *));
	MOCK_METHOD1(addDoor, void(IDoor *));
	MOCK_METHOD1(addTyre, void(ITyre *));
};
