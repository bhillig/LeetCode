// 424 - Longest Repeating Character Replacement (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <map>
#include <string>

int getMaxElement(std::map<char, int>& map)
{
    std::map<char,int>::iterator max = std::max_element(map.begin(), map.end(), [] (const auto& p1, const auto& p2) 
        {
            return p1.second < p2.second;
        });
    return max->second;
}

int characterReplacement(const std::string& s, int k) 
{
    int maxLength = 0;

    std::map<char, int> count;
    
    int l = 0;
    int r = 0;
    while (r < s.size())
    {
        count[s[r]] += 1;

        while ((r - l + 1) - getMaxElement(count) > k)
        {
            count[s[l]] -= 1;
            l++;
        }

        maxLength = std::max(maxLength, r - l + 1);
        r++;
    }    

    return maxLength;
}