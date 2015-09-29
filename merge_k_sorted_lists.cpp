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
    ListNode* mergeTwoLists(ListNode* head,ListNode* node){
        ListNode* start = new ListNode(INT_MIN);
        ListNode* cur = start;
        cur->next = head;
        ListNode* next = cur->next;
        while(node!= NULL){
            ListNode* nextNode = node->next;
            if(cur->val <= node->val && (!next || next->val > node->val)){//insert
                cur->next = node;
                node->next = next;
                cur = node;
                node = nextNode;
            }
            else{
                cur = next;
                next = cur->next;
            }
        }
        return start->next;
    }
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if(!l1)
    //         return l2;
    //     if(!l2)
    //         return l1;
    //     if(l1->val<l2->val)
    //         l1->next=mergeTwoLists(l1->next,l2);
    //     else
    //         l2->next=mergeTwoLists(l1,l2->next);
    // }
    
    //Divide and Conquer
    ListNode* dac(vector<ListNode*>& lists,int s, int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        if(s==e) return lists[s];
        
        ListNode* l1 = dac(lists,s,mid);
        ListNode* l2 = dac(lists,mid+1,e);
        
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n ==1) return lists[0];
        
        return dac(lists,0,n-1);
    }
};