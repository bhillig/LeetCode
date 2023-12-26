// 215 - Kth Largest Element in an Array (LeetCode Exercise)

// Avg. Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

int quickSelect(int l, int r, std::vector<int>& nums, int targetIndex)
{
    int pivot = nums[r];
    int p = l;

    for (int i = l; i < r; ++i)
    {
        if (nums[i] <= pivot)
        {
            int temp = nums[p];
            nums[p] = nums[i];
            nums[i] = temp;
            p += 1;
        }
    }

    int temp = nums[r];
    nums[r] = nums[p];
    nums[p] = temp;

    if (p > targetIndex)
    {
        return quickSelect(l, p - 1, nums, targetIndex);
    }
    else if (p < targetIndex)
    {
        return quickSelect(p + 1, r, nums, targetIndex);
    }

    return nums[p];
}

int findKthLargest(std::vector<int>& nums, int k) 
{
    return quickSelect(0, nums.size() -1, nums, nums.size() - k);
}