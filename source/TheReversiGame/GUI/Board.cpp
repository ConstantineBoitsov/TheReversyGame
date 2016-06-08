#include "Board.h"
//#include <iostream>


Board::Board()
{
	for (int i = 0; i < Bsize; i++)
		for (int j = 0; j < Bsize; j++)
			dots[i][j].SetState(Empty);
	dots[3][3].SetState(White);
	dots[4][4].SetState(White);
	dots[4][3].SetState(Black);
	dots[3][4].SetState(Black);
}

int Board::BlackCount()
{
	b = 0;
	for (int i = 0; i < Bsize; i++)
		for (int j = 0; j < Bsize; j++)
			if (Black==dots[i][j].GetState())
				b++;
	return b;
}


int Board::WhiteCount()
{
	w = 0;
	for (int i = 0; i < Bsize; i++)
		for (int j = 0; j < Bsize; j++)
			if (White == dots[i][j].GetState())
				++w;
	return w;
}

State Board::GetState(int x, int y)
{
	return dots[x][y].GetState();
}

void Board::SetState(int x, int y, State DotState)
{
	dots[x][y].SetState(DotState);
}

