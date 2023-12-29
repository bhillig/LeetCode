// 994 - Rotting Oranges (LeetCode Exercise)

// Time Complexity: O(n * m) since we loop through the grid twice
// Space Complexity: O(n* m) since in the worst case our queue could hold a bunch of 
// fresh oranges about to be rotten

#include <vector>
#include <queue>

int orangesRotting(std::vector<std::vector<int>>& grid) 
{
    if (grid.empty()) return -1;

    const int ROWS = grid.size();
    const int COLS = grid[0].size();

    std::queue<std::vector<int>> q;
    int freshOranges = 0;

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (grid[r][c] == 1)
            {
                ++freshOranges;
            }
            else if (grid[r][c] == 2)
            {
                q.push({r, c});
            }
        }
    }

    int minutes = 0;
    std::vector<std::vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (freshOranges > 0 && !q.empty())
    {
        int queueSize = q.size();

        for (int i = 0; i < queueSize; ++i)
        {
            std::vector<int> node = q.front();
            q.pop();

            int r = node[0];
            int c = node[1];

            for (auto& dir : directions)
            {
                int newR = r + dir[0];
                int newC = c + dir[1];

                if (newR < 0 || newR >= ROWS) continue;
                if (newC < 0 || newC >= COLS) continue;

                if (grid[newR][newC] == 1)
                {
                    grid[newR][newC] = 2;
                    q.push({newR, newC});
                    freshOranges -= 1;
                }
            }
        }
        minutes += 1;
    }

    if (freshOranges == 0) return minutes;
    else return -1;
}