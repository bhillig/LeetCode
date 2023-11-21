// 55 - Jump Game (LeetCode Exercise)

// Idea behind this algorithm is to start from the endpoint and iterate back to the start
// At each iteraiton if the value at that index plus its current index reaches our goal we update it to that new position

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

bool canJump(std::vector<int>& nums) 
{
    int endPoint = nums.size() - 1;

    for (int index = nums.size() - 2; index >= 0; --index)
    {
        if (index + nums[index] >= endPoint)
        {
            endPoint = index;
        }
    }    

    return endPoint == 0;
}