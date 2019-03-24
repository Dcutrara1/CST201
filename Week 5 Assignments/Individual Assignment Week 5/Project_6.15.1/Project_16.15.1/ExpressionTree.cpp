#include "pch.h"
#include "ExpressionTree.h"
#include <iostream>
#include <string>

using namespace std;

ExpressionTree::ExpressionTree()
{
	// Set top pointer as NULL
	top = nullptr;

}
void ExpressionTree::empty()
{
	// Assign NULL to top
	top = nullptr;
}

// Function to push a node into stack
void ExpressionTree::push(BinaryTreeNode *ptr)
{
	// If stack is empty
	if (top == NULL)
		// Top Pointer points to new node
		top = new StackNodde(ptr);
	
	// If stack is not empty
	else
	{
		// Create new node
		StackNodde *nptr = new StackNodde(ptr);
		
		// Set next of new node to top pointer
		nptr->next = top;
		
		// Set top points to new node
		top = nptr;
	}
}
BinaryTreeNode * ExpressionTree::pop()
{
	// If stack is empty
	if (top == NULL)
	cout << "Underflow" << endl;
	else
	{
		// Set ptr to top node in the stack
		BinaryTreeNode *ptr = top->treeNode;
	
		// Set top to next node pointed by top
		top = top->next;
		// Return the pointer
		return ptr;
	}
}

// Function to get top node of stack
BinaryTreeNode * ExpressionTree::peek()
{
	// Return top node in the stack
	return top->treeNode;
}

// Function to insert characters in prefix expression
void ExpressionTree::insert(char val)
{
	// If character is digit
	if (checkDigit(val))
	{
		// Create new node with given value
		BinaryTreeNode *nptr = new BinaryTreeNode(val);
		// Push node to stack
		push(nptr);
	}
	// If character is operator
	else if (checkOperator(val))
	{
		// Create new node
		BinaryTreeNode *nptr = new BinaryTreeNode(val);
		
		// Pop element from stack and assign to left pointer 
		nptr->left = pop();
		
		// Pop element from stack and assign to right pointer 
		nptr->right = pop();
	}
	// Push node to stack If not digit or operator
	else
	{
		// Dispaly message
		cout << "Invalid Expression";
			return;
	}
}

// Function to check character is digit
bool ExpressionTree::checkDigit(char ch)
{
	// Return true if character is digit
	return ch >= '0' && ch <= '9';
}

// Function to check character is operator
bool ExpressionTree::checkOperator(char ch)
{
	// Return true if character is operator
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert character to digit
int ExpressionTree::charToDigit(char ch)
{
	// Return digit correspond to that character
	return ch - '0';
}

// Function to create tree from the given expression
void ExpressionTree::createTree(string epn)
{
	/* Loop throught all the characters in the expression */
	for (int i = epn.length() - 1; i >= 0; i--)
		// Call insert() function
		insert(epn[i]);
}

// Main Function that evaluate expression tree
double ExpressionTree::evaluate()
{
	// Call evaluate() function recursively
	return evaluate(peek());
}

// Function to evaluate a tree
double ExpressionTree::evaluate(BinaryTreeNode * ptr)
{
	// If node is leaf
	if (ptr->left == NULL && ptr->right == NULL)
	{
		/* Return the value of node that is converted to digit */
		return charToDigit(ptr->info);
	}
	else
	{
		double result = 0.0;
		/* Declare variable left and assign value returned by evaluate() function */
		double left = evaluate(ptr->left);
		/* Declare variable right and assign value returned by evaluate() function */
		double right = evaluate(ptr->right);
		/* Declare variable op and assign value ininfo */
		char op = ptr->info;
		// Switch cases
		switch (op)
		{
			// If case is +
		case '+':
			result = left + right;
			break;
			// If case is -
		case '-':
			result = left - right;
			break;
			// If case is *
		case '*':
			result = left * right;
			break;
			// If case is /
		case '/':
			result = left / right;
			break;
			// Default case
		default:
			result = left + right;
			break;
		}
		// Return result
		return result;
	}
};