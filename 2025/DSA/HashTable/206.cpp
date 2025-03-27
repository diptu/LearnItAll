#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int nextNumber(int n)
    {
        int newNumber = 0;
        while (n != 0)
        {
            // Extract the last digit of 'n'.
            int num = n % 10;
            // Add the square of the digit to 'newNumber'.
            newNumber += num * num;
            // Remove the last digit from 'n'.
            n = n / 10;
        }
        return newNumber;
    }

public:
    bool isHappy(int n)
    {
        // Use an unordered_map to detect cycles.
        // The map stores the numbers we've encountered to check for repetition.
        unordered_map<int, int> m;

        // Calculate the next number in the sequence.
        int next_num = nextNumber(n);

        // Continue the loop until 'next_num' becomes 1.
        while (next_num != 1)
        {

            // Check if 'n' has been encountered before.
            if (m.find(n) == m.end())
            {
                // If 'n' is not in the map, store it along with the next number.
                m[n] = next_num;
            }
            else
            {
                // If 'n' is already in the map, it means we've encountered a cycle.
                // This indicates that the number is not happy.
                return false;
            }

            // Move to the next number in the sequence.
            n = next_num;
            next_num = nextNumber(n);
        }

        // If the loop completes and 'next_num' becomes 1,
        // the number is happy.
        return true;
    }
};

int main()
{
    Solution sol;

    cout << sol.isHappy(2) << endl; // Output: 1 (true)

    return 0;
}