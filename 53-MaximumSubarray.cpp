// 53 - Maximum Subarray (LeetCode Exercise)

// Brute force takes O(n^2) time, but we can utilize a greedy algorithm technique
// to solve this problem in linear time 

// Worst Case Time Complexity: O(n)
// Worst Case Space Complexity: O(1)

#include <vector>

int maxSubArray(std::vector<int>& nums) 
{
    int maxSum = nums[0];
    int curSum = 0;
    
    for (int num : nums)
    {
        if (curSum < 0)
            curSum = 0;
        
        curSum += num;
        maxSum = std::max(curSum, maxSum);
    }

    return maxSum;
}