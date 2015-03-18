/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            //circle exists, x_f = l +n*c +t, x_s = l+t, fast = 2*slow ==> l = nc-t = k*c + c-t
            if(slow == fast)
            {
                while(slow!=entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        } 
        return NULL;
    }
};