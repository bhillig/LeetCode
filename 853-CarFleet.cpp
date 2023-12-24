// 853 - Car Fleet (LeetCode Exercise)

// Time Complexity: O(nlog(n))
// Space Complexity: O(n)

#include <vector>
#include <algorithm>

int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) 
{
    std::vector<std::pair<int, float>> pairs;
    for (int i = 0; i < position.size(); ++i)
    {
        pairs.push_back({position[i], (float)(target - position[i]) / speed[i]});
    }    
    std::sort(pairs.begin(), pairs.end(), [](std::pair<int, float>& a, std::pair<int, float>& b)
    {
        return a.first < b.first;
    });

    int numberOfFleets = 0;
    float currTime = 0.f;

    for (int i = pairs.size() - 1; i >= 0; --i)
    {
        if (pairs[i].second > currTime)
        {
            numberOfFleets += 1;
            currTime = pairs[i].second;
        }
    }

    return numberOfFleets;
}