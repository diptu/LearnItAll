/*
189. Rotate Array
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();
        k = k % n;

        // reverse full array
        reverse(nums.begin(), nums.end());

        // reverse first k element in array
        reverse(nums.begin(), nums.begin() + k);

        // reverse remaining n-k element in array
        reverse(nums.begin() + k, nums.end());
    }
};

int main()

{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution s;
    s.rotate(nums, k);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    return 0;
}