#pragma once

#include <stdint.h>
#include "Mediator.h"
#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:
	static Mediator* med;
	const uint16_t score = 30;
};

