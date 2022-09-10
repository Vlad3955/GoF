
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

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}