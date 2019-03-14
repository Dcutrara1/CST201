#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
class BinaryTree
{
	struct node {
		T data;
		node* Left;
		node* Right;
		node* Parent;
	};

public:

	BinaryTree();
	int GetData(T data);
	int FindData(node* temp, T data);
	void AddNode(T data);
	void DeleteNode(T data);
	int Size();
	node* GetRoot();
	bool IsBinaryTree(node * temp);

private:

	int Size(node*);
	std::pair<T, node*> FillMap(std::map<T, node*> &storage, node*);
	node* ConvertToTree(std::vector<node*>&, int, int);
	std::vector<node*> ConvertMapToVector(std::map<T, node*>);
	node* root = nullptr;
};