#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string romanToInt(int num)
    {

        string s = "";
        // Create an unordered_map
        unordered_map<int, string> umap;
        // Insert key-value pairs into the unordered_map
        umap[1] = "I";
        umap[4] = "IV";
        umap[5] = "V";
        umap[9] = "IX";
        umap[10] = "X";
        umap[40] = "XL";
        umap[50] = "L";
        umap[90] = "XC";
        umap[100] = "C";
        umap[400] = "CD";
        umap[500] = "D";
        umap[900] = "CM";
        umap[1000] = "M";
        vector<int> v = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
        {
            int temp = v[i];
            int count = num / temp;
            while (count--)
            {
                s += umap[temp];
                num -= temp;
            }
        }

        return s;
    }
};
int main()
{
    int num = 58; // L = 50, V= 5, III = 3, output = "LVIII"
    Solution sol;
    cout << sol.romanToInt(num) << endl;
    return 0;
}