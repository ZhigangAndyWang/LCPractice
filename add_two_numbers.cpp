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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int curSum = 0;
        ListNode *head = l2;
        ListNode *prevL2 = NULL;
        while( l1 || l2 || carry){
            if(l1 && l2){
                curSum = l1->val + l2->val + carry;
                carry = curSum / 10;
                curSum = curSum % 10;
                l2->val = curSum;
            }
            else if(!l1 && l2){
                curSum = l2->val + carry;
                carry = curSum / 10;
                curSum = curSum % 10;
                l2->val = curSum;
            }
            else if(!l2 && l1){   //l2 is NULL
                curSum = l1->val + carry;
                carry = curSum / 10;
                curSum = curSum % 10;
                //append l2
                prevL2->next = new ListNode(curSum);
            }
            else{   //l1 is NULL, l2 is NULL, carry = 1
                prevL2->next = new ListNode(1);
                carry = 0;
            }
            
            prevL2 = (l2)? l2 : prevL2->next;
            l1 = (l1)? l1->next : l1;
            l2 = (l2)? l2->next : l2;
        }
        return head;
    }
};