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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        return pre(root,res);
    }
    
    vector<int> pre(TreeNode *root,vector<int> &res)
    {
        if(!root) return res;
        res.push_back(root->val);
        pre(root->left,res);
        pre(root->right,res);
        return res;
    }
};