// 494 - Target Sum (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <map>

class Solution 
{
public:

    int backtrack(int i, int total)
    {
        if (i == nums.size())
        {
            return total == target ?  1 :  0;
        }
        if (dp.find({i, total}) != dp.end())
        {
            return dp[{i, total}];
        }

        dp[{i, total}] =    backtrack(i+1, total+nums[i]) +
                            backtrack(i+1, total-nums[i]);
        return dp[{i, total}];
    }

    int findTargetSumWays(std::vector<int>& nums, int target) 
    {
        this->target = target;
        this->nums = nums;
        return backtrack(0, 0);
    }

    std::vector<int> nums;
    int target;
    std::map<std::vector<int>, int> dp;
};