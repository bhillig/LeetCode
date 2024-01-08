// 416 - Partition Equal Subset Sum (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <set>

bool canPartition(std::vector<int>& nums) 
{
    int sum = 0;
    for (int num : nums)
        sum += num;
    
    // If the sum is odd, it's not possible to partition the array into equal sums
    if (sum % 2) return false;

    int target = sum / 2;

    std::set<int> possibleSums = {};
    possibleSums.emplace(0);

    for (int i = nums.size() - 1; i >= 0; --i)
    {
        std::set<int> newSums = {};

        // Add every possible new sum with nums[i]
        for (int sum : possibleSums)
        {
            if (possibleSums.find(nums[i] + sum) == possibleSums.end())
            {
                newSums.emplace(nums[i] + sum);
            }
        }
        for (int sum : newSums)
            possibleSums.emplace(sum);

        // Check if the target has been found
        if (possibleSums.find(target) != possibleSums.end()) return true;
    }

    return false;
}