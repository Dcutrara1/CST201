#include "pch.h"
#include "Graph.h"
#include <iostream> 
#include <list>
#include <stack>
 
#include <vector>

using namespace std;

Graph::Graph()
{
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list. 
	adj[v].push_back(w); 
}

void Graph::buildGraph(std::vector<std::vector<int>> maze)
{
	//Iterate through the maze to find cells to add to the graph
	for (size_t i = 0; i < maze.size(); i++)
	{
		for (size_t j = 0; j < maze[i].size(); j++)
		{
			//If the cell is not a wall, add to graph
			if (maze[i][j] != 1)
			{
				//Make list of connected cells
				list<int> tempList;
				if (i != maze.size() - 1 && maze[i + 1][j] != 1)
				{
					tempList.push_back((i + 1) * 10 + j);
				}
				if (i != 0 && maze[i - 1][j] != 1)
				{
					tempList.push_back((i - 1) * 10 + j);
				}
				if (j != maze[i].size() - 1 && maze[i][j + 1] != 1)
				{
					tempList.push_back(i * 10 + (j + 1));
				}
				if (j != 0 && !maze[i][j - 1] != 1)
				{
					tempList.push_back(i * 10 + (j - 1));
				}
				graph.emplace((i * 10) + j, Vertex{ maze[i][j], tempList });

			}
		}
	}
}

// The function to do DFS traversal.It uses recursive DFSUtil()
vector<vector<int>>  Graph::DFS(std::vector<std::vector<int>> Grid)
{
	// Mark all the vertices as not visited 
	bool *visited = new bool[V];

	// Call the recursive helper function starting from all vertices one by one 
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			DFSUtil(i, visited, Grid);

	return Grid;
}

void Graph::DFSUtil(int v, bool visited[], std::vector<std::vector<int>> Grid)
{
	// Mark the current node as visited 
	visited[v] = true;
	for (size_t i = 0; i < Grid.size(); i++)
	{
		for (size_t j = 0; j < Grid[i].size(); j++)
		{ Grid[i][j] = 4; }
	}

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited, Grid);
}
