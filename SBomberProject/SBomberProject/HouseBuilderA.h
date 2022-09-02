#pragma once
#include <iostream>
#include "HouseBuilder.h"
#include "House.h"

class HouseBuilderA : public HouseBuilder
{
public:
	HouseBuilderA();
	virtual char buildFloorCeil() override;
	virtual char buildWalls() override;
	virtual char buildRoofl1() override;
	char buildRoofl2();
	char buildChimney();
	char* GetResult();
	~HouseBuilderA();
private:
	//House pHouse;
};


