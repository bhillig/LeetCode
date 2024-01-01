// 1143 - Longest Common Subsequence (LeetCode Exercise)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <string>
#include <vector>

int longestCommonSubsequence(const std::string& text1, const std::string& text2) 
{
    const int ROWS = text1.size() + 1;
    const int COLS = text2.size() + 1;
    std::vector<std::vector<int>> dp(ROWS, std::vector<int>(COLS, 0));

    for(int r = ROWS - 2; r >= 0; --r)
    {
        for (int c = COLS - 2; c >= 0; --c)
        {
            if (text1[r] == text2[c])
            {
                dp[r][c] = 1 + dp[r+1][c+1]; 
            }
            else
            {
                dp[r][c] = std::max(dp[r+1][c], dp[r][c+1]);
            }
        }
    }    

    return dp[0][0];
}