#pragma once
#include "playerClass.cpp"
#include <random>

class BotPlayer
{
private:
	Player player;
	vector<pair<int, int>> remainingShots;

	bool huntMode = true;
	pair<int, int> lastHit = make_pair(-1, -1);
	vector <pair<int, int>> targetQueue;
	char currentDirection='\0';

public:

	BotPlayer(int size) :player(size)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				remainingShots.push_back(make_pair(i + 1, j + 1));
			}
		}
	}

	bool isValidShot(pair<int, int> coords)
	{
		if (find(remainingShots.begin(), remainingShots.end(), coords) != remainingShots.end())
		{
			return true;
		}

		return false;
	}

	void setShotResult(char result, pair<int, int> shot)
	{
		if (result == 'H')
		{
			if (huntMode)
			{
				huntMode = false;
				lastHit = shot;

				if (isValidShot(make_pair(shot.first + 1, shot.second)))
				{
					targetQueue.push_back(make_pair(shot.first + 1, shot.second));
				}
				if (isValidShot(make_pair(shot.first - 1, shot.second)))
				{
					targetQueue.push_back(make_pair(shot.first - 1, shot.second));
				}
				if (isValidShot(make_pair(shot.first, shot.second + 1)))
				{
					targetQueue.push_back(make_pair(shot.first, shot.second + 1));
				}
				if (isValidShot(make_pair(shot.first, shot.second - 1)))
				{
					targetQueue.push_back(make_pair(shot.first, shot.second - 1));
				}
			}
			else
			{
				if (shot.first == lastHit.first && shot.second == lastHit.second + 1)
				{
					currentDirection = 'r';
				}
				else if (shot.first == lastHit.first && shot.second == lastHit.second - 1)
				{
					currentDirection = 'l';
				}
				else if (shot.first == lastHit.first + 1 && shot.second == lastHit.second)
				{
					currentDirection = 'd';
				}
				else if (shot.first == lastHit.first - 1 && shot.second == lastHit.second)
				{
					currentDirection = 'u';
				}
			}


		}

		if (result == 'S')
		{
			huntMode = true;

			if (isValidShot(make_pair(shot.first + 1, shot.second)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first + 1, shot.second)), remainingShots.end());
			}
			if (isValidShot(make_pair(shot.first - 1, shot.second)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first - 1, shot.second)), remainingShots.end());
			}
			if (isValidShot(make_pair(shot.first, shot.second + 1)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first, shot.second + 1)), remainingShots.end());
			}
			if (isValidShot(make_pair(shot.first, shot.second - 1)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first, shot.second - 1)), remainingShots.end());
			}
			
			if (isValidShot(make_pair(shot.first + 1, shot.second + 1)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first + 1, shot.second + 1)), remainingShots.end());
			}
			if (isValidShot(make_pair(shot.first - 1, shot.second + 1)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first - 1, shot.second + 1)), remainingShots.end());
			}
			if (isValidShot(make_pair(shot.first + 1, shot.second - 1)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first + 1, shot.second - 1)), remainingShots.end());
			}
			if (isValidShot(make_pair(shot.first - 1, shot.second - 1)))
			{
				remainingShots.erase(remove(remainingShots.begin(), remainingShots.end(), make_pair(shot.first - 1, shot.second - 1)), remainingShots.end());
			}

			currentDirection = '\0';
			lastHit = { -1, -1 };
			targetQueue.clear();
		}

		if (result == 'M')
		{
			huntMode = true;
			targetQueue.clear();
		}

	}


	pair<int, int> getNextShot()
	{
		pair<int, int> temp;

		if (huntMode)
		{
			random_device rnd;
			mt19937 gen(rnd()); // сид вихря мерсенна
			uniform_int_distribution<> dist(0, remainingShots.size() - 1);

			int tempIndex = dist(gen);

			temp = remainingShots[tempIndex];

			remainingShots.erase(remainingShots.begin() + tempIndex);

			return temp;
		}
		else if (!huntMode)
		{
			if (currentDirection != '\0')
			{
				if (currentDirection == 'r')
				{
					if (isValidShot(make_pair(lastHit.first + 1, lastHit.second)))
					{
						return make_pair(lastHit.first + 1, lastHit.second);
					}
					else
					{
						currentDirection == 'l';
					}
				}
			}
		}

	}

};