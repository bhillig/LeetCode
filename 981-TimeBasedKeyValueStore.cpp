// 981 - Time Based Key-Value Store (LeetCode Exercise)

// Set Time Complexity: O(1)
// Get Time Complexity: O(log(n))

// Space Complexity: O(n)

#include <vector>
#include <map>
#include <string>

class TimeMap 
{
public:
    TimeMap() 
    {
        timeMap = {};
    }
    
    void set(std::string key, std::string value, int timestamp) 
    {
        if (timeMap.find(key) == timeMap.end())
        {
            timeMap[key] = {};
        }
        timeMap[key].push_back({value, timestamp});
    }
    
    std::string get(const std::string& key, int timestamp) 
    {
        std::string res = "";
        if (timeMap.find(key) == timeMap.end()) return res;

        int l = 0;
        int r = timeMap[key].size() - 1;

        int m = 0;
        while (l <= r)
        {
            m = l + (r-l)/2;

            int currTime = timeMap[key][m].second;

            if (currTime == timestamp)
            {
                return timeMap[key][m].first;
                
            }
            else if (currTime < timestamp)
            {
                res = timeMap[key][m].first;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return res;
    }
    std::map<std::string, std::vector<std::pair<std::string, int>>> timeMap;
};