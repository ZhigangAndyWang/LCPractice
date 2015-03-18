/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *list;
    TreeNode *sortedListToBST(ListNode *head) 
    {
        list = head;
        int size = count(head);
        TreeNode *root = generate(size);
        return root;
    }
    
    int count(ListNode *head)
    {
        int c = 0;
        while(head!=NULL)
        {
            head = head->next;
            c++;
        }
        return c;
    }
    
    TreeNode *generate(int n)
    {
        if(n == 0) return NULL;
        TreeNode *node = new TreeNode(0);
        node->left = generate(n/2);
        node->val = list->val;
        list = list->next;
        node->right = generate(n-n/2-1);
        return node;
    }
};