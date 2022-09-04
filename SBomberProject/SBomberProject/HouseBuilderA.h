#pragma once
#include <iostream>
#include "HouseBuilder.h"
#include "House.h"


class HouseBuilderA : public HouseBuilder
{
public:
	HouseBuilderA();
	char buildFloor() override;
	void buildWall1() override;
	void buildRoofl1() override;
	void buildCeil();
	void buildWall2();
	void buildRoofl2();
	void buildChimney();
	~HouseBuilderA();
private:
	
};


