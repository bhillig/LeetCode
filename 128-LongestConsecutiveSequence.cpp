// 128 - Longest Consecutive Sequence (LeetCode Exercise)

// Main idea behind this algorithm is to first convert the array into a set so I can utilize constant lookup times
// I then iterate over the set and identify the beginning of a sequence by checking if the number before it is not present
// I then start a loop to count how long this sequence goes on for.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <set>

int longestConsecutive(std::vector<int>& nums) 
{
    std::set<int> numSet;
    for (int num : nums)
    {
        numSet.emplace(num);
    }

    int longestSequence = 0;

    for(int num : numSet)
    {
        // If we have found the start of a sequence
        if (numSet.find(num-1) == numSet.end())
        {
            int currentValue = num;
            int sequenceLength = 1;
            while (numSet.find(++currentValue) != numSet.end())
            {
                sequenceLength++;
            }

            longestSequence = std::max(longestSequence, sequenceLength);
        }
    }
    
    return longestSequence;
}