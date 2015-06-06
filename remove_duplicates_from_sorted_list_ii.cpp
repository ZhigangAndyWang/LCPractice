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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *prev = result;
        
        while(head){
            if(!head->next || head->val != head->next->val){
                prev = head;
            }
            else{
                while(head->next && head->val == head->next->val){
                    head = head->next;
                }
                prev->next = head->next;
            }
            head = head->next;
        }
        return result->next;
    }
};