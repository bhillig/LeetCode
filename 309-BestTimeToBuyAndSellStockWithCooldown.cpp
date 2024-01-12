// 309 - Best Time to Buy and Sell Stock with Cooldown (LeetCode Exercise)

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

#include <map>
#include <vector>

class Solution 
{
public:

    int dfs(int i, bool buying, std::vector<int>& prices)
    {
        if (i >= prices.size()) return 0;
        if (dp.find({i, buying}) != dp.end()) return dp[{i, buying}];

        int cooldown = dfs(i + 1, buying, prices);

        if (buying)
        {
            int buy = dfs(i + 1, !buying, prices) - prices[i];
            dp[{i, buying}] = std::max(buy, cooldown);
        }
        else
        {
            int sell = dfs(i + 2, !buying, prices) + prices[i];
            dp[{i, buying}] = std::max(sell, cooldown);
        }

        return dp[{i, buying}];
    }

    int maxProfit(std::vector<int>& prices) 
    {
        return dfs(0, true, prices);
    }

    std::map<std::vector<int>, int> dp;
};