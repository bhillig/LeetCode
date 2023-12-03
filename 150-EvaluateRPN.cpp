// 150 - Evaluate RPN (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>
#include <vector>
#include <string>

bool isOperator(const std::string& s)
{
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int evalRPN(std::vector<std::string>& tokens) 
{
    std::stack<int> stack;

    for (const std::string& token : tokens)
    {
        // If it's a number, add it to the stack
        if (!isOperator(token))
        {
            stack.push(std::stoi(token));
            continue;
        }
        
        int num2 = stack.top();
        stack.pop();
        int num1 = stack.top();
        stack.pop();

        // If it's an operand, pop the two top elements and
        if (token == "+")
        {
            stack.push(num1 + num2);
        }
        else if (token == "-")
        {
            stack.push(num1 - num2);
        }
        else if (token == "/")
        {
            stack.push(num1 / num2);
        }
        else if (token == "*")
        {
            stack.push(num1 * num2);
        }            
    }    

    return stack.top();
}