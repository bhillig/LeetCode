// 238 - Product of Array Except Self (LeetCode Exercise)

// Time Complexity: O(n) - Linearly traverse through the array of nums doing constant work each time
// Space Complexity: O(n) - Create a vector of size n where n is the number of elements in nums

#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) 
{
    int n = nums.size();
    std::vector<int> ans(n,1);
    
    int suf = 1;
    int pre = 1;
    for(int i = 0; i < nums.size(); i++) 
    {
        ans[i] *= pre;        
        ans[n-1-i] *= suf;      
        pre *= nums[i];			
        suf *= nums[n-1-i];
    }
    return ans;
}