#include <iostream>
#include "botPlayerClass.cpp"
#include <cstdlib>



int main()
{
	int boardSize = 10;
	
	Player p1(boardSize), p2(boardSize);

	int maxShipsNum = 6;
	for (int i = 0; i < maxShipsNum; i++)
	{
		int x, y, len;
		char dir;

		cout << "Please, enter coordinates of your " << i + 1 << " ship (x, y): " << endl;

		cin >> x >> y;
		cout << "Please, enter length of the ship: " << endl;
		cin >> len;
		cout << "Please, enter horizontal or vertical (h/v): " << endl;
		cin >> dir;


		p1.playerPlaceShip(x, y, len, dir);
		p1.printBoard(false);
	}

	cout << "Please, turn away and press enter to let 2nd player place their ships." << endl;
	cin.ignore(); // игнорирует перевод строки предыдущего цаута
	cin.get(); // работает только если нажать энтер
	system("cls");

	for (int i = 0; i < maxShipsNum; i++)
	{
		int x, y, len;
		char dir;

		cout << "Please, enter coordinates of your " << i + 1 << " ship (x, y): " << endl;

		cin >> x >> y;
		cout << "Please, enter length of the ship: " << endl;
		cin >> len;
		cout << "Please, enter horizontal or vertical (h/v): " << endl;
		cin >> dir;

		p2.playerPlaceShip(x, y, len, dir);

		p2.printBoard(false);
	}

	cout << "Please, press Enter to begin." << endl;
	cin.ignore(); // игнорирует перевод строки предыдущего цаута
	cin.get(); // работает только если нажать энтер
	system("cls");

	bool firstPlayerTurn = true;

	while (true)
	{
		while (firstPlayerTurn)
		{
			cout << "It's 1st player turn! Please, enter coorinates to shoot (x, y): " << endl;
			int x, y;
			cin >> x >> y;

			char res = p1.makeShot(p2, x, y);
			if (res == 'A')
			{
				cout << "Already shot!" << endl;
				p2.printBoard(true);
				firstPlayerTurn = false;
				break;
			}
			if (res == 'M')
			{
				cout << "Miss!" << endl;
				p2.printBoard(true);
				firstPlayerTurn = false;
				break;
			}

			if (res == 'H')
			{
				cout << "Hit! You can shoot again!" << endl;
				p2.printBoard(true);
			}

			if (res == 'S')
			{
				cout << "Ship sunk! You can shoot again!" << endl;
				p2.printBoard(true);
			}
			if (p2.isDefeated())
			{
				cout << "Victory! You won!" << endl;
				p2.printBoard(true);
				return 0;
			}
		}

		while (!firstPlayerTurn)
		{
			cout << "It's 2st player turn! Please, enter coorinates to shoot (x, y): " << endl;
			int x, y;
			cin >> x >> y;

			char res = p2.makeShot(p1, x, y);
			if (res == 'A')
			{
				cout << "Already shot!" << endl;
				p1.printBoard(true);
				firstPlayerTurn = true;
				break;
			}
			if (res == 'M')
			{
				cout << "Miss!" << endl;
				p1.printBoard(true);
				firstPlayerTurn = true;
				break;
			}

			if (res == 'H')
			{
				cout << "Hit! You can shoot again!" << endl;
				p1.printBoard(true);
			}

			if (res == 'S')
			{
				cout << "Ship sunk! You can shoot again!" << endl;
				p1.printBoard(true);
			}
			if (p1.isDefeated())
			{
				cout << "Victory! You won!" << endl;
				p1.printBoard(true);
				return 0;
			}
		}
	}

}