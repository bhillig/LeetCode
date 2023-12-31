// 62 - Unique Paths (LeetCode Exercise)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <vector>

int uniquePaths(int m, int n) 
{
    std::vector<std::vector<int>> steps(m+1, std::vector<int>(n+1, 0));

    for (int r = m - 1; r >= 0; --r)
    {
        for (int c = n - 1; c >= 0; --c)
        {
            // Base case: Target destination
            if (r == m - 1 && c == n - 1) steps[r][c] = 1;
            // Otherwise calculate paths given bottom and right adjacent squares
            else steps[r][c] = steps[r+1][c] + steps[r][c+1];
        }
    }

    return steps[0][0];
}