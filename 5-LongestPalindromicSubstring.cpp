// 5 - Longest Palindromic Substring (LeetCode Exercise)

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <string>

std::string longestPalindrome(std::string s) 
{
    std::string res;
    int longestLength = 0;
    int currentLength = 0;

    int l = 0;
    int r = 0;
    
    for (int index = 0; index < s.size(); ++index)
    {
        l = index;
        r = index;

        // Odd length strings
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            currentLength = r - l + 1;
            if (currentLength > longestLength)
            {
                res = std::string(s.begin() + l, s.begin() + r + 1);
                longestLength = currentLength;
            }
            l--;
            r++;
        }

        l = index;
        r = index + 1;

        // Even length strings
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            currentLength = r - l + 1;
            if (currentLength > longestLength)
            {
                res = std::string(s.begin() + l, s.begin() + r + 1);
                longestLength = currentLength;
            }
            l--;
            r++;
        }   
    
    }
    
    return res;
}