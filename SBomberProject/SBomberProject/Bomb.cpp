
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

//BombDecorator
//====================================================
BombDecorator::BombDecorator()
{
}

void BombDecorator::Move(uint16_t time)
{
	_bomb.Move(time * 1.6);
}
void BombDecorator::Draw() const
{
	_bomb.Draw();
	GotoXY(_bomb.GetX(), _bomb.GetY() - 1);
	cout << "|";
}

inline void BombDecorator::SetPos(double nx, double ny)
{
	_bomb.SetPos(nx, ny);
}

inline double BombDecorator::GetY() const
{ 
	return _bomb.GetY(); 
}
inline double BombDecorator::GetX() const
{ 
	return _bomb.GetX(); 
}

inline void BombDecorator::SetWidth(uint16_t widthN)
{ 
	_bomb.SetWidth(widthN);
}
inline uint16_t BombDecorator::GetWidth() const
{ 
	return _bomb.GetWidth(); 
}

BombDecorator::~BombDecorator()
{
}
//====================================================