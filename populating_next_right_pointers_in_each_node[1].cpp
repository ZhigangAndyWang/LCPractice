/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        TreeLinkNode *p = root;
        TreeLinkNode *first = root->left; //first node in next row;
        
        while(p){
            if(!first)
                first = p->left;
                
            if (p->left){
                p->left->next = p->right;
            }
            else{
                break;
            }
            
            if(p->next){
                p->right->next = p->next->left;
                p = p->next;
                continue;
            }
            
            if(!p->next){
                p = first;
                first = p->left;
            }
        }
    }
};