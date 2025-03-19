#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int i = 0;

        for (auto n : nums)
        {
            // First 2 element don't need to consider
            // as maximum 2 occurence are allowed
            // if current element hasn't occcur twice before
            if (i == 0 || i == 1 || nums[i - 2] != n)
            {
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};

int main()

{
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    Solution s;
    int k = s.removeDuplicates(nums);

    for (int i = 0; i < k; i++)
        cout << nums[i] << " ";
    cout << "\nk : " << k << endl;
    return 0;
}