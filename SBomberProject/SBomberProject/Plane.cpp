
#include <iostream>

#include "Plane.h"
#include "MyTools.h"
#include "Visitor.h"

using namespace std;
using namespace MyTools;

void Plane::Accept(Visitor& v)
{
    v.log(this);
}


void Plane::Draw() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
    GotoXY(x - 2, y - 1);
    cout << "===";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}
