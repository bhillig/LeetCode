// 207 - Course Schedule (LeetCode Exercise)

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <vector>
#include <set>
#include <map>

bool canComplete(int course, std::map<int, std::vector<int>>& preMap, std::set<int>& visited)
{
    if (visited.find(course) != visited.end()) return false;

    if (preMap[course].empty()) return true;

    visited.emplace(course);
    for (int pre : preMap[course])
    {
        if (!canComplete(pre, preMap, visited)) return false;
    }
    visited.erase(visited.find(course));

    preMap[course] = {};
    return true;
}

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) 
{
    std::map<int, std::vector<int>> preMap;

    for (auto& pair : prerequisites)
    {
        int course = pair[0];
        int prereq = pair[1];
        preMap[course].push_back(prereq);
    }    

    std::set<int> visited;

    for (int course = 0; course < numCourses; ++course)
    {
        if (!canComplete(course, preMap, visited)) return false;
    }

    return true;
}