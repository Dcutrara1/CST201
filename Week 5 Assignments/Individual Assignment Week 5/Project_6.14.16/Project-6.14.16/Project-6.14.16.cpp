// Project-6.14.16.cpp : This file contains the 'main' function. 
// Name:		Daniel Cutrara
// Class:		CST-201
// Prof:		Bradley Mauger
// Date:		03/11/2019

#include "pch.h"
#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

int main()
{
	BinaryTree<int> HomeTree;
	HomeTree.AddNode(4);
	HomeTree.AddNode(2);
	HomeTree.AddNode(9);
	HomeTree.AddNode(7);
	HomeTree.AddNode(5);
	HomeTree.AddNode(3);
	HomeTree.DeleteNode(5);


	std::cout << HomeTree.IsBinaryTree(HomeTree.GetRoot()) << std::endl;
	std::cout << "Before Right: " << HomeTree.GetRoot()->Right->data << std::endl;
	std::cout << "Before Left: " << HomeTree.GetRoot()->Left->data << std::endl;
	

	BinaryTree<char> Alphabet;
	for (char c = 'a'; c < 'a' + 26; c++)
	{
		Alphabet.AddNode(c);

	}
	std::cout << "Alphabet is balanced? ";
	std::cout << Alphabet.IsBinaryTree(Alphabet.GetRoot()) << std::endl;

	system("pause");
}