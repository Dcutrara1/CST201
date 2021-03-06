// Project_16.15.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name:		Daniel Cutrara
// Class:		CST-201
// Prof:		Bradley Mauge
// Date:		03/11/2019

#include "pch.h"
#include "ExpressionTree.h"
#include "BinaryTreeNode.h"
#include "StackNodde.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declare variable s
	string s;

	// Print headline of program
	cout << "Expression Tree Testing!!! " << endl;
	
	// Prompt user to input prefix expression
	cout << "\nEnter equation in Prefix form: ";
	
	// Read the user entered expression to variable s
	cin >> s;

	ExpressionTree et;
	
	// Call function createTree()
	et.createTree(s);
	
	// display the result
	cout << "\n\nEvaluated Result : " << endl;
	
	system("pause");
}