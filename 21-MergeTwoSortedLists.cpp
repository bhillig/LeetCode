// 21 - MergeTwoSortedLists (LeetCode Exercise)

// Time Complexity: O(n + m) where n is the size of list1 and m is the size of list2
// Space Complexity: O(1)

struct ListNode {
int val;
ListNode* next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode* head = new ListNode();
    ListNode* tail = head;

    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if(list1)
    {
        tail->next = list1;
    }
    if(list2)
    {
        tail->next = list2;
    }

    return head->next;
}