// 143 - ReorderList (LeetCode Exercise)

// General idea is to notice the pattern of flipping between the start of the list and the end
// We can find the middle of the linked list by using two pointers and moving one at double the speed of the other
// When the fast pointer reaches the end we know the slow pointer is at the middle, we then can reverse the second half
// Which allows us to easily merge the two lists into one

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

void reorderList(ListNode* head) 
{
    // Split the list in two
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* previous = nullptr;

    // Reverse the second half
    while(second)
    {
        ListNode* temp = second->next;
        second->next = previous;
        previous = second;
        second = temp;
    }

    // Merge the two halves
    ListNode* one = head;
    ListNode* two = previous;

    while(two)
    {
        ListNode* temp1 = one->next;
        ListNode* temp2 = two->next;

        one->next = two;
        two->next = temp1;
        one = temp1;
        two = temp2;
    }

    return;
}