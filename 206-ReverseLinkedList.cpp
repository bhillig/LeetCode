// 206 - ReverseLinkedList (LeetCode Exercise)

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(n) - We iterate over the linked list once
// Space Complexity: O(1) - No matter the input size we always have three address variables

ListNode* reverseList(ListNode* head)
{
    // General idea here is to have two pointers: a previous pointer and a current pointer
    // While we have a current pointer:
    //      Make it's next variable point to previous and update the pointers
    // At the end we return previous as it will now point to the new head of the list 

    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current)
    {
        // THE SWAP:
        // current->next points to previous
        // current points to current->next
        // previous points to current
        ListNode* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    return previous;
}