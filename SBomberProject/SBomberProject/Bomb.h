#pragma once
#include <vector>
#include "DynamicObject.h"
#include "DestroyableGroundObject.h"


class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках
	void Accept(Visitor& v) override;
	void Draw() const override;
	void addObserver(DestroyableGroundObject* obs);

private:
	std::vector<DestroyableGroundObject*> _observers;
};

