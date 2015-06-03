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
    ListNode *splitList(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
        return head2;
    }
    
    ListNode *reverseList(ListNode *head2){
        ListNode *prev = NULL;
        
        while(head2){
            ListNode *pnext = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = pnext;
        }
        return prev;
    }
    
    ListNode *alternatelyMergeTwoLists(ListNode *head1,ListNode *head2){
        ListNode *nHead = head1;
        while(head2){
            ListNode *cur = head1->next;
            head1->next = head2;
            head1 = head1->next;
            head2 = cur;
        }
        return nHead;
    }
    
    void reorderList(ListNode* head) {
        //split, reverse the second half, and merge
        if(!head || !head->next) return;
        ListNode *head2 = splitList(head);
        ListNode *reversedHead2 = reverseList(head2);
        ListNode *head1 = head;
        ListNode *nHead = alternatelyMergeTwoLists(head1,reversedHead2);
        return;
    }
};