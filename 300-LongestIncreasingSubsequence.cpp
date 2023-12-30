// 300 - Longest Increasing Subsequence (LeetCode Exercise)

// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>

int lengthOfLIS(std::vector<int>& nums) 
{
    if (nums.empty()) return 0;

    std::vector<int> LIS(nums.size(), 1);

    for (int i = nums.size() - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] < nums[j])
            {
                LIS[i] = std::max(LIS[i], 1 + LIS[j]);
            }
        }
    }

    return *std::max_element(LIS.begin(), LIS.end());
}