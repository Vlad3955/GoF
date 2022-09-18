#pragma once

#include <stdint.h>
#include <string>
#include "Mediator.h"
#include "DestroyableGroundObject.h"

class Mediator;

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void BeNotified(std::string& mes) const;

	void Draw() const override;

	//static Mediator* med;

private:
	
	const uint16_t score = 30;
};

