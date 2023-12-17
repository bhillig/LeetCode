// 647 - Palindromic Substrings (LeetCode Exercise)

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <string>

int countSubstrings(std::string s) 
{
    int count = 0;

    int l = 0;
    int r = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        // Count the number of odd length palindromes
        l = i;
        r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            count += 1;
            l -= 1;
            r += 1;
        }

        // Count the number of even length palindromes
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            count += 1;
            l -= 1;
            r += 1;
        }
    }    

    return count;
}