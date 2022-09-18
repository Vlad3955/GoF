#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "LevelGUI.h"


class Mediator
{
public:
	Mediator();
	void queueMessage(std::string& mes);
	void AddColeague(LevelGUI* lGUI);
	~Mediator();
private:
	LevelGUI* lev;

	//std::vector<LevelGUI*> lguiVec;
};


