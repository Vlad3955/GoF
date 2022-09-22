
#include <conio.h>
#include <windows.h>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"

using namespace std;
using namespace MyTools;

class SBomberImpl
{
public:
    SBomberImpl()
        : exitFlag(false),
        startTime(0),
        finishTime(0),
        deltaTime(0),
        passedTime(0),
        fps(0),
        bombsNumber(10),
        score(0)
    {};
    void CheckPlaneAndLevelGUI()
    {
        if (FindPlane()->GetX() > FindLevelGUI()->GetFinishX())
        {
            exitFlag = true;
        }
    }

    void CheckBombsAndGround()
    {
        vector<Bomb*> vecBombs = FindAllBombs();
        Ground* pGround = FindGround();
        const double y = pGround->GetY();
        for (size_t i = 0; i < vecBombs.size(); i++)
        {
            if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
            {
                pGround->AddCrater(vecBombs[i]->GetX());
                CheckDestoyableObjects(vecBombs[i]);
                DeleteDynamicObj(vecBombs[i]);
            }
        }

    }

    void CheckDestoyableObjects(Bomb* pBomb)
    {
        vector<DestroyableGroundObject*> vecDestoyableObjects = FindDestoyableGroundObjects();
        const double size = pBomb->GetWidth();
        const double size_2 = size / 2;
        for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
        {
            const double x1 = pBomb->GetX() - size_2;
            const double x2 = x1 + size;
            if (vecDestoyableObjects[i]->isInside(x1, x2))
            {
                score += vecDestoyableObjects[i]->GetScore();
                DeleteStaticObj(vecDestoyableObjects[i]);
            }
        }
    }

    void DeleteDynamicObj(DynamicObject* pObj)
    {
        auto it = vecDynamicObj.begin();
        for (; it != vecDynamicObj.end(); it++)
        {
            if (*it == pObj)
            {
                vecDynamicObj.erase(it);
                break;
            }
        }
    }

    void DeleteStaticObj(GameObject* pObj)
    {
        auto it = vecStaticObj.begin();
        for (; it != vecStaticObj.end(); it++)
        {
            if (*it == pObj)
            {
                vecStaticObj.erase(it);
                break;
            }
        }
    }

    vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const
    {
        vector<DestroyableGroundObject*> vec;
        Tank* pTank;
        House* pHouse;
        for (size_t i = 0; i < vecStaticObj.size(); i++)
        {
            pTank = dynamic_cast<Tank*>(vecStaticObj[i]);
            if (pTank != nullptr)
            {
                vec.push_back(pTank);
                continue;
            }

            pHouse = dynamic_cast<House*>(vecStaticObj[i]);
            if (pHouse != nullptr)
            {
                vec.push_back(pHouse);
                continue;
            }
        }

        return vec;
    }

    Ground* FindGround() const
    {
        Ground* pGround;

        for (size_t i = 0; i < vecStaticObj.size(); i++)
        {
            pGround = dynamic_cast<Ground*>(vecStaticObj[i]);
            if (pGround != nullptr)
            {
                return pGround;
            }
        }

        return nullptr;
    }

    vector<Bomb*> FindAllBombs() const
    {
        vector<Bomb*> vecBombs;

        for (size_t i = 0; i < vecDynamicObj.size(); i++)
        {
            Bomb* pBomb = dynamic_cast<Bomb*>(vecDynamicObj[i]);
            if (pBomb != nullptr)
            {
                vecBombs.push_back(pBomb);
            }
        }

        return vecBombs;
    }

    Plane* FindPlane() const
    {
        for (size_t i = 0; i < vecDynamicObj.size(); i++)
        {
            Plane* p = dynamic_cast<Plane*>(vecDynamicObj[i]);
            if (p != nullptr)
            {
                return p;
            }
        }

        return nullptr;
    }

    LevelGUI* FindLevelGUI() const
    {
        for (size_t i = 0; i < vecStaticObj.size(); i++)
        {
            LevelGUI* p = dynamic_cast<LevelGUI*>(vecStaticObj[i]);
            if (p != nullptr)
            {
                return p;
            }
        }

        return nullptr;
    }

    void DropBomb()
    {
        if (bombsNumber > 0)
        {
            MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked");

            Plane* pPlane = FindPlane();
            double x = pPlane->GetX() + 4;
            double y = pPlane->GetY() + 2;

            Bomb* pBomb = new Bomb;
            pBomb->SetDirection(0.3, 1);
            pBomb->SetSpeed(2);
            pBomb->SetPos(x, y);
            pBomb->SetWidth(SMALL_CRATER_SIZE);

            vecDynamicObj.push_back(pBomb);
            bombsNumber--;
            score -= Bomb::BombCost;
        }
    }

