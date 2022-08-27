#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SbomberCommand
{
public:
    virtual void execute() = 0;
    virtual ~SbomberCommand() {};
protected:
    
};

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void CommandExecuter(SbomberCommand* pCommand);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    SbomberCommand* pCommand;
    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};
//====================================================================

// Command
//====================================================================
class DeleteDynamicObjCommand : public SbomberCommand
{
public:
    DeleteDynamicObjCommand(DynamicObject* pDynObj, std::vector<DynamicObject*>& vec);
    void execute() override;
    ~DeleteDynamicObjCommand();
private:
    DynamicObject* _pDynObj;
    std::vector<DynamicObject*>& _vec;
};

class DeleteStaticObjCommand : public SbomberCommand
{
public:
    DeleteStaticObjCommand(GameObject* pObj, std::vector<GameObject*>& vecStatic);
    void execute() override;
    ~DeleteStaticObjCommand();
private:
    GameObject* _pObj;
    std::vector<GameObject*>& _vecStatic;
};

class DropBombCommand : public SbomberCommand
{
public:
    DropBombCommand(const Plane* plane, std::vector<DynamicObject*>& vec, uint16_t* numBombs, int16_t* score);
    void execute() override;
    ~DropBombCommand();
private:
    const Plane* _plane;
    std::vector<DynamicObject*>& _vec;
    uint16_t *_numBombs;
    int16_t *_score;
};

class DropBombDecoratorCommand : public SbomberCommand
{
public:
    DropBombDecoratorCommand(const Plane* plane, std::vector<DynamicObject*>& vec, uint16_t* numBombs, int16_t* score);
    void execute() override;
    ~DropBombDecoratorCommand();
private:
    const Plane* _plane;
    std::vector<DynamicObject*>& _vec;
    uint16_t* _numBombs;
    int16_t* _score;
};
//====================================================================
