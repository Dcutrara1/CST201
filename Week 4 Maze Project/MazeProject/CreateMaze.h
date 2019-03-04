#pragma once
#include "pch.h"
#include "ReadFile.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class CreateMaze
{
	// struct node of linked list 
	struct node
	{
		int data;
		node *right, *down;
	}*head, *tail;


public:
	CreateMaze();
	void PrintMap(vector<vector<int>>);

private:
	int maze[11][10];
};