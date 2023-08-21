// 11 - Container With Most Water (LeetCode Exercise)

// General idea is to use two pointers. One at the very left and one at the very right. This is
// because we want to maximize the area. At each iteration we calculate the area and replace it
// if it's larger. We then shift the pointer with the smallest height up/down and repeat til they
// meet

// Time Complexity: O(n) - We perform n iterations of constant work
// Space Complexity: O(1) - We only have three integers no matter the input size

#include <vector>
#include <algorithm>

int getArea(int l, int r, std::vector<int>& height)
{
    return std::min(height[l], height[r]) * std::abs(l-r);
}

int maxArea(std::vector<int>& height) 
{
    int currentMaxArea = 0;

    int l = 0;
    int r = height.size() - 1;

    while (l < r)
    {
        currentMaxArea = std::max(currentMaxArea, getArea(l, r, height));

        /* Move the current lowest height to the next height */
        /* l moves right, r moves left */
        if (height[l] < height[r])
        {
            l++;
        }    
        else
        {
            r--;
        }
    }

    return currentMaxArea;
}