// 322 - Coin Change (LeetCode Exercise)

// Time Complexity: O(amount * len(coins))
// Space Complexity: O(amount)

#include <vector>

int coinChange(std::vector<int>& coins, int amount) 
{
    std::vector<int> dp;
    dp.resize(amount + 1);
    std::fill_n(dp.begin(), dp.size(), INT_MAX - 1);

    dp[0] = 0;

    for (int a = 1; a < amount + 1; ++a)
    {
        for (int coin : coins)
        {
            if (a - coin >= 0)
                dp[a] = std::min(dp[a], 1 + dp[a - coin]);
        }
    }

    if (dp[amount] == INT_MAX - 1)
    {
        return -1;
    }

    return dp[amount];
}