 public:
     std::vector<DynamicObject*> vecDynamicObj;
     std::vector<GameObject*> vecStaticObj;

     bool exitFlag;

     uint64_t startTime, finishTime, passedTime;
     uint16_t bombsNumber, deltaTime, fps;
     int16_t score;
};


SBomber::SBomber() : m_pImpl(new SBomberImpl())
{
    MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    Plane* p = new Plane;
    p->SetDirection(1, 0.1);
    p->SetSpeed(4);
    p->SetPos(5, 10);
    m_pImpl->vecDynamicObj.push_back(p);

    LevelGUI* pGUI = new LevelGUI;
    pGUI->SetParam(m_pImpl->passedTime, m_pImpl->fps, m_pImpl->bombsNumber, m_pImpl->score);
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY(); 
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    pGUI->SetPos(offset, offset);
    pGUI->SetWidth(width);
    pGUI->SetHeight(maxY - 4);
    pGUI->SetFinishX(offset + width - 4);
    m_pImpl->vecStaticObj.push_back(pGUI);

    Ground* pGr = new Ground;
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    m_pImpl->vecStaticObj.push_back(pGr);

    Tank* pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(30, groundY - 1);
    m_pImpl->vecStaticObj.push_back(pTank);

    pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(50, groundY - 1);
    m_pImpl->vecStaticObj.push_back(pTank);

    House * pHouse = new House;
    pHouse->SetWidth(13);
    pHouse->SetPos(80, groundY - 1);
    m_pImpl->vecStaticObj.push_back(pHouse);

    /*
    Bomb* pBomb = new Bomb;
    pBomb->SetDirection(0.3, 1);
    pBomb->SetSpeed(2);
    pBomb->SetPos(51, 5);
    pBomb->SetSize(SMALL_CRATER_SIZE);
    vecDynamicObj.push_back(pBomb);
    */
}

SBomber::~SBomber()
{
    for (size_t i = 0; i < m_pImpl->vecDynamicObj.size(); i++)
    {
        if (m_pImpl->vecDynamicObj[i] != nullptr)
        {
            delete m_pImpl->vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < m_pImpl->vecStaticObj.size(); i++)
    {
        if (m_pImpl->vecStaticObj[i] != nullptr)
        {
            delete m_pImpl->vecStaticObj[i];
        }
    }

    delete m_pImpl;
}

bool SBomber::GetExitFlag() const { return m_pImpl->exitFlag; }

void SBomber::MoveObjects()
{
    MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < m_pImpl->vecDynamicObj.size(); i++)
    {
        if (m_pImpl->vecDynamicObj[i] != nullptr)
        {
            m_pImpl->vecDynamicObj[i]->Move(m_pImpl->deltaTime);
        }
    }
};

void SBomber::CheckObjects()
{
    MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    m_pImpl->CheckPlaneAndLevelGUI();
    m_pImpl->CheckBombsAndGround();
};


void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        m_pImpl->exitFlag = true;
        break;

    case 72: // up
        m_pImpl->FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        m_pImpl->FindPlane()->ChangePlaneY(0.25);
        break;

    case 'b':
        m_pImpl->DropBomb();
        break;

    case 'B':
        m_pImpl->DropBomb();
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < m_pImpl->vecDynamicObj.size(); i++)
    {
        if (m_pImpl->vecDynamicObj[i] != nullptr)
        {
            m_pImpl->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < m_pImpl->vecStaticObj.size(); i++)
    {
        if (m_pImpl->vecStaticObj[i] != nullptr)
        {
            m_pImpl->vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    m_pImpl->fps++;

    m_pImpl->FindLevelGUI()->SetParam(m_pImpl->passedTime, m_pImpl->fps, m_pImpl->bombsNumber, m_pImpl->score);
}

void SBomber::TimeStart()
{
    MyTools::logger.WriteToLog(string(__FUNCTION__) + " was invoked");
    m_pImpl->startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    m_pImpl->finishTime = GetTickCount64();
    m_pImpl->deltaTime = uint16_t(m_pImpl->finishTime - m_pImpl->startTime);
    m_pImpl->passedTime += m_pImpl->deltaTime;

    MyTools::logger.WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)m_pImpl->deltaTime);
}

