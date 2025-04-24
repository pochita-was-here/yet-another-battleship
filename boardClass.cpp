#pragma once
#include <vector>
#include <iostream>
#include "shipClass.cpp"

using namespace std;


class Board
{
private:
	int size;
	vector<char> field;
    vector<Ship> ships;

    bool canPlaceShip(int x, int y, int shipLength, char direction)
    {
        int tempX = x;
        int tempY = y;


        if (direction == 'v')
        {
            for (int i = 0; i < shipLength; i++)
            {
                if (tempX < 1 || tempY < 1 || tempX > size || tempY > size)
                {
                    return false;
                }

                if (field[(tempX - 1) + (size - tempY) * size] != '.')
                {
                    return false;
                }
                else
                {
                    tempY++;
                }
            }
        }

        if (direction == 'h')
        {
            for (int i = 0; i < shipLength; i++)
            {
                if (tempX < 1 || tempY < 1 || tempX > size || tempY > size)
                {
                    return false;
                }

                if (field[(tempX - 1) + (size - tempY) * size] != '.')
                {
                    return false;
                }
                else
                {
                    tempX++;
                }
            }
        }

        return true;
    }

    int cageIndex(int x, int y)
    {
        int res = (x - 1) + (size - y) * size;
        return res;
    }


public:

	Board(int s)
	{
        size = s;
        field = vector<char> (s * s, '.');
	}

    //Board()
    //{
    //    size = 0;
    //    field = vector<char>();
    //}

	void print(bool hideShips=false)
	{
        if (hideShips == true)
        {
            for (int i = 0; i < size; i++)
            {
                for (int k = 0; k < size; k++)
                {
                    if (field[k + (size * i)] == 'O')
                    {
                        cout << "." << " ";
                    }
                    else
                    {
                        cout << field[k + (size * i)] << " ";
                    }
                }
                cout << endl;
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                for (int k = 0; k < size; k++)
                {
                        cout << field[k + (size * i)] << " ";
                }
                cout << endl;
            }
        }
	}

    void placeShip(int x, int y, int shipLength, char direction)
    {
        if (!canPlaceShip(x, y, shipLength, direction))
        {
            return;
        }
        else
        {
            ships.push_back(Ship(x, y, shipLength, direction));

            for (int i = 0; i < shipLength; i++)
            {
                if (direction == 'h')
                {
                    field[cageIndex(x, y)] = 'O';
                    x++;
                }
                else if (direction == 'v')
                {
                    field[cageIndex(x, y)] = 'O';
                    y++;
                }
            }
        }
    }

    char shoot(int x, int y)
    {
        if ((x < 1) || (y < 1) || (x > size) || (y > size))
        {
            return 'E';
        }

        int index = cageIndex(x, y);

        if (field[index] == '*' || field[index] == 'X')
        {
            return 'A';
        }

        for (int i = 0; i < ships.size(); i++)
        {
            vector<pair<int, int>> v1(ships[i].getCoordinates());
            
            for (auto& pair : v1)
            {
                if (pair.first == x && pair.second == y)
                {
                    ships[i].registerHit();

                    if (ships[i].isSunk())
                    {
                        field[index] = 'X';
                        return 'S';
                    }
                    else 
                    {
                        field[index] = 'X';
                        return 'H';
                    }

                }
            }


        }

        field[index] = '*';
        return 'M';
    }

    bool isGameOver()
    {
        for (int i = 0; i < ships.size(); i++)
        {
            if (ships[i].isSunk() != true)
            {
                return false;
            }
        }

        return true;
    }

    int getSize()
    {
        return size;
    }

    char getCell(int x, int y)
    {
        if (x < 1 || y < 1 || x > size || y > size)
        {
            return 'E'; // err
        }
        return field[cageIndex(x, y)];
    }

};