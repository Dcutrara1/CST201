#pragma once
#include "pch.h"
#include <vector>
#include <fstream>
#include <iostream>

class ReadFile
{

public:
	ReadFile();
	void outputFile(std::vector<std::vector<int>> Grid);
	std::vector<std::vector<int>> Corrdinates();
};

