#pragma once
#include "State.h"
//#include <iostream>
class Dot
{
private:

	int row, colum;         // координаты клетки
	State _state;   // состояние клетки
public:
	Dot(int x = 0, int y = 0, State state = Empty)
	{
		colum = x;
		row = y;
		_state = state;
	}
	// функция устанавливает x-кординату клети
	void SetCol(int x);
	// функция устанавливает y-кординату клети
	void SetRow(int y);
	// функция устанавливает состояние клети
	void SetState(State state);
	// функция возвращает состояние текуйщей клетки
	State GetState();
	// функция возвращает x текуйщей клетки
	int GetCol();
	// функция возвращает y текуйщей клетки
	int GetRow();
	// функция - проверка попадания в клетку
	bool TryHit(int x, int y);
	// функция печати одной клетки, в зависимости от ее состояния
	void Print();
};

