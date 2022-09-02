#pragma once

#include <stdint.h>
#include "HouseBuilderA.h"

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:
	//HouseBuilderA* a;
	//char look[7][14];

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 40;
};

