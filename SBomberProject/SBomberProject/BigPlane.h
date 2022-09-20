#pragma once
#include "Plane.h"


class BigPlane : public Plane
{
public:
	BigPlane();
	void DrawBody() const override;
	void DrawWings() const override;
	void DrawTail() const override;
	~BigPlane();
private:

};


