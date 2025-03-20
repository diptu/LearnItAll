#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        bool isPalindrome = true;
        int i = 0;
        int j = 0;
        while (s[i] != '\0')
        {
            char ch = tolower(s[i]);
            if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {
                s[j++] = ch;
            }
            i++;
        }
        // string with only spaces e,g " ";
        if (j == 0)
            j++;

        int end = j - 1; // point to last index.

        for (int k = 0; k <= end / 2; k++)
        {
            if (s[k] != s[end - k])
            {
                isPalindrome = false;
                break;
            }
        }

        return isPalindrome;
    }
};

int main()
{
    string str = "A man, a plan, a canal: Panama";
    Solution s;
    if (s.isPalindrome(str))
        cout << true << endl;
    else
        cout << false << endl;
    return 0;
}