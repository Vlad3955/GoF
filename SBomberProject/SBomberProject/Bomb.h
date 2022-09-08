#pragma once

#include "DynamicObject.h"
#include "Visitor.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����
	void __fastcall Accept(const Visitor& v);
	void Draw() const override;

private:

};

