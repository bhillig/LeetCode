// 20 - Valid Parentheses (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>

bool isValid(string s) 
{
    std::stack<char> stack;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
            continue;
        }

        if (stack.empty()) return false;

        int recent = stack.top();

        if (recent == '(' && c == ')') stack.pop();
        else if (recent == '{' && c == '}') stack.pop();
        else if (recent == '[' && c == ']') stack.pop();
        else return false;
    }    

    return stack.empty();
}