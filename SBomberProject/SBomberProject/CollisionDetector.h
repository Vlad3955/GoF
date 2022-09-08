#pragma once
#include <iostream>
#include <functional>
#include <vector>

#include "Bomb.h"
#include "GameObject.h"
#include "DestroyableGroundObject.h"
#include "DynamicObject.h"
#include "Ground.h"
#include "LevelGUI.h"
#include "Plane.h"





class CollisionDetector
{
public:
    CollisionDetector();
    bool CheckPlaneAndLevelGUI(Plane* pPlane, LevelGUI* pLevelGUI);
    Bomb* CheckBombsAndGround(const std::vector<Bomb*>& vecBomb, Ground* pGround, const std::vector<DestroyableGroundObject*>& vecDestoyableObjects,
        int16_t &score);
    DestroyableGroundObject* CheckDestoyableObjects(Bomb* pBomb, const std::vector<DestroyableGroundObject*>& vecDestoyableObjects,
        int16_t &score);
	~CollisionDetector();
private:
    Bomb* _pBomb;
    Plane* _pPlane;
    LevelGUI* _pLevelGUI;
    Ground* _pGround;
    std::vector<Bomb*> _vecBomb;
    std::vector<DestroyableGroundObject*> _vecDestoyableObjects;
    int16_t _score;
};


