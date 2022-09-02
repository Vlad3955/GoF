#include "HouseBuilderA.h"

HouseBuilderA::HouseBuilderA()
{
}

char HouseBuilderA::buildChimney()
{
	char ch[14] = "";
	return ch[14];
}

char HouseBuilderA::buildFloorCeil()
{
	char ch[14] = "############";
	return ch[14];
}

char HouseBuilderA::buildWalls()
{
	char ch[14] = "#          #";
	return ch[14];
}


char HouseBuilderA::buildRoofl1()
{
	char ch[14] = "##        ##";
	return ch[14];
}

char HouseBuilderA::buildRoofl2()
{
	char ch[14] = "  ########  ";
	return ch[14];
}

char* HouseBuilderA::GetResult()
{
	char bhLook[7][14] = {
		{buildChimney()},
		{buildRoofl2()},
		{buildRoofl1()},
		{buildFloorCeil()},
		{buildWalls()},
		{buildWalls()},
		{buildFloorCeil()}
	};

	/*for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			pHouse->look[i][j] = bhLook[i][j];
		}
	}*/

	

	return *bhLook;
}

HouseBuilderA::~HouseBuilderA()
{
}