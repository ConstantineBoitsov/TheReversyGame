#pragma once
#include "State.h"
#include "Dot.h"

class Board
{
private:
	int b = 0;
	int w = 0;
	static const int Bsize = 8;
	Dot dots[Bsize][Bsize];
	GameState Gstate;
public:
	Board();
	~Board() {}
	void PrintBoard();
	int BlackCount();
	int WhiteCount();
	State GetState(int x, int y);
	void SetState(int x, int y, State dotstate);
};

