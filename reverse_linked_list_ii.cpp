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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 0;
        if(!head) return head;
        ListNode *start = new ListNode(0);
        start->next = head;
        
        ListNode *cur = start;
        ListNode *prev = NULL;
        ListNode *pre,*post;
        while(cur){
            if(i==m-1) pre = cur;
            if(i==n+1) post = cur;
            if(i<m) {
                i++;
                cur = cur->next;
                continue;
            }
            else if (i>n) break;
            else{
                //i>=M && i<=N
                ListNode *pnext = cur->next;
                cur->next = prev;
                prev = cur;
                cur = pnext;
                i++;
            }
        }
        
        pre->next->next = cur;
        pre->next = prev;
        return start->next;
    }
};