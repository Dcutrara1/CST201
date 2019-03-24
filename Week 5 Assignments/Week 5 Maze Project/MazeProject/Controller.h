#pragma once
#include <vector>
#include <stack>
#define ROW 11
#define COL 10 

using namespace std;

class Controller
{
public:
	Controller();
	
	struct Point
	{
		int x;  // Track location on the grid
		int y; // Track location on the grid
	};

	// A Data Structure for queue used in BFS 
	struct queueNode
	{
		Point cell;  // The cordinates of a cell 
		int dist;  // cell's distance of from the starting point  
	};

	bool isValid(int row, int col);
	int BFS(std::vector<std::vector<int>> Grid, Point src, Point dest);

};

