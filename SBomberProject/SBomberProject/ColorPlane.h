#pragma once
#include "Plane.h"

class ColorPlane : public Plane
{
public:
	ColorPlane();
	void DrawBody() const override;
	void DrawWings() const override;
	void DrawTail() const override;
	~ColorPlane();
private:

};


