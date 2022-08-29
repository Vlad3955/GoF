#pragma once
#include <vector>
#include "DynamicObject.h"
#include "Bomb.h"

using namespace std;

class BombIterator { // ��������� �� ������ ������ � �������
	vector<DynamicObject*>& refArr;
	int curIndex;
	Bomb* ptr;
public:
	BombIterator(vector<DynamicObject*>& ref);
	void reset();
	BombIterator& operator++ (); // ���������� ���������
	BombIterator& operator-- (); // ���������� ���������
	DynamicObject* operator*(); // �������� ������������� ���������
	bool operator==(BombIterator it); // �������� �� ���. ��������� ����������
	bool operator!=(BombIterator it); // �������� �� ���. �����������
};