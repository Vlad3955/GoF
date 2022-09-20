#include "Mediator.h"

Mediator::Mediator() : lev(nullptr)
{
	
}

void Mediator::AddColeague(LevelGUI* lGUI)
{
	lev = lGUI;
}

void Mediator::queueMessage(std::string& mes)
{
	lev->BeNotified(mes);
}

Mediator::~Mediator()
{
}