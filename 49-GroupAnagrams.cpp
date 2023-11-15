// 49 - Group Anagrams (LeetCode Exercise)

// General idea is to map an int array storing the counts of each character to a vector of strings which match that array
// by nature these grouped strings would be anagrams. Alternatively I could've sorted each string that came in and used that as a key but
// for larger inputs that nlog(n) for sorting adds up compared to this linear computation of the char count.

// Time Complexity: O(m * n) where m is the size of the array, and n is the average size of a string
// Space Complexity: O(26 * m) in the worst case

#include <vector>
#include <string>
#include <array>
#include <map>

typedef std::array<unsigned int, 26> alphabet;

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
{
    std::map<alphabet, std::vector<std::string>> map;

    for(auto& s : strs)
    {
        alphabet count = {};

        for(char c : s)
        {
            count[c - 'a'] += 1;
        }

        map[count].push_back(s);
    }

    std::vector<std::vector<std::string>> anagrams;
    for (auto& [arr, vec] : map)
    {
        anagrams.push_back(vec);
    }
    return anagrams;

}