#pragma once
class MazeCell
{
public:
	MazeCell();

	void Cell(int, int, bool);
	bool GetWall();
	void SetWall();
	bool GetVisited();
	void SetVisited();
	int GetX();
	int GetY();
	int Location;

private:
	bool isWall;
	bool visited;
	int X;
	int Y;
};

