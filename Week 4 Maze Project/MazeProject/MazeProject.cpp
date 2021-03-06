// Name:		Daniel Cutrara
// Course:		CST-201
// Instructor:	Bradley Mauger 	
// Date:		02/25/2019

#include "pch.h"
#include "ReadFile.h"
#include "CreateMaze.h"
#include "Controller.h"
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main()
{
	// Create a Maze using the input_file provided
	ReadFile Maze;

	// Create a vector to create Maze Grid 
	std::vector<std::vector<int>> Grid(Maze.Corrdinates());

	Controller Mouse;
	Grid = Mouse.Play(Grid);

	CreateMaze maze;	
	maze.PrintMap(Grid);
}