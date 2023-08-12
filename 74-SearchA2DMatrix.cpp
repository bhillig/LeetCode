// 74 - Search a 2D Matrix (LeetCode Exercise)

// Time Complexity: O(log(n * m)) - We perform binary search on a vector of size n * m (treat it like one big vector)
// Space Complexity: O(1) - Constant space no matter the input given

// General idea is to perform binary search on the 2D matrix treating it like one long vector
// We calculate the middleIndex like normal binary search, but this time we have to convert it to a row 
// and column index for lookup in the 2D matrix

#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
{
        const int ROW = matrix.size();
        const int COLUMN = matrix[0].size();

        int l = 0;
        int r = (ROW * COLUMN) - 1;

        while (l <= r)
        {
            int middleIndex = l + (r - l)/2;

            int row = middleIndex / COLUMN;
            int column = middleIndex % COLUMN;

            if (target > matrix[row][column])
            {
                l = middleIndex + 1;
            }
            else if (target < matrix[row][column])
            {
                r = middleIndex - 1;
            }
            else
            {
                return true;
            }
        }    

        return false;
}