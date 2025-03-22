class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long long int n = x, reverse = 0;

        while (n != 0)
        {
            long long int rem = n % 10;
            reverse = reverse * 10 + rem;
            n /= 10;
        }

        return (reverse == x);
    }
};