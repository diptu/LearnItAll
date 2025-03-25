/*
242. Valid Anagram
*/

#include <stdio.h>
#include <string.h>
#define MAX 50001 // string max length
#define SIZE 26   // max lowercase char in english alphabit
int isAnagram(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t)
        return 0;
    int sCount[SIZE] = {0}, tCount[SIZE] = {0};
    for (int i = 0; i < len_s; i++)
    {
        sCount[s[i] - 'a']++;
    }
    for (int i = 0; i < len_t; i++)
    {
        tCount[t[i] - 'a']++;
    }

    for (int i = 0; i < SIZE; i++)

    {
        if (sCount[i] != tCount[i])
            return 0;
    }
    return 1;
}

int main()
{
    char s[] = "rat", t[] = "car";
    printf("%d", isAnagram(s, t));
    return 0;
}