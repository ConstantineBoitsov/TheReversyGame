#include "stdafx.h"
#include "Game.h"

void Dot::Print()
{
	if (_state == Empty)
		std::cout << "[ ]";
	else if (_state == Black)
		std::cout << "[B]";
	else if (_state == White)
		std::cout << "[W]";
}

void Board::PrintBoard()
{
	std::cout << "  _1__2__3__4__5__6__7__8_" << std::endl;
	for (int i = 0; i < Bsize; i++) {
		std::cout << i + 1 << "|";
		for (int j = 0; j < Bsize; j++)
			dots[j][i].Print();
		std::cout << std::endl;
	}
}

void Game::TheGame()
{
	int x, y;
	if (!Check()) 
		GamS = EndGame;
	while (GamS!=EndGame)
	{
		switch (GamS)
		{
		case Player1:
		{
			system("cls");
			GameBoard->PrintBoard();
			std::cout << ("Ход игрока 1") << std::endl << std::endl;
			//std::cout << GameBoard->BlackCount();
			//std::cout << GameBoard->WhiteCount();
			if (!(CheckPlayerGo(GamS)))
			{
				std::cout << "Нет возможных ходов" << std::endl;
				system("pause");
				GamS = Player2;
				break;
			}
			std::cout << ("Введите координату по горизонтали: ") << std::endl;
			std::cin >> x;
			std::cout << ("Введите координату по вертикали: ") << std::endl;
			std::cin >> y;
			if (CheckAndGo(Player1, x - 1, y - 1, false))
				GamS = Player2;
			break;
		}
			
		case Player2:
			system("cls");
			GameBoard->PrintBoard();
			std::cout << ("Ход игрока 2") << std::endl << std::endl;
			//std::cout << GameBoard->BlackCount();
			//std::cout << GameBoard->WhiteCount();
			if (!(CheckPlayerGo(GamS)))
			{
				std::cout << "Нет возможных ходов" << std::endl;
				system("pause");
				GamS = Player1;
				break;
			}
			std::cout << ("Введите координату по горизонтали: ") << std::endl;
			std::cin >> x;
			std::cout << ("Введите координату по вертикали: ") << std::endl;
			std::cin >> y;
			if (CheckAndGo(Player2, x - 1, y - 1, false))
				GamS = Player1;
			break;
		case EndGame:
			system("cls");
			if ((GameBoard->BlackCount()) > (GameBoard->WhiteCount()))
				std::cout << "Игрок 1 победил!" << std::endl;
			else if ((GameBoard->BlackCount()) < (GameBoard->WhiteCount()))
				std::cout << "Игрок 2 победил!" << std::endl;
			else 
				std::cout << "Ничья!" << std::endl;
			system("pause");
			break;
		default:
			break;
		}
	}
}

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
	if (!emp) return emp;
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
