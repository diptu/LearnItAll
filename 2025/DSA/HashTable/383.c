#include <stdio.h>
#include <string.h>
#define SIZE 26 // lowercase English letters.
int canConstruct(char *ransomNote, char *magazine)
{

    int len_ransome = strlen(ransomNote);
    int len_magazine = strlen(magazine);
    int a[SIZE] = {0};

    // increment the value of each char index
    for (int i = 0; i < len_ransome; i++)
        a[ransomNote[i] - 'a']++;

    // deccrement the value of each char index
    for (int i = 0; i < len_magazine; i++)
    {
        a[magazine[i] - 'a']--;
    }

    for (int i = 0; i < SIZE; i++)
        if (a[i] > 0)
            return 0;

    return 1;
}

int main()
{

    char ransomNote[] = "a", magazine[] = "b";
    int res = canConstruct(ransomNote, magazine);
    printf("%d", res);
    return 0;
}