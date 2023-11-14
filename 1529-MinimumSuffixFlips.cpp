// 1529 - Minimum Suffix Flips (LeetCode Exercise)

// This algorithm is given a target string filled with binary digits (0 or 1)
// Given a starter string of all zeros and a flip operation which flips your
// current character and all subsequent characters, return the minimum number of flips needed to match the target string

// General idea for this algorithm is to simulate the flipping of digits through a character variable. This is only possible
// since we know all our characters start at '0' and thus flipping the current char will flip the rest of them to the same 
// value. Utilizing this fact we can simply iterate through target, only flipping when our current char doesn't match the target's.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>

int minFlips(const std::string& target) 
{
    int minFlips = 0;
    char current = '0';

    for(const char& c : target)
    {
        if (current != c)
        {
            minFlips++;
            if (current == '0')
                current = '1';
            else
                current = '0';
        }
    }    

    return minFlips;
}