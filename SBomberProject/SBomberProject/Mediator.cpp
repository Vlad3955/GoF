#include "Mediator.h"

Mediator::Mediator() : lev(nullptr)
{
	
}

void Mediator::AddColeague(LevelGUI* lGUI)
{
	lev = lGUI;

	//lguiVec.push_back(lGUI);
}

void Mediator::queueMessage(std::string& mes)
{
	lev->BeNotified(mes);

	/*for (auto& it : lguiVec)
	{
		it->BeNotified(mes);
	}*/
}

Mediator::~Mediator()
{
}