#include "BombIterator.h"

BombIterator::BombIterator(vector<DynamicObject*>& ref) : refArr(ref), curIndex(-1), ptr(nullptr)
{
	++(*this);
}

void BombIterator::reset()
{
	curIndex = -1; ptr = nullptr;
}

BombIterator& BombIterator::operator++ () // ���������� ���������
{
	curIndex++;
	if (curIndex == -1)
		curIndex = 0;
	for (; curIndex < refArr.size(); curIndex++)
	{
		if (refArr[curIndex] != nullptr)
		{
			ptr = dynamic_cast<Bomb*>(refArr[curIndex]);
		}
	}
	if (curIndex == refArr.size())
	{
		curIndex = -1;
		ptr = nullptr;
	}
	return *this;
}

BombIterator& BombIterator::operator-- () // ���������� ���������
{
	if (curIndex == -1)
		curIndex = refArr.size() - 1;
	for (; curIndex >= 0; curIndex--)
	{
		if (ptr != nullptr)
		{
			ptr = dynamic_cast<Bomb*>(refArr[curIndex]);
		}	
	}
	if (curIndex == -1)
	{
		ptr = nullptr;
	}
	return *this;
}

DynamicObject* BombIterator::operator*() // �������� ������������� ���������
{
	return refArr.at(curIndex);
}

bool BombIterator::operator==(BombIterator it) // �������� �� ���. ��������� ����������
{
	if (curIndex == it.curIndex &&
		ptr == it.ptr &&
		refArr == it.refArr)
	{
		return true;
	}
	return false;
}

bool BombIterator::operator!=(BombIterator it) // �������� �� ���. �����������
{
	return !(*this == it);
}