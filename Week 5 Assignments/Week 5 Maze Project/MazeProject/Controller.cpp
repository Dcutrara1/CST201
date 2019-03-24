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
#define ROW 11
#define COL 10 

using namespace std;


Controller::Controller()
{
}

// check whether given cell (row, col) is a valid cell or not. 

bool Controller::isValid(int row, int col)
{
	// return true if row number and column number is in range 
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

int Controller::BFS(std::vector<std::vector<int>> Grid, Point startingPoint, Point dest)
{
	// These arrays are used to get row and column of surrounding cells 
	int rowNum[] = { -1, 0, 0, 1 };
	int colNum[] = { 0, -1, 1, 0 };

	// check source and destination cell of the matrix have value 1 
	if (!Grid[startingPoint.x][startingPoint.y] || !Grid[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	// Mark the source cell as visited 
	visited[startingPoint.x][startingPoint.y] = true;

	// Create a queue for BFS 
	queue<queueNode> queue;

	// Distance of source cell is 0 
	queueNode s = { startingPoint, 0 };
	queue.push(s);  // Enqueue source cell 

	// Do a BFS starting from source cell 
	while (!queue.empty())
	{
		queueNode curr = queue.front();
		Point pt = curr.cell;

		// If reached the exit, finished.  
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		// Otherwise dequeue the front cell in the queue and enqueue its adjacent cells 
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];

			// if adjacent cell is valid, has path and 
			// not visited yet, enqueue it. 
			if (isValid(row, col) && Grid[row][col] && !visited[row][col])
			{
				// mark cell as visited and enqueue it 
				visited[row][col] = true;
				queueNode Adjcell = { {row, col},
									  curr.dist + 1 };
				queue.push(Adjcell);
			}
		}
	}
	// Return -1 if destination cannot be reached 
	return -1;
}