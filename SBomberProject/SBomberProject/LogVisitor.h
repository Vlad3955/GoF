#pragma once
#include "Visitor.h"
class LogVisitor :
    public Visitor
{
public:
	void log(Bomb* pBomb) override;
	void log(const Plane* pPlane) override;
private:

};

