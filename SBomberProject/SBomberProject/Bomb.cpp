
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include "Visitor.h"

using namespace std;
using namespace MyTools;



void Bomb::Accept(Visitor& v)
{
    v.log(this);
}

void Bomb::addObserver(DestroyableGroundObject* obs)
{
    _observers.push_back(obs);
}

DestroyableGroundObject* Bomb::CheckDestoyableObjects()
{
    
    const double size = this->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < _observers.size(); i++)
    {
        const double x1 = this->GetX() - size_2;
        const double x2 = x1 + size;
        
        if (_observers[i]->HandleInsideCheck(x1, x2))
        {
            return _observers[i];
        }
    }
    return nullptr;
}

void Bomb::RemoveObsrver(DestroyableGroundObject* obs)
{
   _observers.erase(remove(_observers.begin(), _observers.end(), obs), _observers.end());
}

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}