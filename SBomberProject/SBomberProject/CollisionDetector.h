#pragma once
#include <iostream>
#include <vector>
#include "Bomb.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "Ground.h"
#include "DestroyableGroundObject.h"

class CollisionDetector
{
public:
	CollisionDetector(Bomb* pBomb, Plane* pPlane, LevelGUI* pLevelGUI, Ground* pGround, 
        std::vector<Bomb*>& vecBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, bool flag);
    void CheckPlaneAndLevelGUI(Plane* pPlane, LevelGUI* pLevelGUI, bool flag);
    void CheckBombsAndGround(std::vector<Bomb*>& vecBomb, Ground* pGround, std::vector<DestroyableGroundObject*>& vecDestoyableObjects);
    void CheckDestoyableObjects(Bomb* pBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects);
	~CollisionDetector();
private:
    Bomb* _pBomb;
    Plane* _pPlane;
    LevelGUI* _pLevelGUI;
    Ground* _pGround;
    std::vector<Bomb*> _vecBomb;
    std::vector<DestroyableGroundObject*> _vecDestoyableObjects;
    bool _flag;
};


