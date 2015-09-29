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
    int findMaxPathSum(TreeNode *root, int& maxSum){
        //meet the leaf's child
        if(!root) return 0;
        
        int ps1_left = 0, ps1_right = 0;
        if(root->left){
            ps1_left = max(0,findMaxPathSum(root->left,maxSum));
        }
        if(root->right){
            ps1_right = max(0,findMaxPathSum(root->right,maxSum));
        }
        int ps2_root = ps1_left + ps1_right + root->val;
        maxSum = max(ps2_root,maxSum);
        
        int ps1_root = root->val + max(ps1_left,ps1_right);
        
        return ps1_root;
        
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ps1_root = findMaxPathSum(root, maxSum);
        return maxSum;
    }
};