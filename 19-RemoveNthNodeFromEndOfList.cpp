// 19 - Remove Nth Node From End Of List (LeetCode Exercise)

// General idea is to first calculate the length of the list then use this to determine the node to remove in relation to the head not the tail
// We then move two pointers (prev and current) til we arrive at the desired node to remove and remove it. We use two pointers so we can have
// the previous node point to what the removal node was previously pointing to. Base case is where we remove the head in which we return head->next

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <cstddef>

struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    int numberOfNodes = 0;
    ListNode* temp = head;    
    while(temp)
    {
        ++numberOfNodes;
        temp = temp->next;
    }

    int removeIndex = numberOfNodes - (n - 1);

    /* Base case where we remove the head and previous is nullptr */
    if (removeIndex == 1)
    {
        return head->next;
    }

    int currentIndex = 1;
    ListNode* previous = nullptr;
    ListNode* current = head;
    while(currentIndex != removeIndex)
    {
        ++currentIndex;
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    return head;
}