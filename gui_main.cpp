#include <iostream>
#include "graphicBoardClass.cpp"
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

int main()
{

    Board board(10);
    board.placeShip(3, 3, 4, 'h'); // �������� ������� �� 4 ������

    // �������� ����������� �����
    GraphicBoard gb(board, 40, 50, 50); // 40px ������, ���� ���������� �� ����� (50, 50)

    RenderWindow window(VideoMode(600, 600), "Battleship Test");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(200, 200, 200));
        gb.draw(window, false); // false � ���������� �������
        window.display();
    }
}