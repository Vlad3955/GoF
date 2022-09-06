#include "CollisionDetector.h"


CollisionDetector::CollisionDetector(Bomb* pBomb, Plane* pPlane, LevelGUI* pLevelGUI, Ground* pGround, 
    std::vector<Bomb*>& vecBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects, bool flag) //:
    //_pBomb(pBomb), _pPlane(pPlane), _pLevelGUI(pLevelGUI), _pGround(pGround), _vecBomb(vecBomb),
   //_vecDestoyableObjects(vecDestoyableObjects), _flag(flag)
{
    CheckPlaneAndLevelGUI(pPlane, pLevelGUI, flag);
    CheckBombsAndGround(vecBomb, pGround, vecDestoyableObjects);
    CheckDestoyableObjects(pBomb, vecDestoyableObjects);
}

void CollisionDetector::CheckPlaneAndLevelGUI(Plane* pPlane, LevelGUI* pLevelGUI, bool flag)
{
    _pPlane = pPlane;
    _pLevelGUI = pLevelGUI;
    _flag = flag;
    if (_pPlane->GetX() > _pLevelGUI->GetFinishX())
    {
        _flag = true;
    }
}

void CollisionDetector::CheckBombsAndGround(std::vector<Bomb*>& vecBomb, Ground* pGround, std::vector<DestroyableGroundObject*>& vecDestoyableObjects)
{
    _vecBomb = vecBomb;
    _pGround = pGround;
    const double y = _pGround->GetY();
    for (size_t i = 0; i < _vecBomb.size(); i++)
    {
        if (_vecBomb[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(_vecBomb[i]->GetX());
            CheckDestoyableObjects(_vecBomb[i], vecDestoyableObjects);
            DeleteDynamicObj(vecBombs[i]);
        }
    }

}

void CollisionDetector::CheckDestoyableObjects(Bomb* pBomb, std::vector<DestroyableGroundObject*>& vecDestoyableObjects)
{
    _pBomb = pBomb;
    _vecDestoyableObjects = vecDestoyableObjects;
    const double size = _pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < _vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (_vecDestoyableObjects[i]->isInside(x1, x2))
        {
            score += _vecDestoyableObjects[i]->GetScore();
            DeleteStaticObj(_vecDestoyableObjects[i]);
        }
    }
}

CollisionDetector::~CollisionDetector()
{
}