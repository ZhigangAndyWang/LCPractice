/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root->left && !root->right) return root;
        if(p==q) return p;
        
        TreeNode *lca = root;
        int pv = p->val;
        int qv = q->val;
        while( (lca->val-pv)*(lca->val-qv) > 0){
            if(lca->val > pv) 
                lca = lca->left;
            else 
                lca = lca->right;
        }
        return lca;
    }
};