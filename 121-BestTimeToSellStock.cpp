#include <vector>

// The idea behind this algorithm is to keep track of two pointers
// One representing the current buy date and another the sell date
// We want to iterate our right pointer at each iteration and check
// if the prices is lower than our current buy price, if so move it.
// If it's not we want to calculate the max profit if we bought at l
// and sold at r and overrwrite our max profit if it's higher

// Time Complexity: O(n) - we iterate through the array once
// Space Complexity: O(1) - no matter the input size, we only keep track of l, r, and currentMaxProfit

int getMaxProfit(std::vector<int>& prices)
{
    int l = 0;
    int r = 1;

    int currentMaxProfit = 0;

    while(r < prices.size())
    {
        if (prices[r] <= prices[l])
        {
            l = r;
        }
        else
        {
            currentMaxProfit = std::max(currentMaxProfit, prices[r] - prices[l]);
        }

        r++;
    }

    return currentMaxProfit;
}