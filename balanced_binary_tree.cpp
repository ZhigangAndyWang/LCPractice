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
    bool isBalanced(TreeNode *root) {
        if (root==NULL) return true;
        int ldep,rdep,diff;
        
        if(root->left)
        {
            if(!isBalanced(root->left)) return false;
            ldep = root->left->val + 1;
        }
        else
            ldep = 0;
        if(root->right)
        {
            if(!isBalanced(root->right)) return false;
            rdep = root->right->val + 1;
        }
        else 
            rdep = 0;


        diff = ldep-rdep;
        if(abs(diff)>1) return false;
        
        root->val = max(ldep,rdep);
        return true;
    }

};