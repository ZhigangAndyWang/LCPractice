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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curNode = head->next;
        ListNode *lastSorted = head;
        
        while(curNode){
            ListNode *search = head;
            ListNode *aheadSearch = NULL;
            ListNode *nextNode = curNode->next;
            while(aheadSearch!=curNode){
                if(search==curNode){
                    lastSorted = curNode;
                    break;
                }
                else if(curNode->val <= search->val){
                    //insertion
                    if(search==head){
                        curNode->next = head;
                        head = curNode;
                        lastSorted->next = nextNode;
                        break;
                    }
                    else{
                        aheadSearch->next = curNode;
                        curNode->next = search;
                        lastSorted->next = nextNode;
                        break;
                    }
                    //reconstruct
                }
                aheadSearch = search;
                search = search->next;
            }
            
            curNode = nextNode;
        }
        return head;
    }
};