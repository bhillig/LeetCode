// 155 - Min Stack (LeetCode Exercise)

// Designs a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <stack>

class MinStack 
{
public:

    MinStack() 
    {
        
    }

    void push(int val) 
    {
        values.push(val);

        if (minStack.empty())
        {
            minStack.push(val);
            return;
        }

        int minValue = val < minStack.top() ? val : minStack.top();
        minStack.push(minValue);
    }

    void pop() 
    {
        values.pop();
        minStack.pop();
    }

    int top() 
    {
        return values.top();
    }

    int getMin() 
    {
        return minStack.top();
    }

private:
    std::stack<int> values;
    std::stack<int> minStack;
};
