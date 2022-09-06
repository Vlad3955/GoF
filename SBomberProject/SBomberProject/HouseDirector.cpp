#include "HouseDirector.h"


HouseDirector::HouseDirector(HouseBuilderA& _hbA) : hbA(_hbA)
{
}

void HouseDirector::constructWithCHimney()
{
    hbA.buildChimney();
    hbA.buildCeil();
    hbA.buildFloor();
    hbA.buildWall1();
    hbA.buildWall2();
    hbA.buildRoofl1();
    hbA.buildRoofl2();
}
void HouseDirector::constructWithoutCHimney()
{
    hbA.buildCeil();
    hbA.buildFloor();
    hbA.buildWall1();
    hbA.buildWall2();
    hbA.buildRoofl1();
    hbA.buildRoofl2();
}
void HouseDirector::constructBigWindow()
{
    hbA.buildCeil();
    hbA.buildFloor();
    hbA.buildWallBigW1();
    hbA.buildWallBigW2();
    hbA.buildRoofl1();
    hbA.buildRoofl2();
}
void HouseDirector::constructSmallWindow()
{
    hbA.buildCeil();
    hbA.buildFloor();
    hbA.buildWallSmallW1();
    hbA.buildWallSmallW2();
    hbA.buildRoofl1();
    hbA.buildRoofl2();
}

HouseDirector::~HouseDirector()
{
}