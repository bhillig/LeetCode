#include <vector>

// Two Sum II - Input Array Is Sorted (LeetCode Exercise)

// Given an array of sorted elements and a target number, return a vector of indices that add up to the target
// Return the indices such that it is 1 indexed and not 0

// {[0, 1, 2, 4, 5], target = 3} -> return [2, 3]

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    // Idea here is to have two pointers, one at the beginning and one at the end
    // Since we have a sorted array of ints, we can trim down the values we need to look at
    // Calculate the sum of the two elements
    //  If the sum is greater move the right index down
    //  If the sum is less move the left index up
    //  Otherwise return the indices

    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int sum = nums[l] + nums[r];
        if (sum > target)
        {
            r--;
        }
        else if (sum < target)
        {
            l++;
        }
        else
        {
            return std::vector<int>{l+1, r+1};
        }
    }

    return {};
}