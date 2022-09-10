#pragma once
#include <iostream>
#include <stdint.h>
#include "House.h"

class HouseBuilder
{
public:
	virtual void buildFloor() = 0;
	virtual void buildWallSmallW1() = 0;
	virtual void buildRoofl1() = 0;
	virtual ~HouseBuilder() {};
protected:
	House* pHouse;
};

