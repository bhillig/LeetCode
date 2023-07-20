// 141 - Linked List Cycle (LeetCode Exercise)

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
bool hasCycle(ListNode *head) 
{
        ListNode* one = head;
        ListNode* two = head;

        while(one && two)
        {
            one = one->next;
            ListNode* temp = two->next;
            if(temp)
            {
                temp = temp->next;
            }
            else
            {
                break;
            }
            two = temp;
            if (one == two) return true;
        }

        return false;
    }