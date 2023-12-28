// 973 - K Closest Points To Origin (LeetCode Exercise)

// Time Complexity: O(nlog(n))
// Space Complexity: O(n)

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) 
{
    std::vector<std::vector<int>> ans;
    std::vector<std::pair<int, std::vector<int>>> v; 

    for (auto& point : points)
    {
        int distSquared = point[0] * point[0] + point[1] * point[1];
        v.push_back({distSquared, point});
    }

    std::sort(v.begin(), v.end());

    int index = 0;
    while(k > 0)
    {
        ans.push_back(v[index].second);
        index++;
        k--;
    }

    return ans; 
}