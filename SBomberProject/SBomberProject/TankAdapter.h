#pragma once

#include <stdint.h>
#include "TankAdaptee.h"
#include "DestroyableGroundObject.h"

class TankAdapter : public DestroyableGroundObject
{
public:
	bool __fastcall isInside(double x1, double x2) const override;

	uint16_t GetScore() const override;

	void Draw() const override ;

	void SetPos(double nx, double ny);

	double GetY() const;
	double GetX() const;

	void SetWidth(uint16_t widthN);
	uint16_t GetWidth() const;
private:
	mutable TankAdaptee tank;
	const uint16_t score = 30;
};
