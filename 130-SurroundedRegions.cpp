// 130 - Surrounded Regions (LeetCode Exercise)

// Time Complexity: O(n * m)
// Space Complexity: O(1)

#include <vector>

void capture(int row, int col, std::vector<std::vector<char>>& board)
{
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
    if (board[row][col] != 'O') return;

    board[row][col] = 'T';

    capture(row + 1, col, board);
    capture(row - 1, col, board);
    capture(row, col + 1, board);
    capture(row, col - 1, board);
}

void solve(std::vector<std::vector<char>>& board) 
{
    if (board.empty()) return;

    const int ROWS = board.size();
    const int COLS = board[0].size();    

    for (int r = 0; r < ROWS; ++r)
    {
        if (board[r][0] == 'O')
        {
            capture(r, 0, board);
        }
        if (board[r][COLS-1] == 'O')
        {
            capture(r, COLS - 1, board);
        }
    }

    for (int c = 0; c < COLS; ++c)
    {
        if (board[0][c] == 'O')
        {
            capture(0, c, board);
        }
        if (board[ROWS-1][c] == 'O')
        {
            capture(ROWS-1, c, board);
        }
    }

    for (int r = 0; r < ROWS; ++r)
    {
        for (int c = 0; c < COLS; ++c)
        {
            if (board[r][c] == 'O')
            {
                board[r][c] = 'X';
            }
            else if (board[r][c] == 'T')
            {
                board[r][c] = 'O';
            }
        }
    }
}