// 739 - Daily Temperatures (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) 
{
    std::vector<int> res(temperatures.size(), 0);

    std::stack<int> stack;

    for (int i = 0; i < temperatures.size(); ++i)
    {
        while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
        {
            int stackIndex = stack.top();
            stack.pop();
            res[stackIndex] = i - stackIndex;
        }

        stack.push(i);
    }

    return res;
}