/******************************************************************************
https://www.geeksforgeeks.org/move-zeroes-end-array/
Move all zeros to end of array:
Given an array of integers arr[], the task is to move all the zeros to the end
of the array while maintaining the relative order of all non-zero elements.
--------------------------------------------------------
An efficient solution is took a pointer, say count to track where the next non-zero
element should be placed. However, on encountering a non-zero element, instead of
directly placing the non-zero element at arr[count], we will swap the non-zero
element with arr[count]. This will ensure that if there is any zero present at
arr[count], it is pushed towards the end of array and is not overwritten.

*******************************************************************************/

#include <stdio.h>

void pushZerosToEnd(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 0)
		{
			int temp = a[i];
			a[i] = a[count];
			a[count] = temp;
			count++;
		}
	}
}

int main()
{
	int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	pushZerosToEnd(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}