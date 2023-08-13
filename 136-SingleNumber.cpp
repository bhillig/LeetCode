// 136 - Single Number (LeetCode Exercise)

// Time Complexity: O(n) - Linearly iterate through nums

// Space Complexity: O(1) - Constant space no matter the input

#include <vector>

int singleNumber(std::vector<int>& nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        result ^= nums[i];
    }
    return result;
}