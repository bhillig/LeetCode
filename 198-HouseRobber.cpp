// 198 - House Robber (LeetCode Exercise)

// Time Complexity: O(n) - Iterate linearly through input vector
// Space Complexity: O(1) - Constant space no matter the input

// General idea is to understand we can't rob adjacent houses so we must
// consider either taking the house we currently are at plus the house two houses back
// or just the current house

// We use this base case to build up our max profit

#include <vector>
#include <algorithm>

int rob(std::vector<int>& nums) 
{
    int rob1 = 0;
    int rob2 = 0;
    for(int num : nums)
    {
        int temp = std::max(num+rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }    
   
    return rob2;
}

/* Algorithm in motion: */
    /* At 9: rob1 = 0, rob2 = 9 */
    /* At 3: rob1 = 9, rob2 = 9 */
    /* At 5: rob1 = 9, rob2 = 14 */
    /* At 9: rob1 = 14, rob2 = 18 */