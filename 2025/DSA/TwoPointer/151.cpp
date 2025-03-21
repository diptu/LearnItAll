
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // Reverse the entire string
        reverse(s.begin(), s.end());
        int n = s.size();
        // nitialize pointers
        int left = 0;
        int right = 0;
        int i = 0;
        while (i < n)
        {
            // Skip leading spaces
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;

            // Identify word boundaries
            while (i < n && s[i] != ' ')
            {
                s[right++] = s[i++];
            }
            // Reverse the current word
            reverse(s.begin() + left, s.begin() + right);
            // Add space after the word
            s[right++] = ' ';
            left = right;
            i++;
        }
        // Resize the string : not to consider trailing spaces
        s.resize(right - 1);
        return s;
    }
};

int main()
{
    Solution s;
    string str = "a good   example";
    cout << s.reverseWords(str) << endl;
    return 0;
}