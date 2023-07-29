// 509 - Fibonacci Number (LeetCode Exercise)

// Time Complexity: O(n) - Linearly iterate from 1 to n doing constant work
// Space Complexity: O(n) - Our int array is size n where n is the number given

// Utilizing DP we can acheive a runtime of O(n) by building an array of past solutions
// This approach is much more efficent than recursion which has a time complexity of O(n^2)

int fib(int n) 
{
    if (n < 2) return n;

    int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;

    for(int i = 2; i <= n; ++i)
    {
        memo[i] = memo[i-1] + memo[i-2];
    }

    return memo[n];
}