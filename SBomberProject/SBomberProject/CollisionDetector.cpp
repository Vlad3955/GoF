#include "CollisionDetector.h"


CollisionDetector::CollisionDetector() : 
    _pBomb(nullptr), _pPlane(nullptr), _pLevelGUI(nullptr), _pGround(nullptr), _score(0) {};

bool CollisionDetector::CheckPlaneAndLevelGUI(Plane* pPlane, LevelGUI* pLevelGUI)
{
    _pPlane = pPlane;
    _pLevelGUI = pLevelGUI;
    if (_pPlane->GetX() > _pLevelGUI->GetFinishX())
    {
        return true;
    }
    return false;
}


Bomb* CollisionDetector::CheckBombsAndGround(const std::vector<Bomb*>& vecBomb, Ground* pGround, 
    const std::vector<DestroyableGroundObject*>& vecDestoyableObjects, int16_t &score)
{
    _vecBomb = vecBomb;
    _pGround = pGround;
    const double y = _pGround->GetY();
    for (size_t i = 0; i < _vecBomb.size(); i++)
    {
        if (_vecBomb[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(_vecBomb[i]->GetX());
            CheckDestoyableObjects(_vecBomb[i], vecDestoyableObjects, score);
            return _vecBomb[i];
        }
    }
    return nullptr;
}

DestroyableGroundObject* CollisionDetector::CheckDestoyableObjects(Bomb* pBomb, 
    const std::vector<DestroyableGroundObject*>& vecDestoyableObjects, int16_t &score)
{
    _score = score;
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
            _score += _vecDestoyableObjects[i]->GetScore();
            return _vecDestoyableObjects[i];
        }
    }
    return nullptr;
}

CollisionDetector::~CollisionDetector() {}