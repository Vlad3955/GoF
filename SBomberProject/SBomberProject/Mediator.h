#pragma once
#include <iostream>
#include <string>
#include <queue>
#include "Tank.h"

class Tank;

class Mediator
{
public:
	Mediator();
	void queueMessage(std::string mes);
	~Mediator();
private:
	std::queue<std::string> _mes;
};


