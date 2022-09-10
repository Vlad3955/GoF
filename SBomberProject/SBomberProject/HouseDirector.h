#pragma once
#include <iostream>
#include "HouseBuilderA.h"
#include <stdint.h>

class HouseDirector
{
public:
	HouseDirector(HouseBuilderA& _hbA);
	void constructWithCHimney();
	void constructWithoutCHimney();
	void constructBigWindow();
	void constructSmallWindow();
	~HouseDirector();
private:
	HouseBuilderA& hbA;
};

