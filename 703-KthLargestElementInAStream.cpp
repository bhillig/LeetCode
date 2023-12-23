// 703 - Kth Largest Element in a Stream (LeetCode Exercise)

// Time Complexity for Constructor: O(nlog(n))
// Time Complexity for Adding: O(log(k))

// Space Complexity: O(n)

#include <vector>
#include <queue>

class KthLargest 
{
public:
    KthLargest(int inK, std::vector<int>& nums) 
    {
        k = inK;

        for (int num : nums)
        {
            minHeap.push(num);
        }

        while (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    
    int add(int val) 
    {
        minHeap.push(val);
        
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }

        return minHeap.top();
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;
};