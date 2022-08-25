#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

private:

};


//BombDecorator
//====================================================
class BombDecorator : public DynamicObject
{
public:
	BombDecorator();
	void Move(uint16_t time) override;
	void Draw() const override;
	void SetPos(double nx, double ny);

	double GetY() const;
	double GetX() const;

	void SetWidth(uint16_t widthN);
	uint16_t GetWidth() const;
	~BombDecorator();
private:
	Bomb* _bomb;
};
//====================================================


