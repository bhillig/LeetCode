#include <algorithm>
#include <vector>

/* 153 - Find Minimum In Rotated Sorted Array */

/* The idea here is to utilize the knowledge of the input being sorted but rotated */
/* This guarantees there is a pivot point where a left element is greater than its right element otherwise it is sorted */
/* Utilizing binary search we can check if we are to the left of the pivot, if we are we want to search right and vice versa */
/* At each step we check if the new element is the smallest so far and update our return variable */


/* Time complexity: O(log(n)) */
/* Space complexity: O(1) */

int findMin(vector<int>& nums) 
{
    int min = nums[0];

    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        /* If already sorted */
        if (nums[l] <= nums[r])
        {
            min = std::min(min, nums[l]);
            break;
        }

        int m = l + (r-l)/2;
        min = std::min(min, nums[m]);

        if (nums[m] >= nums[l])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }    

    return min;
}