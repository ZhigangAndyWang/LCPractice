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
    ListNode *swapPairs(ListNode *head) {
        if(!head||!head->next) return head;
        
        ListNode start(0);
        start.next = head;
        ListNode *cur = head;
        ListNode *tail = &start;
        
        while(cur&&cur->next)
        {
            ListNode *temp = cur->next;
            if(!temp) break;
            cur->next = temp->next;
            temp->next = cur;
            
            tail->next = temp;
            tail = cur;
            cur = cur->next;
        }
        
        return start.next;
        
    }
};