/*
https://www.youtube.com/watch?v=Gtugy3mRV-A
*/

#include <stdio.h>
int canJump(int *nums, int numsSize)
{
    int initilize_idx = 0;
    int dest_idx = numsSize - 1;
    // starts with second last index
    // and move twoards initilize_idx
    for (int i = dest_idx - 1; i >= 0; i--)
    {

        // can we reach final position
        // from current position
        int jump = nums[i];
        if (i + jump >= dest_idx)
            // move the destination to left
            dest_idx = i;
    }
    // if we can reach to initilize_idx
    // jump to dest_idx possile
    return (dest_idx == initilize_idx);
}
int main()
{
    int nums[] = {2, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    if (canJump(nums, numsSize))
        printf("true");
    else
        printf("false");

    return 0;
}
