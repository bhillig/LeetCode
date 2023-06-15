#include <string>
#include <unordered_map>

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
bool isAnagram(std::string s, std::string t) 
{

    if(s.size() != t.size()) return false;

    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> tMap;

    // For every character in s and t:
    //  If that character isn't in the map, add it
    //  If it is in the map, set the occurence += 1
    // At the end check if the two maps are equal

    for(size_t i = 0; i < s.size(); ++i)
    {
        if (sMap.find(s[i]) != sMap.cend())
        {
            // Increment the occurence by 1
            sMap[s[i]] += 1;
        }
        else
        {
            // Add it to the map
            sMap.emplace(std::make_pair(s[i], 1));
        }
    }

    for(size_t j = 0; j < t.size(); ++j)
    {
        if (tMap.find(t[j]) != tMap.cend())
        {
            tMap[t[j]] += 1;
        }
        else
        {
            tMap.emplace(std::make_pair(t[j], 1));
        }
    }

    return sMap == tMap;
}