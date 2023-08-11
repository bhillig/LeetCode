// 746 - Min Cost Climbing Stairs (LeetCode Exercise)

// Time Complexity: O(n) - Linearly traverse through the vector given 

// Space Complexity: O(1) - Constant amount of space used not linked to input

#include <vector>
#include <algorithm>

int minCostClimbingStairs(std::vector<int>& cost) 
{
    for(int step = cost.size() - 3; step >= 0; step--)
    {
        cost[step] += std::min(cost[step+1], cost[step+2]);
    }

    return std::min(cost[0], cost[1]);
}