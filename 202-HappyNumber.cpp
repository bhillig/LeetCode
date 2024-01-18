// 202 - Happy Number (LeetCode Exercise)

// Time Complexity: O(1) 
// Space Complexity: O(n) (Could be optimized if used a two pointer cycle check instead of a set)

#include <set>

int sumOfSquares(int number)
{
    int res = 0;

    while (number)
    {
        int digit = number % 10;
        digit *= digit;
        res += digit;
        number /= 10;
    }

    return res;
}

bool isHappy(int n) 
{
    std::set<int> visited = {};

    while (visited.find(n) == visited.end())
    {
        visited.emplace(n);
        n = sumOfSquares(n);

        if (n == 1) return true;
    }    

    return false;
}