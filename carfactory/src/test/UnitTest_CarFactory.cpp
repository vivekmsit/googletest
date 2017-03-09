#include <MainFactory_Stub.hpp>
#include <CarAssembleFactory.hpp>
#include <WindowFactory_Mock.hpp>
#include <DoorFactory_Mock.hpp>
#include <TyreFactory_Mock.hpp>
#include <ConcreteCar.hpp>
#include <Configuration_Stub.hpp>
#include <Car_Mock.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

class CarAssembleFactoryTest: public ::testing::Test {
public:

CarAssembleFactoryTest() {

}

void SetUp() {
	mainFactory = MainFactory_Stub::getInstance();
	mainFactory->createFactories();
	windowFactory = dynamic_cast<WindowFactory_Mock *>(mainFactory->getObjHandler("WindowFactory"));
        doorFactory = dynamic_cast<DoorFactory_Mock *>(mainFactory->getObjHandler("DoorFactory"));
        tyreFactory = dynamic_cast<TyreFactory_Mock *>(mainFactory->getObjHandler("TyreFactory"));
}

void TearDown() {
	delete windowFactory;
        delete doorFactory;
        delete tyreFactory;
}

~CarAssembleFactoryTest() {

}

IFactory *mainFactory;

WindowFactory_Mock *windowFactory;
DoorFactory_Mock *doorFactory;
TyreFactory_Mock *tyreFactory;

};


TEST_F(CarAssembleFactoryTest, assembleCar) {
	CarAssembleFactory carAssembleFactory(mainFactory);

	EXPECT_CALL(*windowFactory, createWindow(_, _)).Times(2);
	EXPECT_CALL(*doorFactory, createDoor(_, _)).Times(2);
	EXPECT_CALL(*tyreFactory, createTyre(_, _)).Times(4);

	ICar *car = new ConcreteCar();
	carAssembleFactory.assembleCar(car, "wbname", "wtype", "dbname", "dtype", "tbname", "ttype");
}

TEST_F(CarAssembleFactoryTest, assembleCarUsingConfiguration) {
	CarAssembleFactory carAssembleFactory(mainFactory);
	ICar *car = new ConcreteCar();
	//Car_Mock *car = new Car_Mock();

	EXPECT_CALL(*windowFactory, createWindow(_, _)).Times(2);
        EXPECT_CALL(*doorFactory, createDoor(_, _)).Times(2);
        EXPECT_CALL(*tyreFactory, createTyre(_, _)).Times(4);

	EXPECT_CALL(*(ConfigurationMockDelegatee::getInstance()), getWindowBrandName()).Times(2);
	EXPECT_CALL(*(ConfigurationMockDelegatee::getInstance()), getWindowType()).Times(2);
	EXPECT_CALL(*(ConfigurationMockDelegatee::getInstance()), getDoorBrandName()).Times(2);
	EXPECT_CALL(*(ConfigurationMockDelegatee::getInstance()), getDoorType()).Times(2);
	EXPECT_CALL(*(ConfigurationMockDelegatee::getInstance()), getTyreBrandName()).Times(4);
	EXPECT_CALL(*(ConfigurationMockDelegatee::getInstance()), getTyreType()).Times(4);

	/*EXPECT_CALL(*car, addWindow(_)).Times(2);
	EXPECT_CALL(*car, addDoor(_)).Times(2);
	EXPECT_CALL(*car, addTyre(_)).Times(4);*/

	carAssembleFactory.assembleCarUsingConfiguration(car, "file.config");
	delete car;
}

