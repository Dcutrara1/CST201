#pragma once
#include "MazeCell.h"
#include <map>
#include <list>
#include<vector>

using namespace std;

class Graph
{
	int V;    // No. of vertices 
	list<int> *adj;    // adjacency lists 

	struct Vertex 
	{
		int data;
		std::list<int> edges;	
	};
public:

	Graph();
	Graph(int V);
	void buildGraph(std::vector<std::vector<int>>);
	vector<vector<int>>  DFS(std::vector<std::vector<int>> maze);
	void DFSUtil(int v, bool visited[], std::vector<std::vector<int>> Grid);
	void addEdge(int v, int w);  
	
private:
	map<int, Vertex> graph;
};

