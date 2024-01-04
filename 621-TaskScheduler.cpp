// 621 - Task Scheduler (LeetCode Exercise)

// Time Complexity: O(n * m) where n is the number of tasks in our input and m is the cooldown duration
// Space Complexity: O(n)

#include <map>
#include <vector>
#include <queue>
#include <deque>

int leastInterval(vector<char>& tasks, int n) 
{
    std::deque<std::vector<int>> q;
    std::priority_queue<int> maxHeap;

    std::map<char, int> counter;
    for (char task : tasks)
    {
        counter[task] += 1;
    }

    for (auto& [task, count] : counter)
    {
        maxHeap.push(count);
    }

    int time = 0;

    while (!q.empty() || !maxHeap.empty())
    {
        time += 1;

        if (!maxHeap.empty())
        {
            int taskCount = maxHeap.top() - 1;
            maxHeap.pop();
            if (taskCount > 0)
            {
                q.push_back({taskCount, n + time});
            }
        }
        if (!q.empty() && q.front()[1] == time)
        {
            maxHeap.push(q.front()[0]);
            q.pop_front();
        }
    }   

    return time; 
}