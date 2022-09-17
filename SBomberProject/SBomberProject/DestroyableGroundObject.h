#pragma once

#include <stdint.h>
#include "Mediator.h"
#include "GameObject.h"

class Mediator;

class DestroyableGroundObject : public GameObject
{
public:

    virtual bool __fastcall isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

protected:
    static Mediator* med;
};