#include <unordered_set>
#include <vector>

// Brute Force:
//  For every element in nums:
//      Iterate over all other elements and see if there is a match

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Better Approach:
//  Create a set of integers
//  For every element in nums:
//      if that element is already in the set, return true
//      else add the element to the set
//  If the for loop completes, return false as no match was found

// Time Complexity: O(n) - Linearly iterate over nums once
// Space Complexity: O(n) - Worst case is the set created contains n elements

bool containsDuplicate(std::vector<int>& nums)
{
    std::unordered_set<int> set;

    for(int num : nums)
    {
        if(set.find(num) != set.cend())
        {
            return true;
        }

        set.emplace(num);
    }

    return false;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    containsDuplicate(v);
}