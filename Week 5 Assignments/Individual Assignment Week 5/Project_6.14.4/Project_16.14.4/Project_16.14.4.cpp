// Project_16.14.4.cpp : This file contains the 'main' function.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

/* A binary tree node has data, a pointer to left child 
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

bool isBST(Node *root);
bool isBSTUtil(struct Node* root, Node *&prev);


int main()
{
	struct Node *root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(4);

	if (isBST(root))
		cout << "Is BST" << endl;
	else
		cout << "Not a BST" << endl;

	system("pause");
}

bool isBSTUtil(struct Node* root, Node *&prev)
{
	// traverse the tree in inorder fashion and  
	// keep track of prev node 
	if (root)
	{
		if (!isBSTUtil(root->left, prev))
			return false;

		// Allows only distinct valued nodes  
		if (prev != NULL && root->data <= prev->data)
			return false;

		prev = root;

		return isBSTUtil(root->right, prev);
	}
	return true;
}

bool isBST(Node *root)
{
	Node *prev = NULL;
	return isBSTUtil(root, prev);
}
