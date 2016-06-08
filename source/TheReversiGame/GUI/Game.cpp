//#include "stdafx.h"
#include "Game.h"


bool Game::CheckAndGo(GameState Player,int x, int y, bool Chk)
{
	bool fl = false;
	bool go = false;
	int k, g;
	int p = 0;
	int s = 0;
	State Check = Empty;
	if (GameBoard->GetState(x, y) != Empty)
		return go;
	if (Player == Player1)
	{
		Check = Black;
	}
	if (Player==Player2)
	{
		Check = White;
	}
	// ------горизонтали
	// ---------------слева от текущей клетки
	for ( fl = false, k = y - 1; k >= 0 && Empty != GameBoard->GetState(x,k); --k) 
	{
		if (GameBoard->GetState(x, k) == Check)
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0) {
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x, y-s, Check);
			s++;
		}
		if (Chk) 
			return true;
		else
			go = true;
	}
	p = 0;
	// -------------------справа
	for (fl = false, k = y + 1; k < Bsize && Empty != GameBoard->GetState(x, k); ++k)
	{
		if (GameBoard->GetState(x, k) == Check)
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0)
	{
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x, y + s, Check);
			s++;
		}
		if (Chk) 
			return true;
		else
			go = true;
	}
	p = 0;
	// --- вертикали
	// ------------- снизу от клетки
	for (fl = false, k = x - 1; k >= 0 && Empty != GameBoard->GetState(k, y); --k)
	{
		if (GameBoard->GetState(k, y) == Check)
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0) {
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x-s, y , Check);
			s++;
		}
		if (Chk) 
			return true;
		else
			go = true;
	}
	p = 0;
	//------------- сверху
	for (fl = false, k = x + 1; k < Bsize && Empty != GameBoard->GetState(k, y); ++k)
	{
		if (GameBoard->GetState(k, y) == Check)
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0)
	{
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x+s, y, Check);
			s++;
		}
		if (Chk)
			return true;
		else
			go = true;
	}
	p = 0;
	//------ главная диагональ
	// ----------- слева сверху
	for (fl = false, g = x - 1, k = y - 1; k >= 0 && g >= 0 && Empty != GameBoard->GetState(g, k); --g, --k)
	{
		if (GameBoard->GetState(g, k) == Check) 
		{
			fl = true;
			break;
		}
		else
			p++;
}
	if (fl&&p>0)
	{
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x-s, y - s, Check);
			s++;
		}
		if (Chk) 
			return true;
		else
			go = true;
	}
	p = 0;
	//----------справа снизу
	for (fl = false, g = x + 1, k = y + 1; k < Bsize && g < Bsize && Empty != GameBoard->GetState(g, k); ++g, ++k)
	{
		if (GameBoard->GetState(g, k) == Check)
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0) 
	{
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x + s, y + s, Check);
			s++;
		}
		if (Chk)
			return true;
		else
			go = true;
	}
	p = 0;
	// ----- побочная диагональ
	// ----------- справа сверху
	for (fl = false, g = x - 1, k = y + 1; k < Bsize && g >= 0 && Empty != GameBoard->GetState(g, k); --g, ++k)
	{
		if (GameBoard->GetState(g, k) == Check) 
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0)
	{
		s = 0;
		while ((s <= p) && !(Chk)) 
		{
			GameBoard->SetState(x-s, y + s, Check);
			s++;
		}
		if (Chk) 
			return true;
		else
			go = true;
	}
	p = 0;
	// -------------- слева снизу
	for (fl = false, g = x + 1, k = y - 1; k >= 0 && g < Bsize && Empty != GameBoard->GetState(g, k); ++g, --k)
	{
		if (GameBoard->GetState(g, k) == Check)
		{
			fl = true;
			break;
		}
		else
			p++;
	}
	if (fl&&p>0)
	{
		s = 0;
		while ((s <= p) && !(Chk))
		{
			GameBoard->SetState(x + s, y - s, Check);
			s++;
		}
		if(Chk) 
			return true;
		else 
			go = true;
	}
    p = 0;
    return go;
}

bool Game::Check()
{
	bool emp = false;
	for (int i = 0; i < Bsize; i++)
		for (int j = 0; j < Bsize; j++)
			if (GameBoard->GetState(i, j) == Empty)
				emp = true;
    if (!emp)
        return emp;
    bool pl1 = CheckPlayerGo(Player1);
    bool pl2 = CheckPlayerGo(Player2);
    if (pl1 || pl2)
        return true;
    if ((!pl1) && (!pl2))
        return false;
}

bool Game::CheckPlayerGo(GameState Player)
{
    bool pl = false;
    for (int i = 0; i < Bsize; i++)
        for (int j = 0; j < Bsize; j++)
            if (CheckAndGo(Player, i, j, true))
                pl = true;
    return pl;
}
