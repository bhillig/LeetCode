// 36 - Valid Sudoku (LeetCode Exercise)

// The idea behind this algorithm is to ensure that each row, column and square is unique
// through sets.

// In order to go through each row and column once in a nested loop, we use a map to map us
// from a row/column index to a set for those values.

// Determing each square is tricky and requires taking the x and y coord and dividing by 3 to
// obtain its square index.

// Time Complexity: O(n^2) or O(9^2) as Sudoku size is constant
// Space Complexity: O(n^2) as we have n^2 maps created 

#include <vector>
#include <map>
#include <set>

bool isValidSudoku(std::vector<std::vector<char>>& board) 
{
    typedef std::array<int, 2> Cords;

    std::map<int, std::set<char>> row;
    std::map<int, std::set<char>> col;
    std::map<Cords, std::set<char>> square;

    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if (board[i][j] == '.') continue;

            if (row[i].find(board[i][j]) != row[i].end()) return false;
            if (col[j].find(board[i][j]) != col[j].end()) return false;

            Cords cord = {i/3, j/3};
            if (square[cord].find(board[i][j]) != square[cord].end()) return false;

            row[i].emplace(board[i][j]);
            col[j].emplace(board[i][j]);
            square[cord].emplace(board[i][j]);
        }
    }

    return true;
}