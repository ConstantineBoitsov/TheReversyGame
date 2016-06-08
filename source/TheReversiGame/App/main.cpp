#include <iostream>

#include "Board.h"
#include "Game.h"


int main()
{
    Board B;
    Game Game1(&B);
    Game1.TheGame();
    system("pause");
    return 0;
}

