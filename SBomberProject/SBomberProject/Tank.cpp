
#include <iostream>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;


//Mediator* Tank::med;



void Tank::BeNotified(std::string& mes) const
{
	med.queueMessage(mes);
}

bool Tank::isInside(double x1, double x2) const
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

void Tank::Draw() const
{
	srand(time(NULL));

	int x = 1 + rand() % 4;
	std::string mes;

	switch (x)
	{
	case 1:
	    mes = "111111";
	    BeNotified(mes);
	break;
	case 2:
	    mes = "2222222";
		BeNotified(mes);
	break;
	case 3:
		mes = "33333333";
		BeNotified(mes);
	break;
	case 4:
		mes = "44444444";
		BeNotified(mes);
	break;
	default:
		break;
	}

	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";
}