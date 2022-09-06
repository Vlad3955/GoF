
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

char House::look[7][13];

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);
	int v = 6;
	GotoXY(x, y - v--);
	
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << look[i][j];
		}
		GotoXY(x, y - v--);
	}
}