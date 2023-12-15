// 417 - Pacific Atlantic Water Flow (LeetCode Exercise)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <vector>
#include <set>

void dfs(int r, int c, std::vector<std::vector<int>>& heights, std::set<std::vector<int>>& visited, int prevHeight)
{
    if (visited.find({r, c}) != visited.end()) return;
    if (r < 0 || r >= heights.size()) return;
    if (c < 0 || c >= heights[0].size()) return;

    if (heights[r][c] < prevHeight) return;

    visited.emplace(std::vector<int>{r, c});

    dfs(r + 1, c, heights, visited, heights[r][c]);
    dfs(r - 1, c, heights, visited, heights[r][c]);
    dfs(r, c + 1, heights, visited, heights[r][c]);
    dfs(r, c - 1, heights, visited, heights[r][c]);
}
std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) 
{
    const int ROWS = heights.size();
    const int COLS = heights[0].size();

    std::vector<std::vector<int>> res;

    std::set<std::vector<int>> pacific;
    std::set<std::vector<int>> atlantic;

    for (int r = 0; r < ROWS; ++r)
    {
        dfs(r, 0, heights, pacific, heights[r][0]);
        dfs(r, COLS - 1, heights, atlantic, heights[r][COLS - 1]);
    }

    for (int c = 0; c < COLS; ++c)
    {
        dfs(0, c, heights, pacific, heights[0][c]);
        dfs(ROWS - 1, c, heights, atlantic, heights[ROWS - 1][c]);
    }

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (pacific.find({r, c}) == pacific.end()) continue;
            if (atlantic.find({r, c}) == atlantic.end()) continue;

            res.push_back({r, c});
        }
    }

    return res;
}