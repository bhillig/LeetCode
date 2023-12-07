// 213 - House Robber 2 (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(1)

// Idea is to recognize that if we rob the first house, we can't rob the last and vice versa
// We can create a helper function which is House Robber I and run the two different possible choices on it

#include <vector>

int houseRob(std::vector<int>& nums, int start, int end)
{
    int robOne = 0;
    int robTwo = 0;

    int maxRob = 0;
    for (int i = start; i <= end; ++i)
    {
        maxRob = std::max(robTwo, robOne + nums[i]);
        robOne = robTwo;
        robTwo = maxRob;
    }

    return maxRob;
}

int rob(std::vector<int>& nums) 
{
    if (nums.size() == 1) return nums[0];

    return std::max(houseRob(nums, 0, nums.size() - 2), houseRob(nums, 1, nums.size() - 1));    
}