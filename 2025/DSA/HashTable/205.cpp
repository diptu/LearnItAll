/*
205. Isomorphic Strings
Hash Maps – O(n) Time and O(MAX_CHAR) Space
MAX_CHAR is maximum number of different characters in the two strings. If we talk about lower case alphabet, then its value is 26

The idea is based on the fact that all occurrences of two characters should be at same index. We mainly store the first index of every character and for remaining occurrences, we check if they appear at same first index too.

We mainly use two maps m1 and m2 to store characters as keys and their first indexes as values.

If the lengths of s1 and s2 are not same, return false.
Do the following for every character in s1 and s2.
If this character is seen first time in s1, then store is index in map m1.
If this character is seen first time in s2, then store is index in map m2.
If indexes in map for both the characters do not match, return false.
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 256 // SIZE is maximum number of different characters in the two strings
bool isIsomorphic(string s, string t)
{

    if (s.length() != t.length())
        return false;

    unordered_map<char, int> m1, m2;

    for (int i = 0; i < s.length(); ++i)
    {

        // If character not seen before,
        if (m1.find(s[i]) == m1.end())
        {
            // store its  first occurrence index
            m1[s[i]] = i;

            // m1 hash table
            // 'a' : 0
            // b : 2
        }

        // If character not seen before,
        if (m2.find(t[i]) == m2.end())
        {
            // store its  first occurrence index
            m2[t[i]] = i;

            // m2 hash table
            // 'x' : 0
            // y : 2
        }

        // Check if the first occurrence indices match
        if (m1[s[i]] != m2[t[i]])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s = "aab", t = "xxy";

    cout << isIsomorphic(s, t);

    return 0;
}
