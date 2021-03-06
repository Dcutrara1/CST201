// Problem_9.7.10.cpp : This file contains the 'main' function.
// Name:		Daniel Cutrara
// Class:		CST-201
// Prof:		Bradley Mauger
// Date:		03/17/2019

#include "pch.h"
#include <iostream>
#include<stdlib.h> 
#include<stdio.h> 

using namespace std;

void merge(int arr[], int left, int middle, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int A[], int size);

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);

	system("pause");
}

// Create a left and a right array to be sorted
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		// Sort first and second halves 
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}

// Merges two subarrays created 
void merge(int arr[], int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// create temp arrays
	int Left[sizeof(n1)], Right[sizeof(n2)];

	// Copy data to temp arrays Left[] and Right[] 
	for (i = 0; i < n1; i++)
		Left[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[middle + 1 + j];

	// Merge the temp arrays back into original array
	i = 0; // Initial index of left array 
	j = 0; // Initial index of right array  
	k = left; // Initial index of merged array 
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of Left[]
	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	// Copy the remaining elements of Right[]
	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}

// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << A[i];
		cout << endl; 
}