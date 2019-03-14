#pragma once
#include "BinaryTreeNode.h"

class StackNodde
{
public:
	StackNodde();
public:
	BinaryTreeNode *treeNode;
	StackNodde *next;
	// Parametrized constructor
	StackNodde(BinaryTreeNode *treeNode)
	{
		// Set node to treeNode
		this->treeNode = treeNode;
		// Set next pointer as NULL
		next = nullptr;
	}
};

