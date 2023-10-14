// 287 - Find The Duplicate Number (LeetCode Exercise)

// General idea here is to use Floyd's Algorithm of a fast and slow pointer but using the elements of
// our vector as pointers to different elements. Once slow and fast intersect, we know the distance between
// the start and the intersection so moving a newly created slow pointer and our original slow pointer will
// guarantee a collision at the start of our cycle

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

int findDuplicate(std::vector<int>& nums) 
{
    int slow = 0;
    int fast = 0;
    while(true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast)
        {
            break;
        }
    }

    int slow2 = 0;
    while(true)
    {
        slow = nums[slow];
        slow2 = nums[slow2];

        if (slow == slow2)
        {
            return slow;
        }
    }
    
    return -1;
}