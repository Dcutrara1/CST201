#pragma once
#include "pch.h"
#include "Stack.h"
#include "Cell.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Maze
{
public:
	Maze();
	void exitMaze();
private:
	Cell currentCell, exitCell, entryCell; 
	const char exitMarker, entryMarker, visited, passage, wall; 
	Stack<Cell> mazeStack; 
	char **store; // array of strings; 
	void pushUnvisited(int,int); 
	friend ostream& operator<< (ostream&, const Maze&); 
	int rows, cols;
};

