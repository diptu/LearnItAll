/*
26. Remove Duplicates from Sorted Array

Algorithm Steps:

Initialization:
Initialize k to 1. k represents the index where the next unique element will be placed, and also the count of unique elements so far. Since the first element is always considered unique, we start with k = 1.
Initialize len to the size of the input vector nums.
Iteration:
Iterate through the array nums starting from the second element (index j = 1) up to the last element (index len - 1).
Duplicate Check:
For each element nums[j], compare it with the previous unique element nums[k - 1].
If nums[j] is different from nums[k - 1], it means we have found a new unique element.
Placement of Unique Element:
If nums[j] is unique:
Place nums[j] at the k-th position in the array nums: nums[k] = nums[j].
Increment k to point to the next available position for a unique element.
Return Unique Element Count:
After the loop finishes, k will hold the number of unique elements in the array.
Return k
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int k = 1;
        int len = nums.size();
        for (int j = 1; j < len; j++)
        {
            if (nums[j] != nums[k - 1])
            {
                nums[k] = nums[j];
                k++;
            }
        }

        return k;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 0, 0, 0};

    Solution sol;
    int k = sol.removeDuplicates(nums);
    cout << k << endl;

    return 0;
}