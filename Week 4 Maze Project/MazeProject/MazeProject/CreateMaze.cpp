#include "pch.h"
#include "CreateMaze.h"
#include "ReadFile.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

CreateMaze::CreateMaze()
{
}

void CreateMaze::PrintMap(vector<vector<int>> grid)
{
	//for top line formatting
	cout << "    ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i << " ";
	}
	cout << "\n";
	cout << "   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

	string temp[3][10];
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			switch (grid[i][j])
			{
			case 0:		//Empty
				temp[0][j] = "...";
				temp[1][j] = "...";
				temp[2][j] = "...";
				break;
			case 1:		//Wall
				temp[0][j] = "XXX";
				temp[1][j] = "XXX";
				temp[2][j] = "XXX";
				break;
			case 2:		//Start
				temp[0][j] = "...";
				temp[1][j] = ".F.";
				temp[2][j] = "...";
				break;
			case 3:		//Finish
				temp[0][j] = "...";
				temp[1][j] = ".S.";
				temp[2][j] = "...";
				break;
			case 4:		//Visited, not on stack
				temp[0][j] = "^^^";
				temp[1][j] = "^^^";
				temp[2][j] = "^^^";
				break;
			case 5:		//On stack
				temp[0][j] = "~~~";
				temp[1][j] = "~~~";
				temp[2][j] = "~~~";
				break;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			if (j == 1)
			{
				//for line formatting with row numbers
				if (i >= 10)
				{
					cout << i << " X";
				}
				else
				{
					cout << i << "  X";
				}

				for (int k = 0; k < 10; k++)
				{
					cout << temp[j][k];
				}
				cout << "X" << endl;
			}
			else
			{
				cout << "   X";

				for (int k = 0; k < 10; k++)
				{
					cout << temp[j][k];
				}
				cout << "X" << endl;

			}

		}
	}
	cout << "   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
}
