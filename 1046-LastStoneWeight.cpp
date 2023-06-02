#include <vector>
#include <queue>

// Main idea is to create a priority queue from the vector given
// While we atleast have two stones:
//  Pop both of them off and 'subtract' durability of the larger stone
//  by adding the durability of the largestStone - largeStone
// If by the end our queue is empty, return 0, else return the durabiliy of the last stone

// Time Complexity: O(n)
// Space Complexity: O(n)

int lastStoneWeight(std::vector<int> stones)
{
    std::priority_queue<int> pq(stones.begin(), stones.end());

    while(pq.size() > 1)
    {
        int largestStone = pq.top();
        pq.pop();

        int largeStone = pq.top();
        pq.pop();

        if (largestStone != largeStone)
        {
            pq.push(largestStone - largeStone);
        }
    }

    if(pq.empty()) return 0;

    return pq.top();
}