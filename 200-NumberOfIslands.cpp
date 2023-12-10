// 200 - Number of Islands (LeetCode Exercise)

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <vector>
#include <deque>

typedef std::array<int, 2> Cord;

std::vector<std::vector<int>> directions = {{1,0}, {-1,0}, {0, 1}, {0, -1}};

void bfs(int row, int col, std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& grid)
{
    std::deque<Cord> q;
    q.push_back({row, col});
    visited[row][col] = true;

    while (!q.empty())
    {
        Cord cord = q.front();
        q.pop_front();

        int r = cord[0];
        int c = cord[1];

        for (auto& dir : directions)
        {
            int newR = r + dir[0];
            int newC = c + dir[1];

            if (newR < 0 || newR >= grid.size()) continue;
            if (newC < 0 || newC >= grid[0].size()) continue;
            if (visited[newR][newC]) continue;
            if (grid[newR][newC] != '1') continue;

            q.push_back({newR, newC});
            visited[newR][newC] = true;
        }
    }

}

int numIslands(std::vector<std::vector<char>>& grid) 
{
    int islands = 0;    

    if (grid.empty()) return islands;

    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<bool>> visited(rows);

    for (auto& vec : visited)
        vec.resize(cols);

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (grid[r][c] == '1' && !visited[r][c])
            {
                bfs(r, c, visited, grid);
                islands += 1;
            }
        }
    }

    return islands;
}