#pragma once
#include <iostream>
#include "Visitor.h"
#include <string>
#include "MyTools.h"
#include "Bomb.h"
#include "Plane.h"


class LogVisitor : public Visitor
{
public:
	LogVisitor();

	virtual void log(Bomb* pBomb) override;
	virtual void log(Plane* pPlane) override;
	~LogVisitor();
private:

};