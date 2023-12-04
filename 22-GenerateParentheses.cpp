// 22 - Generate Parnetheses (LeetCode Exercise)

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)

#include <vector>
#include <string>
#include <stack>

void backtrack(int openN, int closedN, int n, std::stack<char>& stack, std::vector<std::string>& res)
{
    if (openN == n && closedN == n)
    {
        std::string validCombination;
        while (!stack.empty())
        {
            char c = stack.top();
            validCombination += c;
            stack.pop();
        }

        for (int i = validCombination.size() - 1; i > - 1; --i)
        {
            stack.push(validCombination[i]);
        }

        std::reverse(validCombination.begin(), validCombination.end());
        res.push_back(validCombination);
        return;
    }

    if (openN < n)
    {
        stack.push('(');
        backtrack(openN + 1, closedN, n, stack, res);
        stack.pop();
    }

    if (closedN < openN)
    {
        stack.push(')');
        backtrack(openN, closedN + 1, n, stack, res);
        stack.pop();
    }
}

std::vector<std::string> generateParenthesis(int n) 
{
    std::stack<char> stack;
    std::vector<std::string> res;
    backtrack(0, 0, n, stack, res);
    return res;
}