#include <vector>

// Binary search can be applied on any list that is sorted
// We first check the middle of the range of values and compare it to our target
// If the target is greater, we search the upper half
// Else if the target is less, we search the bottom half
// Else we return the target
// If l is no longer <= r, that means we have searched through all valid elements
// We return -1 in this case

// Time Complexity: O(log(n)) - We divide our problem set in half each time
// Space Complexity: O(1) - For any size n, we will always just have l, r, and m

int search(std::vector<int>& nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int m;

    while (l <= r)
    {
        m = l + (r-l) / 2;

        if(target > nums[m])
        {
            l = m + 1;
        }
        else if (target < nums[m])
        {
            r = m - 1;
        }
        else
        {
            return m;
        }
    }

    return -1;
}