#pragma once
#include <vector>
#include "DynamicObject.h"
#include "Bomb.h"

using namespace std;

class BombIterator { // «Итератор» по четным числам в массиве
	const vector<DynamicObject*>& refArr;
	int curIndex;
	DynamicObject* ptr;
public:
	BombIterator(const vector<DynamicObject*>& ref);
	void reset();
	BombIterator& operator++ (); // префиксный инкремент
	BombIterator& operator-- (); // префексный декремент
	DynamicObject* operator*(); // операция разыменования итератора
	bool operator==(BombIterator it); // проверка на лог. равенство итераторов
	bool operator!=(BombIterator it); // проверка на лог. неравенство
};