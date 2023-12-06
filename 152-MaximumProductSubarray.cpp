// 152 - Maximum Product Subarray (LeetCode Exercise)

// Time Complexity: O(n) as we iterate through nums twice
// Space Complexity: O(1)

#include <vector>

int maxProduct(std::vector<int>& nums) 
{
    int maxProduct = INT_MIN;
    int curMax = 1;

    for (int i = 0; i < nums.size(); ++i)
    {
        curMax *= nums[i];

        maxProduct = std::max(curMax, maxProduct);

        if (curMax == 0)
        curMax = 1;
    }

    curMax = 1;

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        curMax *= nums[i];

        maxProduct = std::max(curMax, maxProduct);

        if (curMax == 0)
            curMax = 1;
    }

    return maxProduct;
}