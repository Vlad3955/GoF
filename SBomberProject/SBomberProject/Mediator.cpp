#include "Mediator.h"

Mediator::Mediator()
{
}

void Mediator::queueMessage(std::string& mes)
{
	_mes.push(mes);
}

Mediator::~Mediator()
{
}