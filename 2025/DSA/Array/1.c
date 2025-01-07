/*
Second Largest Element in an Array
- Given an array of positive integers arr[] of size n, the task is to find
second largest distinct element in the array.

Note: If the second largest element does not exist, return -1.
=====================================
[Expected Approach] One Pass Search – O(n) Time and O(1) Space
The idea is to keep track of the largest and second largest element while traversing the array. Initialize largest and second largest with -1. Now, for any index i,


If arr[i] > largest, update second largest with largest and largest with arr[i].
Else If arr[i] < largest and arr[i] > second largest, update second largest with arr[i].

credits:

[^1]: geeksforgeeks. *Article Title*. *Top 50 Array Coding Problems for Interviews*, *Second Largest Element in an Array*.

*/

int findSecondLargest(int arr[], int N)
{
    int largest = -1, second_largest = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int res = findSecondLargest(arr, N);
    printf("Second largest element : %d\n", res);
    return 0;
}