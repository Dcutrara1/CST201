#pragma once
using namespace std;

class BinaryTreeNode
{
public:
	BinaryTreeNode();
	

public:
	char info;
	BinaryTreeNode *left, *right;
	// Parameterized constructor
	BinaryTreeNode(char value)
	{
		// Set value for info
		this->info = value;
		//Set left pointer as NULL
		this->left = nullptr;
		//Set right pointer as NULL
		this->right = nullptr;
	}
};
