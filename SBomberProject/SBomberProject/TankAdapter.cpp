#include <stdint.h>
#include "TankAdapter.h"

bool __fastcall TankAdapter::isInside(double x1, double x2) const
{
	return tank.isInRange(x1, x2);
}
 uint16_t TankAdapter::GetScore() const
{ 
	return tank.GetScore(); 
}

void TankAdapter::Draw() const 
{
	 tank.Paint();
}

void TankAdapter::SetPos(double nx, double ny) 
{
	tank.SetPos(nx, ny);
}

double TankAdapter::GetY() const 
{ 
	return tank.GetY(); 
}

double TankAdapter::GetX() const 
{ 
	return tank.GetX(); 
}

void TankAdapter::SetWidth(uint16_t widthN) 
{ 
	tank.SetWidth(widthN);
}
uint16_t TankAdapter::GetWidth() const 
{ 
	return tank.GetWidth(); 
}