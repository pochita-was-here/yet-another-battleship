#pragma once
#include "boardClass.cpp"

class Player
{
private:

	Board board;

public:

	Player(int s):board(s) // список инициализации конструктора
	{

	}

	void playerPlaceShip(int x, int y, int len, char dir)
	{
		board.placeShip(x, y, len, dir);
	}

	char makeShot(Player& enemy, int x, int y)
	{
		return enemy.board.shoot(x, y);
	}

	bool isDefeated()
	{
		return board.isGameOver();
	}

	void printBoard(bool hideShips)
	{
		board.print(hideShips);
	}


};