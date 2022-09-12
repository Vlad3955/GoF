
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

void Bomb::removeobsrver(DestroyableGroundObject* obs)
{
    _observers.erase(remove(_observers.begin(), _observers.end(), obs), _observers.end());
}

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}