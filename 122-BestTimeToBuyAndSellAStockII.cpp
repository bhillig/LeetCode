// 122 - Best Time To Buy and Sell A Stock II (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

int maxProfit(std::vector<int>& prices) 
{
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i-1])
        {
            maxProfit += prices[i] - prices[i-1];
        }
    }
    return maxProfit;
}