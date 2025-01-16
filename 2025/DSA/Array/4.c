/******************************************************************************
https://www.geeksforgeeks.org/maximum-consecutive-ones-or-zeros-in-a-binary-array/
Maximum consecutive one's (or zeros) in a binary array
--------------------------------------------------------
An efficient solution is to traverse the array from left to right. If we see a 1,
we increment the count and compare it with the maximum so far. If we see a 0,
we reset the count as 0.

*******************************************************************************/

#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getMaxLength(int a[], int n)
{
	int count = 0;
	int length = 0;

	for (int i = 0; i<n; i++) {
		// If 1 is found, increment count
		if(a[i] == 1) count++;
		// Reset count when 0 is found
		if(a[i]==0) count = 0;
		length = MAX(count, length);
	}

	return length;
}

int main()
{
	int arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Maximum consecutive 1's : %d\n",getMaxLength(arr, n));

	return 0;
}