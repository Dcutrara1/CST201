#pragma once
#include "pch.h"
#include "ReadFile.h"
#include "CreateMaze.h"
#include "Controller.h"
#include <vector>
#include <stack>
#include <cstdlib>
#include <queue>
#include <list>

using namespace std;

Controller::Controller()
{
}

enum Direction
{
	Left,
	Right,
	Up,
	Down
};

vector<vector<int>> Controller::Play(vector<vector<int>> grid)
{
	// find starting position
	queue<int> Player;
	queue<Direction> pop; // Track which direction to move after popping off stack
	int x; // Track location on the grid
	int y; // Track location on the grid


	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == 3)
			{
				Player.push(grid[i][j]);
				x = i;
				y = j;
			}
		}
	}

	// interate through maze
	bool isFinished = false;
	while (!isFinished)
	{

		// looking up, right, left, down looking for a 0
		if (x + 1 != grid.size() && grid[x + 1][y] == 0)        //Down
		{
		grid[x + 1][y] = 5;
		Player.push(grid[x + 1][y]);
		x += 1;
		pop.push(Up);
		}

		else if (y + 1 != grid[x].size() && grid[x][y + 1] == 0)        //Right
		{
			grid[x][y + 1] = 5;
			Player.push(grid[x][y + 1]);
			y += 1;
			pop.push(Left);
		}

		else if (x - 1 != -1 && grid[x - 1][y] == 0)        //UP
		{
			grid[x - 1][y] = 5;
			Player.push(grid[x - 1][y]);
			x -= 1;
			pop.push(Down);
		}
		
		else if (y - 1 != -1 && grid[x][y - 1] == 0)        //Left
		{
			grid[x][y - 1] = 5;
			Player.push(grid[x][y - 1]);
			y -= 1;
			pop.push(Right);
		}
		else if (grid[x][y - 1] == 5 && grid[x - 1][y] == 1)
		{
			grid[x][y - 1] = 5;
			Player.push(grid[x][y - 1]);
			y -= 1;
			pop.push(Right);

		}

		else // If there is no 0, pop off top off of stack
		{
			switch (pop.back())
			{
			
			case Down:
				Player.pop();
				pop.pop();
				grid[x][y] = 4;
				x += 1;
				break;

			case Right:
				Player.pop();
				pop.pop();
				grid[x][y] = 4;
				y += 1;
				break;

			case Up:
				Player.pop();
				pop.pop();
				grid[x][y] = 4;
				x -= 1;
				break;

			case Left:
				Player.pop();
				pop.pop();
				grid[x][y] = 4;
				y -= 1;
				break;		
			}
		}		

		if (x - 1 != -1 && grid[x - 1][y] == 2)        //UP
			isFinished = true;
		else if (y + 1 != grid[x].size() && grid[x][y + 1] == 2)        //Right
			isFinished = true;
		else if (x + 1 != grid.size() && grid[x + 1][y] == 2)        //Down
			isFinished = true;
		else if (y - 1 != -1 && grid[x][y - 1] == 2)        //Left
			isFinished = true;
	}
	return grid;
}
