// 33 - Search In Rotated Sorted Array (LeetCode Exercise)

//  Main idea behind this algorithm is to see how there are always two sorted portions
//  in a rotated array and to figure out where to move your left and right pointers accordingly

// Time Complexity: O(log(n))
// Space Complexity: O(1)
 
#include <vector>
 
int search(std::vector<int>& nums, int target) 
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int m = l + (r-l)/2;

        if (nums[m] == target) return m;

        // In the left portion
        if (nums[l] <= nums[m])
        {
            if (target > nums[m] || target < nums[l])
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        // In the right portion
        else
        {
            if (target < nums[m] || nums[l] <= target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
    }

    return -1;
}