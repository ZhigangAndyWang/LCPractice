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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *tailA = headA;
        ListNode *tailB = headB;
        int la=0,lb=0;
        
        while(tailA != NULL)
        {
            tailA = tailA->next;
            la++;
        }
        while(tailB != NULL)
        {
            tailB = tailB->next;
            lb++;
        }
        
        tailA = headA;
        tailB = headB;
        
        if(la>lb)
        {
            for(int i=0;i<la-lb;i++) 
            {
                tailA = tailA->next;
            }
        }
        
        if(la<lb)
        {
            for(int i=0;i<lb-la;i++) 
            {
                tailB = tailB->next;
            }
        }
        
        while(tailA!=tailB && tailA!=NULL)
        {
            tailA = tailA->next;
            tailB = tailB->next;
        }
        return tailA;
    }
};