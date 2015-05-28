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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        if (head == NULL) return head;
        
        ListNode *prv = NULL; 
        ListNode *nxt = head->next;
        
        while(nxt!=NULL){
            ListNode *tmp = nxt->next;
            head->next = prv;
            nxt->next = head;
            
            prv = head;;
            head = nxt;
            nxt = tmp;
        }
        return head;
    }
};