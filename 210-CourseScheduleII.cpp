// 210 - Course Schedule (LeetCode Exercise)

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <map>
#include <vector>
#include <set>

class Solution 
{
public:

    std::map<int, std::vector<int>> preMap;

    bool dfs(int course, std::set<int>& path, std::set<int>& visited, std::vector<int>& order)
    {
        if (path.find(course) != path.end()) return false;
        if (visited.find(course) != visited.end()) return true;

        path.emplace(course);
        for (int pre : preMap[course])
        {
            if (!dfs(pre, path, visited, order))
            {
                return false;
            }
        }
        path.erase(course);

        order.push_back(course);
        visited.emplace(course);
        return true;
    }

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) 
    {
        std::vector<int> res;

        std::set<int> path;
        std::set<int> visited;

        for (std::vector<int>& pair : prerequisites)
        {
            preMap[pair[0]].push_back(pair[1]);
        }

        for (int course = 0; course < numCourses; ++course)
        {
            
            if(!dfs(course, path, visited, res))
            {
                return {};
            }
        }
        
        return res;
    }
};