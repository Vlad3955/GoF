#pragma once

#include <iostream>

#include "Bomb.h"
#include "Plane.h"


class Visitor
{
public:
	virtual void log(Bomb* pBomb) = 0;
	virtual void log(const Plane* pPlane) = 0;
	virtual ~Visitor() {};
private:

};
