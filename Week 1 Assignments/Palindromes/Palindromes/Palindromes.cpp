// Name:	Daniel Cutrara
// Course:	CST-201
// Prof:	Bradley Mauger
// Date:	02/21/2019
// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include <forward_list>

using namespace std;

// Struct to create a Singly Linked List
struct node
{
	char data;
	node* next;
}*head;

//Struct to create a Doubly Linked List
struct doublyNode
{
	char data;
	doublyNode* next;
	doublyNode* prev;
}*doublyHead, *doublyTail;

// Function Prototypes

// Singly Node Palindrome functions
void createSinglyNode(string input);
void printSinglyNode(node* head);
bool checkPalindrome(node* head);

// Doubly Node Palindrome functions
void createDoublyNode(string input);
void printDoublyNode(doublyNode* doublyHead);
bool checkPalindrome(doublyNode* head, doublyNode* tail);

// Functions used to determine if singly is a Palindrome
node* findMiddle(node* head, bool &odd);
void reverse(node* &head);
bool compare(node* a, node* b);


int main()
{
	// string to capture input for test
	string input;

	// output explaining singly linked list test and requesting input from user
	cout << "Determine whether the contents of a singly linked list are a palindrome\n";
	cout << "Enter word or numbers to test if a palidrome\n";
	cin >> input;


	//Function to create Singly Linked List based on input
	createSinglyNode(input);
	printSinglyNode(head);
	if (checkPalindrome(head))
		cout << " is a Palindrome" << endl;
	else
		cout << " is NOT a Palindrome" << endl;
	cout << endl;

	
	// output explaining doubly linked list test and requesting input from user
	cout << "Determine whether the contents of a doubly linked list are a palindrome\n";
	cout << "Enter word or numbers to test if a palidrome\n";
	cin >> input;

	// Function to create Doubly Linked List based on input
	createDoublyNode(input);
	printDoublyNode(doublyHead);	
	if (checkPalindrome(doublyHead, doublyTail))
		cout << " is a Palindrome" << endl;
	else
		cout << " is NOT a Palindrome" << endl;
	cout << endl;
	
}

// Singly Node Functions
void createSinglyNode(string input)
{	
	node* curr;
	node* temp;
	int length = input.length();

	head = new node;
	head->data = input[0];
	head->next = NULL;
	temp = head;
	curr = head;

	for (int i = 1; i < length; i++)
	{
		curr = new node;
		curr->data = input[i];
		temp->next = curr;
		temp = temp->next;
	}
	temp->next = NULL;
}

// Prints the Singly Linked List created
void printSinglyNode(node* head)
{
	node* curr = head;
	while (curr->next != nullptr)
	{
		cout << curr->data;
		curr = curr->next;
	}
	cout << curr->data;
}

// Checks to see if List is Palindrome
bool checkPalindrome(node * head)
{
	// Base Case
	if (head == nullptr)
		return true;

	// Flag to indicate if number of nodes in list is odd or not. 
	// Passed to Find Middle Function
	bool odd = false;
	
	// Find second half of the linked list
	node* mid = findMiddle(head, odd);

	// If number of nodes is odd, advance mid
	if (odd)
		mid = mid->next;

	// Reverse the 2nd half
	reverse(mid);
	
	// Compare the 1st and 2nd Half
	return compare(head, mid);
	return false;
}

// Funcion is called in the singly checkPalindro function to find the middle of the string. 
node* findMiddle(node* head, bool &odd)
{
	node* prev = nullptr;
	node *slow = head, *fast = head;

	// Find middle pointer
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	// For odd nodes, fast still points to last node
	if (fast)
		odd = true;

	// Make next of previous node NULL
	prev->next = nullptr;

	// Return mid node
	return slow;
}

// Function reverses the nods of a linked list
void reverse(node* &head)
{
	node* result = nullptr;
	node* current = head;

	while (current != nullptr)
	{
		node* next = current->next;
		current->next = result;
		result = current;
		current = next;
	}
	head = result;
}

// Function compares the 2 halves of the singly list to see if a match
bool compare(node* a, node* b)
{
	// Check if lists are empty
	if (a == nullptr && b == nullptr)
		return true;

	return a && b && (a->data == b->data) && compare(a->next, b->next);
}


// Functions to create the Doubly Nodes
void createDoublyNode(string input)
{
	doublyNode* n;

	int length = input.length();

	n = new doublyNode;
	n->data = input[0];
	n->next = NULL;
	n->prev = NULL;
	doublyHead = n;
	doublyTail = n;
	if (length > 1)
	{
		for (int i = 1; i < length; i++)
		{
			n = new doublyNode;
			n->data = input[i];
			n->prev = doublyTail;
			doublyTail->next = n;
			doublyTail = n;
		}
		doublyTail->next = NULL;
	}
}

// Functions to check if Doubly list is a Palindrome
bool checkPalindrome(doublyNode* head, doublyNode* tail)
{
	bool isPalindrome = true;
	doublyNode* ftemp = head;
	doublyNode* ltemp = tail;
	do
	{
		if (ftemp->data != ltemp->data)
			isPalindrome = false;
		ftemp = ftemp->next;
		ltemp = ltemp->prev;
	} while (ftemp != ltemp && isPalindrome);

	return isPalindrome;
}

// Prints the Doubly list created
void printDoublyNode(doublyNode* doublyHead)
{
	doublyNode* curr = doublyHead;
	while (curr != NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}