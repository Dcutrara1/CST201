// Problem_9.7.6.cpp : This file contains the 'main' function. 
// Name:		Daniel Cutrara
// Class:		CST-201
// Prof:		Bradley Mauger
// Date:		3/17/2019


// Normal insertion sort, it takes O(n) comparisons(at nth iteration) in worst case. 
// Binary insertion sort, using  binary search to find the proper location to insert the element reduces it to O(log n).

#include "pch.h"
#include <iostream>
using namespace std;

void insertionSort(int a[], int n);
int binarySearch(int a[], int item, int low, int high);

int main()
{
	int a[] = { 37, 25, 7, 47, 12, 27, 33, 48, 101, 89, 52 };
	int n = sizeof(a) / sizeof(a[0]), i;

	cout << "Original array: \n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
	
	insertionSort(a, n);

	cout << "Sorted array: \n";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;

	system("pause");
}

// A binary search based function to find the position where item should be inserted in a[low..high] 
int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}

// Function to sort an array a[] of size 'n' 
void insertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		// find location where selected sould be inseretd 
		loc = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space 
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}