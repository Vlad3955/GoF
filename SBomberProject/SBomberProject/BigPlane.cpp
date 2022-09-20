#include "BigPlane.h"


BigPlane::BigPlane()
{
}



void BigPlane::DrawBody() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "HHHHHHHHHH>";
}

void BigPlane::DrawWings() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x + 2, y - 2);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
    GotoXY(x + 2, y + 2);
    cout << "////";
}

void BigPlane::DrawTail() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x - 2, y - 1);
    cout << "===";
}

BigPlane::~BigPlane()
{
}