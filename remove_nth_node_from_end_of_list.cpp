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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *start = head;
        ListNode *nafter = head;
        for(int i=0;i<n;i++)
        {
            nafter = nafter->next;
        }
        
        if(!nafter) return head->next;
        
        while(nafter->next)
        {
            start = start->next;
            nafter = nafter->next;
        }
        
        start->next = start->next->next;
        return head;
        
    }
};