#pragma once
#include "BinaryTreeNode.h"
#include "StackNodde.h"
#include <string>

using namespace std;

class ExpressionTree
{
public:
	ExpressionTree();
	void empty();

	void push(BinaryTreeNode * ptr);
	BinaryTreeNode *pop();
	BinaryTreeNode *peek();		
	void insert(char val);
	bool checkDigit(char ch);
	bool checkOperator(char ch);
	int charToDigit(char ch);
	void createTree(string epn);
	double evaluate();
	double evaluate(BinaryTreeNode * ptr);

private:
	StackNodde *top;

};

