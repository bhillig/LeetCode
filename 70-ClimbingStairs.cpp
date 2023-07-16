/* 
70 - Climbing Stairs (LeetCode Exercise)

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Time Complexity: O(n) - We iterate through a loop linearly up until n, constant amount of work is done each time
Space Complexity: O(n) - For an input of n, we create an int array of size n+1. We take the bigger term so O(n).
*/

#include <cstddef>

int climbStairs(int n) 
{
        
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int maximumWays[n+1];

    maximumWays[0] = 0;
    maximumWays[1] = 1;
    maximumWays[2] = 2;

    for (size_t i = 3; i <= n; ++i)
    {
        maximumWays[i] = maximumWays[i-1] + maximumWays[i-2];
    }

    return maximumWays[n];
}