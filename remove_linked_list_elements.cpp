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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *prev = start;
        ListNode *post;
        while(head){
            post = head->next;
            if(head->val == val){
                prev->next = post;
            }
            else{
                prev = prev->next;
            }
            head = head->next;
        }
        return start->next;
    }
};