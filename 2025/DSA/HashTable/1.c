#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int rem_value = target - nums[i];
            // if rem_value exist in hasmap
            if (numMap.count(rem_value))
            {
                return {numMap[rem_value], i};
            }
            // storing key value pair (key->value)
            //{num->idx} e,g 2->0, 7->1,11->2,15->3
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};
int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution s;
    vector<int> a = s.twoSum(nums, target);
    cout << a[0] << ", " << a[1] << endl;

    return 0;
}