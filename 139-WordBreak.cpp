// 139 - Word Break (LeetCode Exercise)

// Time Complexity: O(n * m) where n is the len of s and m is len of wordDict
// Space Complexity: O(n)

#include <vector>
#include <string>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) 
{
    std::vector<bool> dp(s.size() + 1, false);
    dp[s.size()] = true;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        for (const std::string& word : wordDict)
        {
            if (i + word.size() > s.size()) continue;

            if (word == std::string(s.begin() + i, s.begin() + i + word.size()))
            {
                dp[i] = dp[i + word.size()];
                if (dp[i]) break;
            }
        }
    }

    return dp[0];
}