#include "pch.h"
#include "ReadFile.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

ReadFile::ReadFile()
{
}

std::vector<std::vector<int>> ReadFile::Corrdinates()
{
	std::vector<std::vector<int>> map;
	ifstream readFile("input_file.txt");

	int a;
	int b;
	char sym;

	if (readFile.is_open())
	{
		readFile >> a >> sym >> b >> sym;
		map.resize(b);
		for (int i = 0; i < b; i++)
			map[i].resize(a);
		readFile >> sym >> b >> sym >> a >> sym >> sym;
		map[b][a] = 3;
		readFile >> sym >> a >> sym >> b >> sym >> sym;
		map[b][a] = 2;

		do
		{
			readFile >> sym >> a >> sym >> b >> sym >> sym;
			map[b][a] = 1;

		} while (sym != '.');
	}
	readFile.close();	
	
	return map;
}

void ReadFile::outputFile(std::vector<std::vector<int>> Grid)
{
	ofstream outputFile("maze.txt");
	for (int i = 0; i < Grid.size(); i++)
	{
		for (int j = 0; j < Grid[i].size(); j++)
		{
			outputFile << Grid[i][j] << " ";
		}
		outputFile << endl;
	}
	outputFile.close();
}