#pragma once
#include <vector>

using namespace std;

class Ship
{
private:
	int x;
	int y;
	int length;
	char direction;
	int hits;

public:

	Ship(int startX, int startY, int len, char dir):x(startX), y(startY), length(len), direction(dir), hits(0)
	{

	}

	void registerHit()
	{
		hits++;
	}

	bool isSunk()
	{
		if (hits >= length)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	vector<pair<int, int>> getCoordinates()
	{
		vector <pair<int, int>> v1;
		int tempX = x;
		int tempY = y;

		for (int i = 0; i < length; i++)
		{
			if (direction == 'h')
			{
				v1.push_back(make_pair(tempX, tempY));
				tempX++;
			}
			else if (direction == 'v')
			{
				v1.push_back(make_pair(tempX, tempY));
				tempY++;
			}
		}
		return v1;
	}

};