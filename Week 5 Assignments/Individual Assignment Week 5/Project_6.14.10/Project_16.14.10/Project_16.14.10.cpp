// Project_16.14.10.cpp : This file contains the 'main' function. 
// Name:		Daniel Cutrara
// Class:		CST-201
// Prof:		Bradley Mauger
// Date:		03/10/2019

#include "pch.h"
#include <iostream>
#include <queue>

using namespace std;

/* A binary tree node has data, a pointer to the left child 
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data);
void mirror(Node * root);
void inOrder(struct Node* node);

// Driver to text program
int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	//Print inorder traversal of the input tree
	cout << "\nInorder traversal of the"
		" constructed tree is \n";
	inOrder(root);

	// Convert tree to its mirror
	mirror(root);

	// Print inorder traversal of the mirror tree
	cout << "\nInorder traversal of the "
		"mirror tree is \n";
	inOrder(root);

	cout << endl;
	system("pause");
}

// Create a new node with data and NULL left and right pointers
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return(node);
}

// Swap left and right pointers at every node
void mirror(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> queue;
	queue.push(root);
	
	while (!queue.empty())
	{
		// pop top node from queue 
		Node* curr = queue.front();
		queue.pop();

		// swap left child with right child 
		swap(curr->left, curr->right);

		// push left and right children 
		if (curr->left)
			queue.push(curr->left);
		if (curr->right)
			queue.push(curr->right);
	}
}

// Print function for Inorder traversal
void inOrder(struct Node* node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}