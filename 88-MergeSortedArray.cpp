// 88 - Merge Sorted Array (LeetCode Exercise)

// Time Complexity: O(n + m)
// Space Complexity: O(n) but can be improved to be done in place at O(1)

#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
{
    int l = 0;
    int r = 0;

    std::vector<int> nums;
    while (l < m && r < n)
    {
        if (nums1[l] <= nums2[r])
        {
            nums.push_back(nums1[l]);
            l++;
        }
        else
        {
            nums.push_back(nums2[r]);
            r++;
        }
    }    

    while (l < m)
    {
        nums.push_back(nums1[l]);
        l++;
    }

    while (r < n)
    {
        nums.push_back(nums2[r]);
        r++;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        nums1[i] = nums[i];
    }
}