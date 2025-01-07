/*
Trird Largest Element in an Array
- Given an array of positive integers arr[] of size n, the task is to find
second largest distinct element in the array.

Note: If the trird largest element does not exist, return -1.
=====================================
[Expected Approach] One Pass Search – O(n) Time and O(1) Space
The idea is to keep track of the largest and second largest element while traversing the array. Initialize largest and second largest with -1. Now, for any index i,


Create three variables, first, second, third, to store indices of three largest elements of the array. (Initially all of them are initialized to a minimum value).
Move along the input array from start to the end.
For every index check if the element is larger than first or not. Update the value of first, if the element is larger, and assign the value of first to second and second to third. So the largest element gets updated and the elements previously stored as largest becomes second largest, and the second largest element becomes third largest.
Else if the element is larger than the second, then update the value of second,and the second largest element becomes third largest.
If the previous two conditions fail, but the element is larger than the third, then update the third.
Print the value of third after traversing the array from start to end
credits:

[^1]: geeksforgeeks. *Article Title*. *Top 50 Array Coding Problems for Interviews*, *Second Largest Element in an Array*.

*/

int findTrirdLargest(int arr[], int N)
{
    int largest = -1, second_largest = -1, third_largest = -1;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] > largest)
        {
            third_largest = second_largest;
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest)
        {
            third_largest = second_largest;
            second_largest = arr[i];
        }
        else if (arr[i] > third_largest)
        {
            third_largest = arr[i];
        }
    }
    return third_largest;
}

#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int res = findTrirdLargest(arr, N);
    printf("Third largest element : %d\n", res);
    return 0;
}