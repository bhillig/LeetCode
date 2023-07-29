// 3 - Longest Substring Without Repeating Characters (LeetCode Exercise)

#include <set>
#include <string>
#include <algorithm>

// Time Complexity: O(n) - Iterate linearly through the string
// Space Complexity: O(n) - Worst case is that our set is size of n where n is the size of input string s

// General idea here is to have two pointers (l and r)
// When we find a new letter r, we see if it's in our current substring set
// If it is we keep erasing the leftmost letter in our set and moving the pointer up
// Everytime we add the right most letter, we update our longest length

int lengthOfLongestSubstring(std::string s) 
{
    std::set<char> currentSet;

    int l = 0;
    int longestLength = 0;

    for(int r = 0; r < s.size(); ++r)
    {
        while (currentSet.find(s[r]) != currentSet.end())
        {
            currentSet.erase(s[l]);
            l++;
        }

        currentSet.emplace(s[r]);
        longestLength = std::max(longestLength, (int)currentSet.size());
    }

    return longestLength;
}