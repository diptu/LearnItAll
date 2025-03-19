/*
88. Merge Sorted Array

https://www.youtube.com/watch?v=TTWKBqG-6IU&t=202s
Initialize three pointers:
m_idx: Points to the last valid element in nums1 (index m - 1).
n_idx: Points to the last element in nums2 (index n - 1).
r: Points to the last position in the merged array nums1 (index m + n - 1).
Handle the edge case where nums2 is empty (n == 0). If it is, no merging is needed, so return.
Merging from the End:

Iterate while both m_idx and n_idx are greater than or equal to 0:
Compare the elements at nums1[m_idx] and nums2[n_idx].
If nums1[m_idx] is greater than nums2[n_idx]:
Place nums1[m_idx] into nums1[r].
Decrement m_idx.
Otherwise (if nums2[n_idx] is greater than or equal to nums1[m_idx]):
Place nums2[n_idx] into nums1[r].
Decrement n_idx.
Decrement r in each iteration.
Copying Remaining Elements from nums2:

After the previous loop, if there are any remaining elements in nums2 (i.e., n_idx is still greater than or equal to 0), copy them into the remaining positions of nums1:
Iterate while n_idx is greater than or equal to 0:
Place nums2[n_idx] into nums1[r].
Decrement n_idx.
Decrement r.
Result:

The nums1 array now contains the merged sorted elements from both nums1 and nums2.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;

        int m_idx = m - 1;
        int n_idx = n - 1;
        int r = m + n - 1;

        while (m_idx >= 0 && n_idx >= 0)
        {
            if (nums1[m_idx] > nums2[n_idx])
            {
                nums1[r] = nums1[m_idx];
                m_idx--;
            }
            else
            {
                nums1[r] = nums2[n_idx];
                n_idx--;
            }
            r--;
        }

        // Copy remaining elements from nums2, if any
        while (n_idx >= 0)
        {
            nums1[r] = nums2[n_idx];
            n_idx--;
            r--;
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}