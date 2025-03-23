#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {

        int len = s.size();
        int res = 0;
        // Create an unordered_map
        unordered_map<char, int> umap;
        // Insert key-value pairs into the unordered_map
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;

        for (int i = 0; i < len; i++)
        {

            // descring order
            if (umap[s[i]] >= umap[s[i + 1]])
            {

                res += umap[s[i]];
            }
            // incring order
            else if (umap[s[i]] <= umap[s[i + 1]])
            {

                res -= umap[s[i]];
            }
        }

        return res;
    }
};
int main()
{
    string s = "LVIII"; // L = 50, V= 5, III = 3, output = 58
    Solution sol;
    cout << sol.romanToInt(s) << endl;
    return 0;
}