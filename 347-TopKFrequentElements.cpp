// 347 - Top K Frequent Elements (LeetCode Exercise)

#include <vector>
#include <unordered_map>
#include <set>

// Helper comparator function to sort pairs
bool cmp(std::pair<int, int>& a,
        std::pair<int, int>& b)
{
    return a.second > b.second;
}

// Time Complexity: O(nlogn) - Sorting takes O(nlogn) which is the bottleneck of this algorithm, creating
//                              the map is done in O(n) time as is creating the pairs.

// Space Complexity: O(n) - We create a map of size n and a vector of pairs of size n where n is the size of nums given

std::vector<int> topKFrequent(std::vector<int>& nums, int k) 
{
    std::unordered_map<int, int> map;
    for (auto num : nums)
    {
        if (map.find(num) != map.cend())
        {
            map[num] += 1;
        }
        else
        {
            map.emplace(std::make_pair(num, 1));
        }
    }

    // Declare vector of pairs
    std::vector<std::pair<int, int> > pairs;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto it : map) 
    {
        pairs.push_back(it);
    }

    // Sort using comparator function
    std::sort(pairs.begin(), pairs.end(), cmp);

    std::vector<int> result;
    for (std::size_t i = 0; i < k; ++i)
    {
        // Find the ith most frequent number
        result.push_back(pairs[i].first);
    }

    return result;
}