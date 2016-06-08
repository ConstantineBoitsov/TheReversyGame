#pragma once
#include "State.h"
//#include <iostream>
class Dot
{
private:

	int row, colum;         // ���������� ������
	State _state;   // ��������� ������
public:
	Dot(int x = 0, int y = 0, State state = Empty)
	{
		colum = x;
		row = y;
		_state = state;
	}
	// ������� ������������� x-��������� �����
	void SetCol(int x);
	// ������� ������������� y-��������� �����
	void SetRow(int y);
	// ������� ������������� ��������� �����
	void SetState(State state);
	// ������� ���������� ��������� �������� ������
	State GetState();
	// ������� ���������� x �������� ������
	int GetCol();
	// ������� ���������� y �������� ������
	int GetRow();
	// ������� - �������� ��������� � ������
	bool TryHit(int x, int y);
	// ������� ������ ����� ������, � ����������� �� �� ���������
	void Print();
};

