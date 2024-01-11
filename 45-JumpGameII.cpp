// 45 - Jump Game II (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

int jump(std::vector<int>& nums) 
{
    int l = 0;
    int r = 0;

    int minJumps = 0;

    while (r < nums.size() - 1)
    {
        int farthest = 0;
        for (int i = l; i <= r; ++i)
        {
            farthest = std::max(i + nums[i], farthest);
        }


        minJumps++;
        l = r + 1;
        r = farthest;
    }

    return minJumps;
}