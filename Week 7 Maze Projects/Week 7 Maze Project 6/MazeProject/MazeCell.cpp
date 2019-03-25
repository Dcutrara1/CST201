#include "pch.h"
#include "MazeCell.h"



MazeCell::MazeCell()
{
}

void MazeCell::Cell(int x, int y, bool wall)
{
	X = x;
	Y = y;
	isWall = wall;
	visited = false;
	Location = x * 10 + y;
}

bool MazeCell::GetWall()
{
	return isWall;
}

void MazeCell::SetWall()
{
	isWall = true;
}

bool MazeCell::GetVisited()
{
	return visited;
}

void MazeCell::SetVisited()
{
	visited = true;
}

int MazeCell::GetX()
{
	return X;
}

int MazeCell::GetY()
{
	return Y;
}