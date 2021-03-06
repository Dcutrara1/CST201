// Name:		Daniel Cutrara
// Course:		CST-201
// Instructor:	Bradley Mauger 	
// Date:		02/10/2019

#include "pch.h"
#include "ReadFile.h"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// struct node of linked list 
struct node
{
	int data;
	node *right, *down;
}*head, *tail;

node* createNode(int d);

// returns head pointer of linked list constructed from 2D matrix 
node* createLinkedMaze(int matrix[][11], int i, int j, int m, int n);

// Function for displaying linked list data
void display(node* head);

int main()
{
	// Create a Maze using the input_file provided
	ReadFile Maze;

	// Create a vector to create Maze Grid
	std::vector<std::vector<int>> Grid(Maze.Corrdinates());
	
	Maze.outputFile(Grid);

	ifstream inputfile{ "maze.txt" };
	static int MazeArray[10][11]{};
	for (int i{}; i != 11; ++i)
	{
		for (int j{}; j != 10; ++j)
		{
			inputfile >> MazeArray[i][j];
		}
	}

	int m = 10, n = 11;
	node* head = createLinkedMaze(MazeArray, 0, 0, m, n);

	display(head);	
}

node * createNode(int d)
{
	node* temp = new node;
	temp->data = d;
	temp->right = temp->down = NULL;
	return temp;
}

node * createLinkedMaze(int matrix[][11], int i, int j, int m, int n)
{
	// return if i or j is out of bounds 
	if (i > n - 1 || j > m - 1)
		return NULL;

	// create a new node for current i and j and recursively allocate its down and 
	// right pointers 
	node* temp = new node();
	temp->data = matrix[i][j];
	temp->right = createLinkedMaze(matrix, i, j + 1, m, n);
	temp->down = createLinkedMaze(matrix, i + 1, j, m, n);
	return temp;
}

void display(node * head)
{
	// pointer to move right 
	node* Rp;

	// pointer to move down 
	node* Dp = head;

	//for top line formatting
	cout << "    ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i << " "; 
	}
	cout << "\n\n    ";

	int i = 0;

	// loop till node->down is not NULL 
	while (Dp)
	{
		Rp = Dp;
		for (int k = 0; k < 3; k++)
		{
			// loop till node->right is not NULL 
			while (Rp)
			{
				if (k == 0)
				{
					// Switch used to determine which square is printed based on number
					switch (Rp->data)
					{
					case 1:
						cout << "XXX";
						break;
					default:
						cout << "...";
					}

				}
				else if (k == 1)
				{
					// Switch used to determine which square is printed based on number
					switch (Rp->data)
					{
					case 0:
						cout << "...";
						break;
					case 1:
						cout << "XXX";
						break;
					case 2:
						cout << ".F.";
						break;
					default:
						cout << ".S.";
					}
				}
				else if (k == 2)
				{
					// Switch used to determine which square is printed based on number
					switch (Rp->data)
					{
					case 1:
						cout << "XXX";
						break;
					default:
						cout << "...";
					}
				}

				Rp = Rp->right;
			}

			if (k == 0)
			{
				//for line formatting with row numbers
				if (i >= 10)
				{
					cout << "\n" << i << "  ";
				}
				else
				{
					cout << "\n" << i << "   ";
				}
				i++;
			}
			else
			{
				cout << "\n    ";
			}
			Rp = Dp;

		}
		Dp = Dp->down;
	}
}
