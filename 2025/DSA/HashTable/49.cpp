#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // Map to store sorted string (key) and its anagrams (value).
        unordered_map<string, vector<string>> m;

        // Iterate through each word in the input vector.
        for (auto word : strs)
        {
            string temp = word;             // Store the original word.
            sort(word.begin(), word.end()); // Sort the word to get its canonical form.
            m[word].push_back(temp);        // Add the original word to the corresponding anagram group.
        }

        // Vector to store the result (groups of anagrams).
        vector<vector<string>> res;

        // Iterate through the map and add each group of anagrams to the result.
        for (auto it = m.begin(); it != m.end(); it++)
        {
            res.push_back(it->second); // Add the vector of anagrams to the result.
        }

        return res; // Return the result.
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> v = sol.groupAnagrams(strs); // Get the grouped anagrams.

    // Print the result correctly.
    for (const auto &group : v)
    {
        cout << "["; // Start of the group.
        for (size_t i = 0; i < group.size(); ++i)
        {
            cout << "\"" << group[i] << "\""; // Print the string with quotes.
            if (i < group.size() - 1)
            {
                cout << ","; // Add comma if not the last string.
            }
        }
        cout << "]" << endl; // End of the group.
    }

    return 0;
}