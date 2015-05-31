/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* mergeList(ListNode *l1,ListNode *l2){
        ListNode *start = new ListNode(0);  //ListNode start(0);
        ListNode *startPos = start;
        
        while(l1 || l2){
            if(!l1){
                start->next = l2;
                break;
            }
            else if(!l2){
                start->next = l1;
                break;
            }
            else{
                if(l1->val < l2->val){
                    start->next = l1;
                    l1 = l1->next;
                }
                else{
                    start->next = l2;
                    l2 = l2->next;
                }
            }
            start = start->next;
        }
        return startPos->next;
    }
    
    ListNode* getMid(ListNode* head, ListNode* tail) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }    
    
    //given head and tail, use merge sort to sort the whole list
    ListNode* mergeSortList(ListNode *head, ListNode *tail){
        if(head == tail) return head;
        
        ListNode *mid = getMid(head,tail);
        ListNode *sortedPost = mergeSortList(mid->next,tail);
        mid->next = NULL;   //***Null first
        ListNode *sortedPre = mergeSortList(head,mid);
        
        return mergeList(sortedPre,sortedPost);
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode *tail = head;
        
        while(tail->next){
            tail = tail->next;
        }
        return mergeSortList(head,tail);
    }
};