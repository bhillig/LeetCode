// 91 - Decode Ways (LeetCode Exercise)

// First Solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

// Second Solution:
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <vector>

// First solution
int numDecodings2(std::string s) 
{
    int n = s.size();
    std::vector<int> dp(n+1, 0);

    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i)
    {
        // Single digit case
        if (s[i] != '0')
            dp[i] += dp[i + 1];
        // Two digit case
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && (s[i+1] >= '0' && s[i+1] <= '6'))))
        {
            dp[i] += dp[i+2];
        }
    }

    return dp[0];
}

// Second Solution (Optimized for space)
int numDecodings(std::string s) 
{
    int dp = 0;
    int dp1 = 1;
    int dp2 = 0;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        // Single digit case
        if (s[i] != '0')
            dp += dp1;
        // Two digit case
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && (s[i+1] >= '0' && s[i+1] <= '6'))))
        {
            dp += dp2;
        }
        dp2 = dp1;
        dp1 = dp;
        dp = 0;
    }

    return dp1;
}