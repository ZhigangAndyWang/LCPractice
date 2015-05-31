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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *end = head;
        ListNode *cnt = head;
        int count = 0;
        
        if(!head) return head;
        
        while(cnt){
            count++;
            cnt = cnt->next;
        }
        
        k = k%count;
        
        if(k==0) return head;
        
        for(int i=0;i<k-1;i++){
            end = end->next;
        }
        
        while(end->next){
            start = start->next;
            end = end->next;
        }
        
        if(head == start->next)
            return head;
        
        end->next = head;
        head = start->next;
        start->next = NULL;
        
        return head;
    }
};


/*
A more concise solution by circling it first

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};*/