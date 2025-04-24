#include "boardClass.cpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class GraphicBoard
{
private:
	Board& b1;
	int cellSize = 40;
	int startX, startY;


public:

	GraphicBoard(Board& currentBoard, int cellS, int x, int y):b1(currentBoard), cellSize(cellS), startX(x), startY(y)
	{
		
	}

	void draw(RenderWindow& window, bool hideShips)
	{
		int boardSize = b1.getSize();

		for (int x = 0; x < boardSize; x++)
		{
			for (int y = 0; y < boardSize; y++)
			{
				char c = b1.getCell(x + 1, y + 1);

				RectangleShape rectangle(Vector2f(static_cast<float>(cellSize), static_cast<float>(cellSize))); // принимает размер в пикселях как вектор2ф, т.е. флоат

				rectangle.setPosition(startX + x * cellSize, startY + y * cellSize);

				if (c == '.')
				{
					rectangle.setFillColor(Color(135, 206, 250));
				}
				if (c == 'O' && hideShips)
				{
					rectangle.setFillColor(Color(135, 206, 250)); // как будто там пусто
				}
				else if (c == 'O')
				{
					rectangle.setFillColor(Color::White);
				}
				if (c == 'X')
				{
					rectangle.setFillColor(Color(128, 0, 0));
				}
				if (c == '*')
				{
					rectangle.setFillColor(Color(128, 128, 128));
				}
				rectangle.setOutlineColor(Color::Black);
				rectangle.setOutlineThickness(1.0f);
				window.draw(rectangle);
			}
		}
	}

};