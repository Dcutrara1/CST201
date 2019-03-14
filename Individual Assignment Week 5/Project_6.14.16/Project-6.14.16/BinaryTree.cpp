#pragma once
#include "pch.h"
#include "BinaryTree.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
BinaryTree<T>::BinaryTree()
{

}

template<typename T>
int BinaryTree<T>::GetData(T data)
{
	return FindData(root, data);
}

template<typename T>
inline int BinaryTree<T>::FindData(node* temp, T dataSearch)
{
	if (!temp)
		return -1;
	if (temp->data == dataSearch)
		return 0;
	else if (temp->Right)
		return 1 + FindData(temp->Right, dataSearch);
	else
		return 1 + FindData(temp->Left, dataSearch);
}

template<typename T>
void BinaryTree<T>::AddNode(T dataToAdd)
{
	if (!root)
		root = new node{ dataToAdd, nullptr, nullptr, nullptr };
	else
	{
		node* temp = new node{ dataToAdd, nullptr, nullptr, nullptr };
		node* trace = root;
		while (trace->Right != nullptr)
			trace = trace->Right;

		trace->Right = temp;

		std::map<T, node*> MStorage;
		MStorage.insert(FillMap(MStorage, root));
		std::vector<node*> VStorage;
		VStorage = ConvertMapToVector(MStorage);
		root = ConvertToTree(VStorage, 0, VStorage.size() - 1);
	}
}
template<typename T>
void BinaryTree<T>::DeleteNode(T data)
{
	std::map<int, node*> MStorage;
	MStorage.insert(FillMap(MStorage, root));
	MStorage.erase(data);
	std::vector<node*> VStorage;
	VStorage = ConvertMapToVector(MStorage);
	root = ConvertToTree(VStorage, 0, VStorage.size() - 1);
}

template<typename T>
int BinaryTree<T>::Size()
{
	return Size(root);
}

template<class T>
typename BinaryTree<T>::node * BinaryTree<T>::GetRoot()
{
	return root;
}


template<typename T>
int BinaryTree<T>::Size(node* temp)
{
	int total = 1;

	if (temp->Right != nullptr)
		total = 1 + Size(temp->Right);
	if (temp->Left != nullptr)
		total = 1 + Size(temp->Left);

	return total;
}

//Start of the tree sorting process
template<typename T>
std::pair<T, typename BinaryTree<T>::node*> BinaryTree<T>::FillMap(std::map<T, node*> &storage, node* temp)
{
	if (temp->Right != nullptr)
		storage.insert(FillMap(storage, temp->Right));
	if (temp->Left != nullptr)
		storage.insert(FillMap(storage, temp->Left));
	return std::make_pair(temp->data, temp);
}

template<class T>
typename BinaryTree<T>::node* BinaryTree<T>::ConvertToTree(std::vector<node*> &VTemp, int first, int last)
{
	if (first > last)
		return nullptr;

	int middle = (first + last) / 2;

	VTemp[middle]->Right = ConvertToTree(VTemp, middle + 1, last);
	VTemp[middle]->Left = ConvertToTree(VTemp, first, middle - 1);

	return VTemp[middle];
}

template<class T>
typename std::vector<typename BinaryTree<T>::node*> BinaryTree<T>::ConvertMapToVector(std::map<T, node*> mapTemp)
{
	std::vector<node*> vectorTemp;
	typename std::map<T, typename BinaryTree<T>::node*>::iterator it;
	for (it = mapTemp.begin(); it != mapTemp.end(); ++it)
		vectorTemp.push_back(it->second);
	return vectorTemp;
}

//When using outside of header, make sure to pass in GetRoot() function as parameter
template<typename T>
bool BinaryTree<T>::IsBinaryTree(node* temp)
{
	if (temp->Right == nullptr && temp->Left == nullptr)
		return true;
	else if (temp->Right != nullptr && temp->Left == nullptr)
	{
		if (temp->data < temp->Right->data
			&& IsBinaryTree(temp->Right))
			return true;
		else
			return false;
	}
	else if (temp->Right == nullptr && temp->Left != nullptr)
	{
		if (temp->Left->data < temp->data
			&& IsBinaryTree(temp->Left))
			return true;
		else
			return false;
	}
	else if (temp->Right != nullptr && temp->Left != nullptr)
	{
		if (temp->Left->data < temp->data
			&& temp->data < temp->Right->data
			&& IsBinaryTree(temp->Left)
			&& IsBinaryTree(temp->Right))
			return true;
		else
			return false;
	}
	else
		return true;
}