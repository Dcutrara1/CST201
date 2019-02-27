#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class T>
class Stack : public stack<T>
{
public:
	Stack();
	
	T pop() 
	{ 
		T tmp = top(); 
		stack<T>::pop(); 
		return tmp;
	}
};

template<class T>
inline Stack<T>::Stack()
{
}
