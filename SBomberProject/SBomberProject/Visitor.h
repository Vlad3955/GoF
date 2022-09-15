#pragma once
#include <iostream>
#include "DynamicObject.h"
#include "Bomb.h"
#include "Plane.h"




class Visitor
{
public:
	virtual void log(Bomb* pBomb) = 0;
	virtual void log(Plane* pPlane) = 0;
};

