#pragma once
#include <iostream>
#include "HouseBuilder.h"
#include "House.h"


class HouseBuilderA : public HouseBuilder
{
public:
	HouseBuilderA();
	void buildChimney();

	void buildRoofl2();
	void buildRoofl1() override;
	void buildCeil();
	void buildWall1();
	void buildWall2();

	void buildWallSmallW1() override;
	void buildWallSmallW2();
	
	void buildWallBigW1();
	void buildWallBigW2();

	void buildFloor() override;
	~HouseBuilderA();
private:
	
};


