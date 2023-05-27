#include <unordered_map>
#include <vector>

// Brute Force:
//  For every element in nums:
//      Iterate over every other element
//          if the sum of the two elements equal target, return the indices
//  If we reach the end return an empty vector

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Better Approach:
//  Create a map that maps ints to ints
//  The first int will be the value (ie nums[i]) which will map to the index it was discoverd
//  For every element in nums:
//      Calculate the desired compliment needed to reach target
//      If that value is in our map, return the two indices
//      Else add this value and its index to our map
//  If we reach the end return an empty vector

// Time Complexity: O(n)
// Space Complexity: O(n)

// Takeaway: If we trade a little bit of memory to create a map (worst at size n), we can
// utilize the instant lookups a map provides (thanks to hashing) to only iterate through once

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> map;
    std::vector<int> result;

    for(int i = 0; i < nums.size(); ++i)
    {
        int desiredCompliment = target - nums[i];
        
        if (map.find(desiredCompliment) != map.cend())
        {
            result.push_back(i);
            result.push_back(map[desiredCompliment]);
            return result;
        }

        map.emplace(std::make_pair(nums[i], i));
    }

    return result;
}