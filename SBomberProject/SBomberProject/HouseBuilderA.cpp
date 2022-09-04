#include "HouseBuilderA.h"
#include <cstring>


HouseBuilderA::HouseBuilderA()
{
	
}

void HouseBuilderA::buildChimney()
{
	strcpy_s(pHouse->look[0], "");
}

void HouseBuilderA::buildRoofl2()
{
	strcpy_s(pHouse->look[1], "  ########  ");
}

void HouseBuilderA::buildRoofl1()
{
	strcpy_s(pHouse->look[2], "##        ##");
}

void HouseBuilderA::buildCeil()
{
	strcpy_s(pHouse->look[3], "############");
}

void HouseBuilderA::buildWall1()
{
	strcpy_s(pHouse->look[4], "#          #");
}

void HouseBuilderA::buildWall2()
{
	strcpy_s(pHouse->look[5], "#          #");
}

void HouseBuilderA::buildFloor()
{
	strcpy_s(pHouse->look[6], "############");
}









HouseBuilderA::~HouseBuilderA()
{
}