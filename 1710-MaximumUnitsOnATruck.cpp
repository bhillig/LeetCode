// 1710 - Maximum Units On A Truck (LeetCode Exercise)

// Time Complexity: O(n)
// Space Complexity: O(n)
#include <vector>
#include <array>

int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) 
{
    int amountTaken = 0;
    
    int MIN = INT_MAX;
    int MAX = INT_MIN;

    std::array<int, 1001> values = {};
    for (std::vector<int>& box : boxTypes)
    {
        MIN = std::min(MIN, box[1]);
        MAX = std::max(MAX, box[1]);
        values[box[1]] += box[0];
    }

    for (int i = MAX; i >= MIN; --i)
    {
        int boxSize = values[i];
        if (!boxSize) continue;

        int boxesTaken = std::min(boxSize, truckSize);
        amountTaken += i * boxesTaken;
        truckSize -= boxesTaken;
        if (!truckSize) break;
    }

    return amountTaken;
}