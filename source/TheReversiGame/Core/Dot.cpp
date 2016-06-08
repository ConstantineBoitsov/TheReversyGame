
#include "Dot.h"

void Dot::SetCol(int x)
{
	colum = x;
}

void Dot::SetRow(int y)
{
	row = y;
}

void Dot::SetState(State state)
{
	_state = state;
}

State Dot::GetState()
{
	return _state;
}

int Dot::GetCol()
{
	return colum;
}

int Dot::GetRow()
{
	return row;
}




