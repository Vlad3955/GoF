#pragma once
#include <vector>
#include "DynamicObject.h"
#include "Bomb.h"

using namespace std;

class BombIterator { // «Итератор» по четным числам в массиве
	vector<DynamicObject*>& refArr;
	int curIndex;
	Bomb* ptr;
public:
	BombIterator(vector<DynamicObject*>& ref);
	void reset();
	BombIterator& operator++ (); // префиксный инкремент
	BombIterator& operator-- (); // префексный декремент
	DynamicObject* operator*(); // операция разыменования итератора
	bool operator==(BombIterator it); // проверка на лог. равенство итераторов
	bool operator!=(BombIterator it); // проверка на лог. неравенство
};