// 695 - Max Area of Island (LeetCode Exercise)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <vector>
#include <queue>

typedef std::array<int, 2> Cord;

int getArea(int row, int col, std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited)
{
    int area = 0;

    std::queue<Cord> q;
    q.push({row, col});
    visited[row][col] = true;

    std::vector<std::vector<int>> directions {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        Cord node = q.front();
        q.pop();

        area += 1;

        int r = node[0];
        int c = node[1];
        
        for (std::vector<int>& dir : directions)
        {
            int newR = r + dir[0];
            int newC = c + dir[1];

            if (newR < 0 || newR >= grid.size()) continue;
            if (newC < 0 || newC >= grid[0].size()) continue;
            if (visited[newR][newC]) continue;
            if (grid[newR][newC] != 1) continue;

            visited[newR][newC] = true;
            q.push({newR, newC});
        }
    }
    return area;
}
int maxAreaOfIsland(std::vector<std::vector<int>>& grid) 
{
    if (grid.empty()) return 0;

    int maxArea = 0;

    const int ROWS = grid.size();
    const int COLS = grid[0].size();    

    std::vector<std::vector<bool>> visited(ROWS);
    for (auto& vec : visited)
        vec.resize(COLS);

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (grid[r][c] == 1 && !visited[r][c])
            {
                maxArea = std::max(maxArea, getArea(r, c, grid, visited));
            }
        }
    }

    return maxArea;
}