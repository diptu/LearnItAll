#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        int end_idx = s.size() - 1, len = 0, is_last_char = 0;
        for (int i = end_idx; i >= 0; i--)
        {
            if (s[i] == ' ' && is_last_char)
                break;
            if (s[i] != ' ')
            {
                len++;
                is_last_char = 1;
            }
        }
        return len;
    }
};

int main()
{
    string s = "a ";

    Solution sol;
    int k = sol.lengthOfLastWord(s);
    cout << "Length: " << k << endl;

    return 0;
}