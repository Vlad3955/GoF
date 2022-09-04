#pragma once
#include <iostream>
#include <stdint.h>
#include "House.h"

class HouseBuilder
{
public:
	virtual char buildFloor() = 0;
	virtual void buildWall1() = 0;
	virtual void buildRoofl1() = 0;
	virtual ~HouseBuilder() {};
protected:
	House* pHouse = nullptr;
};

