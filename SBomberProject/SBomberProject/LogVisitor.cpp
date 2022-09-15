#include "LogVisitor.h"

using namespace std;
using namespace MyTools;

LogVisitor::LogVisitor() {}

void LogVisitor::log(Bomb* pBomb)
{
	WriteToLog("Bomb speed: ", pBomb->GetSpeed());
	//WriteToLog("Bomb direction: ", pBomb->GetDirection());
	WriteToLog("Bomb direction X: ", pBomb->GetDirectionX());
	WriteToLog("Bomb direction Y: ", pBomb->GetDirectionY());
}

void LogVisitor::log(Plane* pPlane)
{
	WriteToLog("Plane speed: ", pPlane->GetSpeed());
	//WriteToLog("Plane direction: ", pPlane->GetDirection());
	WriteToLog("Plane direction X: ", pPlane->GetDirectionX());
	WriteToLog("Plane direction Y: ", pPlane->GetDirectionY());
}

LogVisitor::~LogVisitor() {}