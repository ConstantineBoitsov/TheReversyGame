#pragma once
#include "Board.h"
#include "Dot.h"
class Game
{
private:
	GameState GamS;
	Board *GameBoard;
	static const int Bsize = 8;
public:
	Game(Board *B) {
		GameBoard = B;
		GamS = Player1;
	}
	~Game() {}
	void TheGame();
	bool CheckAndGo(GameState Player, int x, int y, bool Chk);
	bool Check();
	bool CheckPlayerGo(GameState Player);
};

