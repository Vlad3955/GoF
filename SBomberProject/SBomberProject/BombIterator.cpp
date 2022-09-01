#include "BombIterator.h"

BombIterator::BombIterator(const vector<DynamicObject*>& ref) : refArr(ref), curIndex(-1), ptr(nullptr)
{
	++(*this);
}

void BombIterator::reset()
{
	curIndex = -1; ptr = nullptr;
}

BombIterator& BombIterator::operator++ () // префиксный инкремент
{
	curIndex++;
	if (curIndex == -1)
		curIndex = 0;
	for (; curIndex < refArr.size(); curIndex++)
	{
		Bomb* pBomb = dynamic_cast<Bomb*>(refArr[curIndex]);
		if (pBomb != nullptr)
		{
			ptr = refArr[curIndex];
			break;
		}
	}
	if (curIndex == refArr.size())
	{
		curIndex = -1;
		ptr = nullptr;
	}
	return *this;
}

BombIterator& BombIterator::operator-- () // префексный декремент
{
	if (curIndex == -1)
		curIndex = refArr.size() - 1;
	for (; curIndex >= 0; curIndex--)
	{
		Bomb* pBomb = dynamic_cast<Bomb*>(refArr[curIndex]);
		if (pBomb != nullptr)
		{
			ptr = refArr[curIndex];
			break;
		}
	}
	if (curIndex == -1)
	{
		ptr = nullptr;
	}
	return *this;
}


DynamicObject* BombIterator::operator*() // операция разыменования итератора
{
	return refArr.at(curIndex);
}

bool BombIterator::operator==(BombIterator it) // проверка на лог. равенство итераторов
{
	if (curIndex == it.curIndex &&
		ptr == it.ptr &&
		refArr == it.refArr)
	{
		return true;
	}
	return false;
}

bool BombIterator::operator!=(BombIterator it) // проверка на лог. неравенство
{
	return !(*this == it);
}